#include "Application.h"
#include "Enemy_redball.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"

Enemy_RedBall::Enemy_Big_Eye(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 11,10,70,68 });

	fly.PushBack({ 88,10,70,68 });

	fly.PushBack({ 165,10,70,68 });


	fly.PushBack({ 11,160,70,68 });



	fly.PushBack({ 11,77,70,68 });

	fly.PushBack({ 88,77,70,68 });



	fly.PushBack({ 165,77,70,68 });
	fly.PushBack({ 11,10,70,68 });


	fly.speed = 0.065f;

	animation = &fly;

	path->PushBack({ 0 , 0 }, 2, &fly);

	collider = App->collision->AddCollider({ 13, 10, 70, 68 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_position.x = x;
	original_position.y = y;
}