#include "Application.h"
#include "PowerUp_Laser.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModulePowerUp.h"
#include "ModuleAudio.h"


PowerUp_Laser::PowerUp_Laser(int x, int y) : PowerUp(x, y)
{
	box_b.PushBack({ 5, 117, 18, 15 });
	box_b.speed = 0.3f;
	animation = &box_b;

	collider = App->collision->AddCollider({ 0, 0, 18, 15 }, COLLIDER_TYPE::COLLIDER_POWERUP, (Module*)App->powerup);

	original_y = y;
}

void PowerUp_Laser::Move()
{
	position.x -= 0.7f;
}


void PowerUp_Laser::OnCollision(Collider* collider)
{
	if (collider->type == COLLIDER_PLAYER)
	{
		App->player->Laser = true; 
		App->audio->ChunkPlay(App->powerup->Laser);
	}
}