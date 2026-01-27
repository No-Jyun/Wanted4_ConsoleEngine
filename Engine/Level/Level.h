#pragma once
// dll에서 템플릿을 사용할때 발생하는 오류 코드 C4251
// dll에선 원칙적으로 사용하면 안됨. 그러나 답이 없음
#pragma warning(disable: 4251)	// 미봉책 (유니티, 언리얼 다 사용함)

// STL(Standard Template Library - C++ 기본 제공)
// 크기가 알아서 변경되는 배열
#include <vector>
#include "Common/Common.h"

namespace Wanted
{
	// 전방 선언
	class Actor;

	// 담당 임무 : 레벨에 있는 모든 액터(물체) 관리
	class WANTED_API Level
	{
	public:
		Level();
		virtual ~Level();

		// 게임 플레이 이벤트
		virtual void BeginPlay();
		virtual void Tick(float deltaTime);
		virtual void Draw();

		// 액터 추가 함수
		void AddNewActor(Actor* newActor);

	protected:
		// 액터 배열
		std::vector<Actor*> actors;
	};
}
