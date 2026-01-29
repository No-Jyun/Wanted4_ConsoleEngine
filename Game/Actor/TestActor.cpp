#include "TestActor.h"
#include "Core/Input.h"
#include "Engine/Engine.h"
#include <Windows.h>
#include <iostream>

using namespace Wanted;

TestActor::TestActor()
	: super('T', Vector2(10, 5))
{

}

void TestActor::BeginPlay()
{
	// 상위 함수 호출
	// C++ 부모함수 가리키는 포인터가 없음
	Actor::BeginPlay();

	//std::cout << "TestActor::BeginPlay()\n";
}

void TestActor::Tick(float deltaTime)
{
	Actor::Tick(deltaTime);

	// Q키 종료
	if (Wanted::Input::Get().GetKeyDown('Q'))
	{
		// Todo: 게임 엔진 종료 요청
		Wanted::Engine::Get().QuitEngine();
	}
	
	// 이동
	//if (Input::Get().GetKey('D'))
	if (Input::Get().GetKey(VK_RIGHT) && GetPosition().x < 20)	// 방향키
	{
		Vector2 newPosition = GetPosition();
		newPosition.x += 1;
		SetPosition(newPosition);
	}

	if (Input::Get().GetKey(VK_LEFT) && GetPosition().x > 0)	// 방향키
	{
		Vector2 newPosition = GetPosition();
		newPosition.x -= 1;
		SetPosition(newPosition);
	}

	if (Input::Get().GetKey(VK_DOWN) && GetPosition().y < 20)	// 방향키
	{
		Vector2 newPosition = GetPosition();
		newPosition.y += 1;
		SetPosition(newPosition);
	}

	if (Input::Get().GetKey(VK_UP) && GetPosition().y > 0)	// 방향키
	{
		Vector2 newPosition = GetPosition();
		newPosition.y -= 1;
		SetPosition(newPosition);
	}

	//std::cout 
	//	<< "TestActor::Tick(). deltaTime: " << deltaTime
	//	<< ", FPS: " << (1.0f) / deltaTime << "\n";
}

void TestActor::Draw()
{
	Actor::Draw();
}
