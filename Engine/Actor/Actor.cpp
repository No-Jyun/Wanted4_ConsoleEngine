#include "Actor.h"
#include <iostream>
#include <Windows.h>

namespace Wanted
{
	Actor::Actor(
		const char image, const Vector2& position)
		: image(image), position(position)
	{

	}

	Actor::~Actor()
	{

	}

	void Actor::BeginPlay()
	{
		// 이벤트를 받은 후에는 플래그 설정
		hasBeganPlay = true;
	}

	void Actor::Tick(float deltaTime)
	{

	}

	void Actor::Draw()
	{
		// 액터의 현재 좌표로 콘솔 좌표 위치 이동
		COORD coord = {};
		
		// coord의 x와 y 값은 short 자료형이므로 형변환을 해야함
		// 기본형끼리의 형변환이므로 static cast 사용
		coord.X = static_cast<short>(position.x);
		coord.Y = static_cast<short>(position.y);
		
		// 윈도우에선 기본적으로 출력용, 입력용, 에러용 콘솔 3개를 가짐
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

		// 이동한 좌표에서 글자 그리기
		std::cout << image;
	}

	void Actor::SetPosition(const Vector2& newPosition)
	{
		// 액터의 좌표로 콘솔 좌표 위치 이동
		COORD coord = {};
		coord.X = static_cast<short>(position.x);
		coord.Y = static_cast<short>(position.y);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

		// 해당 위치의 글자 값 지우기 (빈칸 그리기)
		std::cout << ' ';

		// 새로운 위치 설정
		position = newPosition;
	}
}
