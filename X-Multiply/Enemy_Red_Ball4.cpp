#include "Application.h"
#include "Globals.h"
#include "Enemy_Red_Ball4.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "SDL/include/SDL_timer.h"

Enemy_Red_Ball4::Enemy_Red_Ball4(int x, int y) : Enemy(x, y)
{

	animation = &one;
	one.speed = 0.0f;

	life = 5;

	original_position.y = y;

	collider = App->collision->AddCollider({ 0, 0, 32, 29 }, COLLIDER_TYPE::COLLIDER_REDBALL, (Module*)App->enemies);

	one.PushBack({ 23, 242, 32, 29 });


}

void Enemy_Red_Ball4::OnCollision(Collider* collider_)
{

	if (life == 5)
	{
		animation = &two;
		two.PushBack({ 56, 245, 31, 22 });
		two.speed = 0.0f;

		position.x += 1;
		position.y += 1;

		collider->rect.h = 22;
		collider->rect.w = 31;
	}

	else if (life == 4)
	{
		animation = &three;
		three.PushBack({ 91, 248, 26, 18 });
		three.speed = 0.0f;

		position.x += 3;
		position.y += 4;

		collider->rect.h = 18;
		collider->rect.w = 26;
	}
	else if (life == 3)
	{
		animation = &four;
		four.PushBack({ 125, 250, 21, 13 });
		four.speed = 0.0f;

		position.x += 3;
		position.y += 3;

		collider->rect.h = 13;
		collider->rect.w = 21;
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