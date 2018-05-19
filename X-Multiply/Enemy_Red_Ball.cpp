#include "Application.h"
#include "Globals.h"
#include "Enemy_Red_Ball.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "SDL/include/SDL_timer.h"

Enemy_Red_Ball::Enemy_Red_Ball(int x, int y) : Enemy(x, y)
{

	animation = &one; 
	one.speed = 0.0f;

	life = 5;

	original_position.y = y;

	collider = App->collision->AddCollider({ 0, 0, 32, 32 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	one.PushBack({ 23, 112, 32, 32 });
	

}

void Enemy_Red_Ball::OnCollision(Collider* collider_)
{

	if (life == 5)
	{
		animation = &two;
		two.PushBack({ 55, 113, 31, 31 });
		two.speed = 0.0f;

		position.x += 1;
		position.y += 1;

		collider->rect.h = 31;
		collider->rect.w = 31;
	}

	else if (life == 4)
	{
		animation = &three;
		three.PushBack({ 90, 116, 26, 24 });
		three.speed = 0.0f;

		position.x += 3;
		position.y += 4;

		collider->rect.h = 24;
		collider->rect.w = 26;
	}
	else if (life == 3)
	{
		animation = &four;
		four.PushBack({ 125, 119, 21, 19 });
		four.speed = 0.0f;

		position.x += 3;
		position.y += 3;

		collider->rect.h = 19;
		collider->rect.w = 21;
	}
	else if (life == 2)
	{
		animation = &five;
		five.PushBack({ 160, 123, 15, 13 });
		five.speed = 0.0f;

		position.x += 3;
		position.y += 3;

		collider->rect.h = 13;
		collider->rect.w = 15;
	}

	
	
}