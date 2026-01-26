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
		// Todo: 나중에 프레임 처리 고려해서 따로 추가 작업 해야함
		// push 류는 L-value 레퍼런스를 받음 (L-value 레퍼런스은 복사를 안함
		//actors.push_back(newActor);
		
		// emplace 류는 R-value 레퍼런스를 고려함 (R-value 레퍼런스로 받으면 복사를 안해도 되면 안함)
		// 성능이 더 나을 수 있음. 그러나 현대의 c++은 크게 상관이 없음
		// L-value가 들어와도 알아서 처리함
		actors.emplace_back(newActor);	
	}
}