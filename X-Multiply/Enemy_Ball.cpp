#include "Application.h"
#include "Enemy_Ball.h"
#include "ModuleCollision.h"
#include "Globals.h"

Enemy_Ball::Enemy_Ball(int x, int y) : Enemy(x, y)
{
	Width = 24;
	Height = 27;

	fly.PushBack({ 0 , 110, Width, Height});
	fly.PushBack({ 31 , 110, Width, Height });
	fly.PushBack({ 62 , 110, Width, Height });
	fly.speed = 0.2f;
	animation = &fly;

	/*path.PushBack({-1.0f, -0.5f}, 100);
	path.PushBack({-1.0f, 0.5f}, 80);
	path.PushBack({-1.0f, 1.0f}, 80);*/

	collider = App->collision->AddCollider({0, 0, Width, Height }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;
}

void Enemy_Ball::Move()
{
	position = original_pos + path.GetCurrentSpeed();
}
