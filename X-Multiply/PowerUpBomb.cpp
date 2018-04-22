#include "Application.h"
#include "PowerUpBomb.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"


PowerUp_Bomb::PowerUp_Bomb(int x, int y) : PowerUp(x, y)
{


	fly.PushBack({ 69, 75, 24, 13 });

	fly.speed = 0.0f;

	animation = &fly;

	original_y = y;
}

void PowerUp_Bomb::Move()
{

}


void PowerUp_Bomb::OnCollision(Collider* collider)
{
	if (collider->type == COLLIDER_PLAYER)
	{
		App->player->score += 1000;
	}
}