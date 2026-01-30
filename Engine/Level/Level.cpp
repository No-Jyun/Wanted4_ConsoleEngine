#include "Level.h"
#include "Actor/Actor.h"

namespace Wanted
{
	Level::Level()
	{

	}

	Level::~Level()
	{
		// 메모리 정리
		for (Actor*& actor : actors)
		{			
			if (actor)
			{
				delete actor;
				actor = nullptr;
			}
		}

		// 배열 초기화
		actors.clear();
	}

	void Level::BeginPlay()
	{
		// 액터에 이벤트 흘리기
		for (Actor* actor : actors)
		{
			// 이미 BeginPlay 호출된 액터는 건너뛰기
			if (actor->HasBeganPlay())
			{
				continue;
			}

			actor->BeginPlay();
		}
	}

	void Level::Tick(float deltaTime)
	{
		// 액터에 이벤트 흘리기
		for (Actor* actor : actors)
		{
			actor->Tick(deltaTime);
		}
	}

	void Level::Draw()
	{
		// 액터에 이벤트 흘리기
		for (Actor* actor : actors)
		{
			actor->Draw();
		}
	}

	void Level::AddNewActor(Actor* newActor)
	{
		// 나중에 프레임 처리 고려해서 따로 추가 작업 해야함
		// push 류는 L-value 레퍼런스를 받음 (L-value 레퍼런스은 복사를 안함
		//actors.push_back(newActor);
		
		// emplace 류는 R-value 레퍼런스를 고려함 (R-value 레퍼런스로 받으면 복사를 안해도 되면 안함)
		// 성능이 더 나을 수 있음. 그러나 현대의 c++은 크게 상관이 없음
		// L-value가 들어와도 알아서 처리함
		//actors.emplace_back(newActor);
		addRequestedActors.emplace_back(newActor);
	}

	void Level::ProcessAddAndDestroyActor()
	{
		// 제거 처리		제거 로직에서 벡터를 erase 하므로 ix++하면 안됨
		for (int ix = 0; ix < static_cast<int>(actors.size());)
		{
			// 제거 요청된 액터가 있는지 확인
			if (actors[ix]->DestroyRequested())
			{
				// 삭제 처리
				delete actors[ix];
				actors.erase(actors.begin() + ix);
				continue;
			}
			ix++;
		}

		// 추가 처리
		if (addRequestedActors.size() == 0)
		{
			return;
		}

		for (Actor* const actor : addRequestedActors)
		{
			actors.emplace_back(actor);
		}

		// 처리가 끝났으면 배열 초기화
		addRequestedActors.clear();
	}
}