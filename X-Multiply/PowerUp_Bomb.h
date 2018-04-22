#ifndef __POWERUPBOMB_H__
#define __POWERUPBOMB_H__

#include "PowerUp.h"

class PowerUp_Bomb : public PowerUp
{
private:

	int original_y = 0;
	Animation box_b;

public:

	PowerUp_Bomb(int x, int y);
	iPoint original_position;

	void Move();
	void PowerUp_Bomb::OnCollision(Collider* collider);
};

#endif 
