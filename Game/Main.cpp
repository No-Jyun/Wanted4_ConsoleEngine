#include <iostream>
#include "Engine/Engine.h"
#include "Level/TestLevel.h"
#include "Actor/TestActor.h"

using namespace Wanted;

int main()
{
	//Wanted::Engine engine;
	//engine.SetNewLevel(new TestLevel());
	//engine.Run();

	TestLevel* level = new TestLevel();
	Actor* actor = new Actor();
	TestActor* testActor = new TestActor();

	if (testActor->Is(actor))
	{
		std::cout << "Testactor is Actor type\n";
	}
	else
	{
		std::cout << "Testactor is not Actor type\n";
	}

	// 아래와 같은 일을함
	TestActor* testActor2 = dynamic_cast<TestActor*>(actor);
	TestActor* testActor = actor->As<TestActor>();
	if (testActor)
	{
		std::cout << "actor is TestActor type\n";
	}
	else
	{
		std::cout << "actor is not TestActor type\n";
	}
}