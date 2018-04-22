#include "Application.h"
#include "Enemy_Ball.h"
#include "ModuleCollision.h"
#include "Globals.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"

Enemy_Ball::Enemy_Ball(int x, int y, bool up) : Enemy(x, y)
{
	Width = 24;
	Height = 27;

	fly.PushBack({ 0 , 110, Width, Height });
	fly.PushBack({ 32 , 110, Width, Height });
	fly.PushBack({ 64 , 110, Width, Height });
	fly.speed = 0.01f;
	animation = &fly;

	this->up = up;

	collider = App->collision->AddCollider({ 0, 0, Width, Height }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;
}

void Enemy_Ball::Move()
{
	angle += 0.08f;

	if (original_pos.x - 157 == position.x) {
		ret = true;
	}
	
	if (up)
		position.y = original_pos.y + sinf(angle) * 1.9f * 20;
	else
		position.y = original_pos.y + sinf(-angle) * 1.9f * 20;

	if (ret == false) {
		position.x -= 0.7f;
	}
	else {
		position.x += 3.7f;
	}

}

void Enemy_Ball::OnCollision(Collider* collider)
{
	if (collider->type == COLLIDER_PLAYER_SHOT)
	{
		App->player->score += 100;
		App->particles->AddParticle(App->particles->explosion_enemy, position.x, position.y);
	}
}
