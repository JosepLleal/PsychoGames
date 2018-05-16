#ifndef __ENEMY_RED_BALL4_H__
#define __ENEMY_RED_BALL4_H__

#include "Enemy.h"

class Enemy_Red_Ball4 : public Enemy
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
	Enemy_Red_Ball4(int x, int y);
	void Enemy_Red_Ball4::OnCollision(Collider* collider);
};

#endif // __ENEMY_NEMONA_H__

