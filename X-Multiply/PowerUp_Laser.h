#ifndef __POWERUPLASER_H__
#define __POWERUPLASER_H__

#include "PowerUp.h"

class PowerUp_Laser : public PowerUp
{
private:

	int original_y = 0;
	Animation box_b;

public:

	PowerUp_Laser(int x, int y);
	iPoint original_position;

	void Move();
	void PowerUp_Laser::OnCollision(Collider* collider);
};

#endif 
