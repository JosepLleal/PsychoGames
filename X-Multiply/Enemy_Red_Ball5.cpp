#include "Application.h"
#include "Globals.h"
#include "Enemy_Red_Ball5.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "SDL/include/SDL_timer.h"

Enemy_Red_Ball5::Enemy_Red_Ball5(int x, int y) : Enemy(x, y)
{

	animation = &one;
	one.speed = 0.0f;

	life = 5;

	original_position.y = y;

	collider = App->collision->AddCollider({ 0, 0, 27, 29 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	one.PushBack({ 28, 274, 27, 29 });


}

void Enemy_Red_Ball5::OnCollision(Collider* collider_)
{

	if (life == 5)
	{
		animation = &two;
		two.PushBack({ 60, 277, 27, 26 });
		two.speed = 0.0f;

		position.x += 1;
		position.y += 1;

		collider->rect.h = 26;
		collider->rect.w = 27;
	}

	else if (life == 4)
	{
		animation = &three;
		three.PushBack({ 94, 280, 22, 24 });
		three.speed = 0.0f;

		position.x += 3;
		position.y += 4;

		collider->rect.h = 24;
		collider->rect.w = 22;
	}
	else if (life == 3)
	{
		animation = &four;
		four.PushBack({ 127, 279, 19, 19 });
		four.speed = 0.0f;

		position.x += 3;
		position.y += 3;

		collider->rect.h = 19;
		collider->rect.w = 19;
	}
	else if (life == 2)
	{
		animation = &five;
		five.PushBack({ 160, 154, 15, 13 });
		five.speed = 0.0f;

		position.x += 3;
		position.y += 3;

		collider->rect.h = 13;
		collider->rect.w = 15;
	}

	
}