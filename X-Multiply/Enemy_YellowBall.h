#ifndef __ENEMY_YELLOWBALL_H__
#define __ENEMY_YELLOWBALL_H__

#include "Enemy.h"

class Enemy_YellowBall : public Enemy
{
private:
	int original_y = 0;
	Animation inflate;


public:

	iPoint original_position;
	Enemy_YellowBall(int x, int y);

};

#endif // #define __ENEMY_YELLOWBALL_H__

