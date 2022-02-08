#pragma once
#include "Actor.h"

class Player : public Actor
{
public:
	Player();
	Player(int NewX, int NewY);
	virtual ~Player();
};

