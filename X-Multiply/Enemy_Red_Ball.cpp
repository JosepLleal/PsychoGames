#include "Application.h"
#include "Enemy_Red_Ball.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "SDL/include/SDL_timer.h"

Enemy_Red_Ball::Enemy_Red_Ball(int x, int y) : Enemy(x, y)
{
	animation = &fly;

	path->PushBack({ 0 , 0 }, 2, &fly);

	collider = App->collision->AddCollider({ 0, 0, 48, 48 }, COLLIDER_TYPE::COLLIDER_REDBALL, (Module*)App->enemies);

	original_position.x = x;
	original_position.y = y;
}
