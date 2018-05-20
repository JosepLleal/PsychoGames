#ifndef __ENEMY_DROP_H__
#define __ENEMY_DROP_H__

#include "Enemy.h"

class Enemy_Drop : public Enemy
{
private:
	
	int original_y = 0;
	Animation drop; 
	Animation drop2;
	Animation drop3;
	int counter = 0; 

public:

	iPoint original_position;
	Enemy_Drop(int x, int y);
	void Move();
	//void Enemy_Drop::OnCollision(Collider* collider);
};

#endif // __ENEMY_DROP_H__
