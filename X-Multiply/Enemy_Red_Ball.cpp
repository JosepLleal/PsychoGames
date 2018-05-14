#include "Application.h"
#include "Globals.h"
#include "Enemy_Red_Ball.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "SDL/include/SDL_timer.h"

Enemy_Red_Ball::Enemy_Red_Ball(int x, int y) : Enemy(x, y)
{

	animation = &fly; 

	original_position.x = x;
	original_position.y = y;

	if(life == 5)
	{
		collider = App->collision->AddCollider({ 0, 0, 30, 30 }, COLLIDER_TYPE::COLLIDER_REDBALL, (Module*)App->enemies);
		fly.PushBack({ 23, 112, 33, 32 });
	}

	else if (life == 4)
	{
		collider = App->collision->AddCollider({ 0, 0, 28, 28 }, COLLIDER_TYPE::COLLIDER_REDBALL, (Module*)App->enemies);
		fly.PushBack({ 56, 112, 33, 32 });
	}

	else if (life == 3)
	{
		collider = App->collision->AddCollider({ 0, 0, 25, 25 }, COLLIDER_TYPE::COLLIDER_REDBALL, (Module*)App->enemies);
		fly.PushBack({ 89, 144, 28, 26 });
	}
}

void Enemy_Red_Ball::OnCollision(Collider* collider)
{
	if (collider->type == COLLIDER_PLAYER_SHOT)
	{
		life = life - 1; 
	}
}