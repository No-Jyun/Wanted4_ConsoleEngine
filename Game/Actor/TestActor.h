#pragma once

#include "Actor/Actor.h"

class TestActor : public Wanted::Actor
{
	RTTI_DECLARATIONS(TestActor, Actor)

//public:
protected:	// 물려받아서 구현하는 쪽은 protected도 가능
				// 다형성 때문에 virtual을 사용한다.
				// 이미 Actor을 통해서 mapping이 이루졌기때문에
	virtual void BeginPlay() override;
	virtual void Tick(float deltaTime) override;
	virtual void Draw() override;
};

