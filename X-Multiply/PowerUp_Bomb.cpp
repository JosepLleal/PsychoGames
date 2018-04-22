#include "Application.h"
#include "PowerUp_Bomb.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"


PowerUp_Bomb::PowerUp_Bomb(int x, int y) : PowerUp(x, y)
{
	bomb.PushBack({ 235, 106, 15, 15 });
	bomb.PushBack({ 253, 106, 15, 15 });
	bomb.PushBack({ 267, 106, 15, 15 });
	bomb.PushBack({ 286, 106, 15, 15 });
	bomb.PushBack({ 302, 106, 15, 15 });
	bomb.speed = 0.1f;
	bomb.loop = false;

	bomb.speed = 0.5f;

	animation = &bomb;

	original_y = y;
}

void PowerUp_Bomb::Move()
{
	position.x -= 0.7f;
}


void PowerUp_Bomb::OnCollision(Collider* collider)
{
	if (collider->type == COLLIDER_PLAYER)
	{
		App->player->Bomb = true;
	}
}