#ifndef __ENEMY_RED_BALL_H__
#define __ENEMY_RED_BALL_H__

#include "Enemy.h"

class Enemy_Red_Ball : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	Animation fly;


public:

	iPoint original_position;
	Path* path = new Path();
	Enemy_Red_Ball(int x, int y);

};

#endif // __ENEMY_NEMONA_H__
