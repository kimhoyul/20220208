#include "Goal.h"

Goal::Goal()
{
	X = 0;
	Y = 0;
	Shape = 'G';
}

Goal::Goal(int NewX, int NewY)
{
	X = NewX;
	Y = NewY;
	Shape = 'G';
}

Goal::~Goal()
{
}
