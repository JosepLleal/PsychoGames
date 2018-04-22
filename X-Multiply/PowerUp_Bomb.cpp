#include "Application.h"
#include "PowerUp_Bomb.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"


PowerUp_Bomb::PowerUp_Bomb(int x, int y) : PowerUp(x, y)
{
	box_b.PushBack({163, 133, 24, 15});
	box_b.speed = 0.0f;
	animation = &box_b;

	collider = App->collision->AddCollider({ 0, 0, 24, 14 }, COLLIDER_TYPE::COLLIDER_POWERUP, (Module*)App->powerup);

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