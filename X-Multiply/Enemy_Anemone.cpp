#include "Application.h"
#include "Enemy_Anemone.h"
#include "ModuleCollision.h"
#include "Globals.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"


Enemy_Anemone::Enemy_Anemone(int x, int y) : Enemy(x, y)
{
	Width = 48;
	Height = 43;

	static_movement.PushBack({ 0, 162, 48, Height });
	static_movement.PushBack({ 61, 162, 48, Height });
	static_movement.PushBack({ 121, 162, 48, Height });
	static_movement.speed = 0.05f;
	animation = &static_movement;

	collider = App->collision->AddCollider({0, 0, Width, Height }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;
}

void Enemy_Anemone::Move()
{
	if ( App->render->camera.x % 420 == 0)
	{
		App->particles->AddParticle(App->particles->anemona_shot1, original_pos.x + 24, original_pos.y + 25, COLLIDER_ENEMY_SHOT);
		App->particles->AddParticle(App->particles->anemona_shot2, original_pos.x + 24, original_pos.y + 15, COLLIDER_ENEMY_SHOT);
		App->particles->AddParticle(App->particles->anemona_shot3, original_pos.x + 24, original_pos.y + 10, COLLIDER_ENEMY_SHOT);
		App->particles->AddParticle(App->particles->anemona_shot4, original_pos.x + 24, original_pos.y + 20, COLLIDER_ENEMY_SHOT);
		App->particles->AddParticle(App->particles->anemona_shot5, original_pos.x + 24, original_pos.y + 25, COLLIDER_ENEMY_SHOT);
	}
}

void Enemy_Anemone::OnCollision(Collider* collider)
{
	if (collider->type == COLLIDER_PLAYER_SHOT)
	{
		App->player->score += 600;
		App->particles->AddParticle(App->particles->explosion_enemy, position.x, position.y);
	}
}
