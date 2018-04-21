#include "Application.h"
#include "PowerUp_SpeedUp.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"


PowerUp_SpeedUp::PowerUp_SpeedUp(int x, int y) : PowerUp(x, y)
{


	fly.PushBack({ 69, 75, 24, 13 });
	
	fly.speed = 0.0f;

	animation = &fly;

	collider = App->collision->AddCollider({ 22, 20, 24, 13 }, COLLIDER_TYPE::COLLIDER_POWERUP, (Module*)App->powerup);

	original_y = y;
}

void PowerUp_SpeedUp::Move()
{

	position.x -= 0.7f;


}


void PowerUp_SpeedUp::OnCollision(Collider* collider)
{
	if (collider->type == COLLIDER_PLAYER)
	{
		App->player->score += 1000;
	}
}