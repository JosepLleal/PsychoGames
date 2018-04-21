#ifndef __ENEMY_ANEMONE_H__
#define __ENEMY_ANEMONE_H__

#include "Enemy.h"

class Enemy_Anemone : public Enemy
{
private:

	iPoint original_pos;
	Animation static_movement;

public:

	Enemy_Anemone(int x, int y);

	// Enemy Hitbox
	int Width;
	int Height;

	void Move();
};

#endif // __ENEMY_ANEMONE_H__