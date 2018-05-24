#include "Application.h"
#include "Globals.h"
#include "Enemy_Red_Ball3.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "SDL/include/SDL_timer.h"
#include "ModuleAudio.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"

Enemy_Red_Ball3::Enemy_Red_Ball3(int x, int y) : Enemy(x, y)
{

	animation = &one;
	one.speed = 0.0f;

	life = 5;

	original_position.y = y;

	collider = App->collision->AddCollider({ 0, 0, 31, 32 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	one.PushBack({ 24, 208, 31, 32 });


}

void Enemy_Red_Ball3::OnCollision(Collider* collider_)
{
	App->audio->ChunkPlay(App->enemies->redball);

	if (life == 5)
	{
		animation = &two;
		two.PushBack({ 56, 208, 27, 32 });
		two.speed = 0.0f;

		

		collider->rect.h = 32;
		collider->rect.w = 27;
	}

	else if (life == 4)
	{
		animation = &three;
		three.PushBack({ 93, 214, 22, 26 });
		three.speed = 0.0f;

		
		collider->rect.h = 26;
		collider->rect.w = 22;
	}
	else if (life == 3)
	{
		animation = &four;
		four.PushBack({ 126, 214, 19, 21 });
		four.speed = 0.0f;

		

		collider->rect.h = 21;
		collider->rect.w = 19;
	}
	else if (life == 2)
	{
		animation = &five;
		five.PushBack({ 160, 154, 15, 13 });
		five.speed = 0.0f;

		

		collider->rect.h = 13;
		collider->rect.w = 15;
	}
	else if (life == 1)
	{
		App->player->score += 100;
	}


	

}