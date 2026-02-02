#pragma once

#include "Actor/Actor.h"

using namespace Wanted;

class Player : public Actor
{
	RTTI_DECLARATIONS(Player, Actor)

public:
	Player(const Vector2& position);

//public:
protected:	// 물려받아서 구현하는 쪽은 protected도 가능
				// 다형성 때문에 virtual을 사용한다.
				// 이미 Actor을 통해서 mapping이 이루졌기때문에
	virtual void BeginPlay() override;
	virtual void Tick(float deltaTime) override;
	virtual void Draw() override;
};

