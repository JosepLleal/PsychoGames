#include "Application.h"
#include "Globals.h"
#include "Enemy_Red_Ball1.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "SDL/include/SDL_timer.h"
#include "ModuleAudio.h"
#include "ModuleEnemies.h"

Enemy_Red_Ball1::Enemy_Red_Ball1(int x, int y) : Enemy(x, y)
{

	animation = &one;
	one.speed = 0.0f;

	life = 5;

	original_position.y = y;

	collider = App->collision->AddCollider({ 0, 0, 32, 32 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	one.PushBack({ 23, 144, 32, 32 });


}

void Enemy_Red_Ball1::OnCollision(Collider* collider_)
{
	App->audio->ChunkPlay(App->enemies->redball);

	if (life == 5)
	{
		animation = &two;
		two.PushBack({ 56, 147, 31, 28 });
		two.speed = 0.0f;

		position.x += 1;
		position.y += 1;

		collider->rect.h = 28;
		collider->rect.w = 31;
	}

	else if (life == 4)
	{
		animation = &three;
		three.PushBack({ 90, 147, 28, 27 });
		three.speed = 0.0f;

		position.x += 3;
		position.y += 3;

		collider->rect.h = 27;
		collider->rect.w = 28;
	}
	else if (life == 3)
	{
		animation = &four;
		four.PushBack({ 125, 151 ,21, 19 });
		four.speed = 0.0f;

		position.x += 3;
		position.y += 3;

		collider->rect.h = 19;
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