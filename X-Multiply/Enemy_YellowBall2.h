#ifndef __ENEMY_YELLOWBALL2_H__
#define __ENEMY_YELLOWBALL2_H__

#include "Enemy.h"

class Enemy_YellowBall2 : public Enemy
{
private:
	int original_y = 0;
	Animation inflate;


public:

	iPoint original_position;
	Enemy_YellowBall2(int x, int y);

	void Move();
	void Enemy_YellowBall2::OnCollision(Collider* collider);


};

#endif // #define __ENEMY_YELLOWBALL2_H__
