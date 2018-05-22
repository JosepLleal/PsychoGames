#ifndef __DIAMOND_WALL_H__
#define __DIAMOND_WALL_H__

#include "Enemy.h"

class Diamond_Wall : public Enemy
{
private:

	bool touching = false;
	int original_y = 0;
	Animation idle;

	int counter = 0;

public:

	Diamond_Wall(int x, int y);
	iPoint original_position;

	// Enemy Hitbox
	int Width;
	int Height;

	void Move();
	void Diamond_Wall::OnCollision(Collider* collider);


};

#endif 

