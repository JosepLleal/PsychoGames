#include "Application.h"
#include "PowerUp_Enemy.h"
#include "ModulePowerUp.h"
#include "ModuleCollision.h"
#include "ModuleAudio.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"


PowerUp_Enemy::PowerUp_Enemy(int x, int y) : PowerUp(x, y)
{
	

	fly.PushBack({ 161, 63, 28, 19 }); 
	fly.PushBack({ 193, 62, 31, 20 });
	

	fly.speed = 0.2f;

	animation = &fly;

	collider = App->collision->AddCollider({ 22, 20, 29, 19 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->powerup);

	original_y = y;
}

void PowerUp_Enemy::Move()
{
	
	position.x -= 0.7f;


}


void PowerUp_Enemy::OnCollision(Collider* collider)
{
	if (collider->type == COLLIDER_PLAYER_SHOT)
	{
		App->player->score += 1000;
		App->particles->AddParticle(App->particles->explosion_enemy, position.x, position.y);
		App->audio->ChunkPlay(App->powerup->powerup_killed);
	}
}