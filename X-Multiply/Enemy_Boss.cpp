#include "Application.h"
#include "Enemy_Boss.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleEnemies.h"
#include "SDL/include/SDL_timer.h"
#include "ModuleFadeToBlack.h"
#include "ModulePlayer.h"

Enemy_Boss::Enemy_Boss(int x, int y) : Enemy(x, y)
{
	life = 140;

	collider = App->collision->AddCollider({ 0, 0, 50, 200 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);



	animation = &right_goup;

	left_goup.PushBack({ 6, 448, 170, 224 });
	left_goup.PushBack({ 188, 448, 198, 224 });
	left_goup.PushBack({ 393, 449, 194, 224 });
	left_goup.PushBack({ 632, 449, 184, 224 });
	left_goup.PushBack({ 851, 449, 170, 231 });
	left_goup.PushBack({ 5, 693, 170, 232 });
	left_goup.speed = 0.1f;
	left_goup.loop = false;
	

	left_shoot.PushBack({ 185, 692, 170, 232 });
	left_shoot.PushBack({ 367, 692, 170, 232 });
	left_shoot.PushBack({ 549, 692, 170, 232 });
	left_shoot.PushBack({ 732, 692, 170, 232 });
	left_shoot.speed = 0.1f;
	left_shoot.loop = false;
	

	left_godown.PushBack({ 5, 693, 170, 232 });
	left_godown.PushBack({ 851, 449, 170, 231 });
	left_godown.PushBack({ 632, 449, 184, 224 });
	left_godown.PushBack({ 393, 449, 194, 224 });
	left_godown.PushBack({ 188, 448, 198, 224 });
	left_godown.PushBack({ 6, 448, 170, 224 });
	left_godown.speed = 0.1f;
	left_godown.loop = false;

	////////////////////////////////////

	right_goup.PushBack({ 16, 949, 155, 202 });
	right_goup.PushBack({ 190, 949, 155, 202 });
	right_goup.PushBack({ 371, 949, 155, 202 });
	right_goup.PushBack({ 553, 949, 155, 202 });
	right_goup.PushBack({ 736, 949, 155, 202 });
	right_goup.PushBack({ 16, 1165, 155, 202 });
	right_goup.PushBack({ 190, 1165, 155, 202 });
	right_goup.speed = 0.1f;
	right_goup.loop = false;


	right_shoot.PushBack({ 370, 1165, 155, 202 });
	right_shoot.PushBack({ 554, 1165, 155, 202 });
	right_shoot.PushBack({ 735, 1170, 155, 202 });
	right_shoot.speed = 0.1f;
	right_shoot.loop = false;

	right_godown.PushBack({ 190, 1165, 155, 202 });
	right_godown.PushBack({ 16, 1165, 155, 202 });
	right_godown.PushBack({ 736, 949, 155, 202 });
	right_godown.PushBack({ 553, 949, 155, 202 });
	right_godown.PushBack({ 371, 949, 155, 202 });
	right_godown.PushBack({ 190, 949, 155, 202 });
	right_godown.PushBack({ 16, 949, 155, 202 });
	right_godown.speed = 0.1f;
	right_godown.loop = false;


	original_position.x = x;
	original_position.y = y;
}

void Enemy_Boss::Move()
{
	if (animation == &right_goup)
	{
		if (right_goup.Finished() == true) 
		{ 
			animation = &right_shoot; 
			right_goup.Reset();
			
		}
	}
	else if (animation == &right_shoot)
	{
		if(right_shoot.Finished() == true)
		{ 
			shooting_counter++;
			if (shooting_counter <= 7) { right_shoot.Reset();}
			else
			{
				shooting_counter = 0;
				animation = &right_godown;
			}
			 
		}
	}
	else if(animation == &right_godown)
	{
		if (right_godown.Finished() == true) 
		{ 
			animation = &left_goup; 
			position.x -= 190;
			right_godown.Reset();
		}
	}
	else if (animation == &left_goup)
	{
		
		if (left_goup.Finished() == true) 
		{ 
			animation = &left_shoot; 
			left_goup.Reset();
			
		}
	}
	else if (animation == &left_shoot)
	{
		if (left_shoot.Finished() == true)
		{
			shooting_counter++;
			if (shooting_counter <= 7) { left_shoot.Reset(); }
			else
			{
				shooting_counter = 0;
				animation = &left_godown;
			}

		}
	}
	else if (animation == &left_godown)
	{
		if (left_godown.Finished() == true)
		{
			animation = &right_goup;
			position.x += 190;
			left_godown.Reset();
		}
	}
}
void Enemy_Boss::OnCollision(Collider* collider)
{
	if (life == 1)
	{
		App->player->score += 500000;
		App->fade->FadeToBlack((Module*)App->lvl5, (Module*)App->stage_cleared, 1.0f);
	}

}
