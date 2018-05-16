#ifndef __ENEMY_RED_BALL3_H__
#define __ENEMY_RED_BALL3_H__

#include "Enemy.h"

class Enemy_Red_Ball3 : public Enemy
{
private:
	int original_y = 0;
	Animation one;
	Animation two;
	Animation three;
	Animation four;
	Animation five;


public:

	iPoint original_position;
	Enemy_Red_Ball3(int x, int y);
	void Enemy_Red_Ball3::OnCollision(Collider* collider);
};

#endif //__ENEMY_RED_BALL3_H__

