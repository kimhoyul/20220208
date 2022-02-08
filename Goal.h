#pragma once
#include "Actor.h"

class Goal : public Actor
{
public:
	Goal();
	Goal(int NewX, int NewY);
	virtual ~Goal();
};

