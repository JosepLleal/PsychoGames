#ifndef __ENEMY_ANEMONE_H__
#define __ENEMY_ANEMONE_H__

#include "Enemy.h"

class Enemy_Anemone: public Enemy
{
private:

	int original_y = 0;
	Animation static_movement;

public:

	Enemy_Anemone(int x, int y);
	iPoint original_position;

	// Enemy Hitbox
	int Width;
	int Height;

};

#endif // __ENEMY_EXAMPLE_H__
