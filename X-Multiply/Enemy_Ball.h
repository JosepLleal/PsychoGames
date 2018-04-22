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
	bool ret = false;
	bool up;

public:

	class Enemy_Ball(int x, int y, bool up);

	int Width;
	int Height;
	float angle = 0.0f;

	void Move();
	void Enemy_Ball::OnCollision(Collider* collider);
};

#endif // __ENEMY_BALL_H__