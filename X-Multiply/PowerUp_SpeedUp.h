#ifndef __POWERUP_SPEEDUP_H__
#define __POWERUP_SPEEDUP_H__

#include "PowerUp.h"

class PowerUp_SpeedUp : public PowerUp
{
private:

	int original_y = 0;
	Animation fly;

public:

	PowerUp_SpeedUp(int x, int y);
	iPoint original_position;


	void Move();
	void PowerUp_SpeedUp::OnCollision(Collider* collider);
};

#endif 


