#include "Application.h"
#include "Globals.h"
#include "Enemy_Red_Ball1.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "SDL/include/SDL_timer.h"

Enemy_Red_Ball1::Enemy_Red_Ball1(int x, int y) : Enemy(x, y)
{

	animation = &one;
	one.speed = 0.0f;

	life = 5;

	original_position.x = x;
	original_position.y = y;

	collider = App->collision->AddCollider({ 0, 0, 32, 32 }, COLLIDER_TYPE::COLLIDER_REDBALL, (Module*)App->enemies);

	one.PushBack({ 24, 146, 32, 32 });


}

void Enemy_Red_Ball1::OnCollision(Collider* collider_)
{

	if (life == 5)
	{
		animation = &two;
		two.PushBack({ 57, 148, 32, 28 });
		two.speed = 0.0f;

		position.x += 1;
		position.y += 1;

		collider->rect.h = 31;
		collider->rect.w = 31;
	}

	else if (life == 4)
	{
		animation = &three;
		three.PushBack({ 30, 148, 28, 27 });
		three.speed = 0.0f;

		position.x += 3;
		position.y += 4;

		collider->rect.h = 24;
		collider->rect.w = 26;
	}
	else if (life == 3)
	{
		animation = &four;
		four.PushBack({ 126, 152 ,21, 19 });
		four.speed = 0.0f;

		position.x += 3;
		position.y += 3;

		collider->rect.h = 19;
		collider->rect.w = 21;
	}
	else if (life == 2)
	{
		animation = &five;
		five.PushBack({ 161, 155, 15, 13 });
		five.speed = 0.0f;

		position.x += 3;
		position.y += 3;

		collider->rect.h = 13;
		collider->rect.w = 15;
	}

	if (life <= 0)
	{
		App->particles->AddParticle(App->particles->explosion_enemy, position.x, position.y);
	}

}