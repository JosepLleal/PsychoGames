#ifndef __POWERUP_ENEMY_H__
#define __POWERUP_ENEMY_H__

#include "PowerUp.h"

class PowerUp_Enemy : public PowerUp
{
private:
	
	int original_y = 0;
	Animation fly;

public:

	PowerUp_Enemy(int x, int y);
	iPoint original_position;

	void Move();
	void PowerUp_Enemy::OnCollision(Collider* collider);


};

#endif // __ENEMY_EXAMPLE_H__

