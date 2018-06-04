#include "Application.h"
#include "PowerUp_SpeedUp.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleAudio.h"
#include "ModulePowerUp.h"

PowerUp_SpeedUp::PowerUp_SpeedUp(int x, int y) : PowerUp(x, y)
{


	fly.PushBack({ 163, 133, 24, 15 });

	fly.speed = 0.0f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 24, 13 }, COLLIDER_TYPE::COLLIDER_POWERUP, (Module*)App->powerup);

	original_y = y;
}

void PowerUp_SpeedUp::Move()
{

	position.x -= 0.7f;


}


void PowerUp_SpeedUp::OnCollision(Collider* collider)
{
	App->player->Speedup = true;
	App->player->speedup_anim = true;
	App->audio->ChunkPlay(App->powerup->SpeedUp);
	
}