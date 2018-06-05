#ifndef __ENEMY_BOSS_H__
#define __ENEMY_BOSS_H__

#include "Enemy.h"

class Enemy_Boss : public Enemy
{
private:
	int original_y = 0;
	
	Animation left_goup;
	Animation left_godown;
	Animation left_shoot;
	
	Animation right_goup;
	Animation right_godown;
	Animation right_shoot;
	int shooting_counter = 0;


public:

	iPoint original_position;
	Enemy_Boss(int x, int y);

	void Move();
	void Enemy_Boss::OnCollision(Collider* collider);


};

#endif // #define __ENEMY_BOSS_H__

