#include "Application.h"
#include "Globals.h"
#include "Enemy_Red_Ball2.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "SDL/include/SDL_timer.h"

Enemy_Red_Ball2::Enemy_Red_Ball2(int x, int y) : Enemy(x, y)
{

	animation = &one;
	one.speed = 0.0f;

	life = 5;

	

	collider = App->collision->AddCollider({ 0, 0, 32, 32 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	one.PushBack({ 24, 177, 32, 32 });

	original_position.y = y;

}

void Enemy_Red_Ball2::OnCollision(Collider* collider_)
{

	if (life == 5)
	{
		animation = &two;
		two.PushBack({ 56, 178, 31, 29 });
		two.speed = 0.0f;

		/*position.x += 1;
		position.y += 1;*/

		collider->rect.h = 29;
		collider->rect.w = 31;
	}

	else if (life == 4)
	{
		animation = &three;
		three.PushBack({ 91, 181, 24, 22 });
		three.speed = 0.0f;

		/*position.x += 3;
		position.y += 4;*/

		collider->rect.h = 22;
		collider->rect.w = 24;
	}
	else if (life == 3)
	{
		animation = &four;
		four.PushBack({ 125, 183, 21, 19 });
		four.speed = 0.0f;

		/*position.x += 3;
		position.y += 3;*/

		collider->rect.h = 19;
		collider->rect.w = 21;
	}
	else if (life == 2)
	{
		animation = &five;
		five.PushBack({ 160, 123, 15, 13 });
		five.speed = 0.0f;

		/*position.x += 3;
		position.y += 3;*/

		collider->rect.h = 13;
		collider->rect.w = 15;
	}

}