#ifndef __ENEMY_RED_BALL_H__
#define __ENEMY_RED_BALL_H__

#include "Enemy.h"

class Enemy_Red_Ball : public Enemy
{
private:
	int original_y = 0;
	Animation fly;


public:

	iPoint original_position;
	Enemy_Red_Ball(int x, int y);
	unsigned short life = 5;
	void Enemy_Red_Ball::OnCollision(Collider* collider);
};

#endif // __ENEMY_NEMONA_H__
