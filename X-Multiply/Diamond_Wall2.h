#ifndef __DIAMOND_WALL2_H__
#define __DIAMOND_WALL2_H__

#include "Enemy.h"

class Diamond_Wall2 : public Enemy
{
private:

	bool touching = false;
	int original_y = 0;
	Animation idle;

public:

	Diamond_Wall2(int x, int y);
	iPoint original_position;

	// Enemy Hitbox
	int Width;
	int Height;

	void Move();
	void Diamond_Wall2::OnCollision(Collider* collider);


};

#endif 
