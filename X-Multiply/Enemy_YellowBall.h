#ifndef __ENEMY_YELLOWBALL_H__
#define __ENEMY_YELLOWBALL_H__

#include "Enemy.h"

class Enemy_YellowBall : public Enemy
{
private:
	int original_y = 0;
	Animation inflate;
	int shooting_counter = 0;


public:

	iPoint original_position;
	Enemy_YellowBall(int x, int y);

	void Move();
	void Enemy_YellowBall::OnCollision(Collider* collider);


};

#endif // #define __ENEMY_YELLOWBALL_H__

