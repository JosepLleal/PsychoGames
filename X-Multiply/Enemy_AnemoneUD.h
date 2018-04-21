#ifndef __ENEMY_ANEMONEUD_H__
#define __ENEMY_ANEMONEUD_H__

#include "Enemy.h"

class Enemy_AnemoneUD : public Enemy
{
private:

	iPoint original_pos;
	Animation static_movement;

public:

	Enemy_AnemoneUD(int x, int y);

	// Enemy Hitbox
	int Width;
	int Height;

	void Move();
	void Enemy_AnemoneUD::OnCollision(Collider* collider);
};

#endif // __ENEMY_ANEMONEUD_H__
