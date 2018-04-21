#ifndef __ENEMY_BALL_H__
#define __ENEMY_BALL_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Ball : public Enemy
{
private:
	Path path;
	iPoint original_pos;
	Animation fly;

public:

	class Enemy_Ball(int x, int y);

	int Width;
	int Height;

	void Move();
	void Enemy_Ball::OnCollision(Collider* collider);
};

#endif // __ENEMY_BALL_H__