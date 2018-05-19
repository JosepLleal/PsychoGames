#include "Application.h"
#include "Enemy_YellowBall2.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "SDL/include/SDL_timer.h"

Enemy_YellowBall2::Enemy_YellowBall2(int x, int y) : Enemy(x, y)
{
	life = 1;

	inflate.PushBack({ 184, 400, 24, 30 });
	inflate.PushBack({ 214, 400, 25, 35 });
	inflate.PushBack({ 246, 400, 30, 38 });
	inflate.PushBack({ 279, 400, 29, 38 });
	inflate.PushBack({ 183, 352, 29, 38 });

	inflate.PushBack({ 215, 352, 24, 16 });
	inflate.PushBack({ 215, 352, 24, 16 });
	inflate.PushBack({ 215, 352, 24, 16 });
	inflate.PushBack({ 215, 352, 24, 16 });
	inflate.PushBack({ 215, 352, 24, 16 });
	

	inflate.PushBack({ 246, 352, 24, 23 });
	inflate.PushBack({ 278, 352, 24, 28 });


	inflate.speed = 0.1f;
	animation = &inflate;

	collider = App->collision->AddCollider({ 0, 0, 29, 38 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_position.x = x;
	original_position.y = y;
}

void Enemy_YellowBall2::Move()
{
	if (App->render->camera.x % 136 == 0)
	{
		App->particles->AddParticle(App->particles->anemona_shotud1, original_position.x + 14, original_position.y + 15, COLLIDER_ENEMY_SHOT);
		App->particles->AddParticle(App->particles->anemona_shotud2, original_position.x + 14, original_position.y + 5, COLLIDER_ENEMY_SHOT);
		App->particles->AddParticle(App->particles->anemona_shotud3, original_position.x + 14, original_position.y , COLLIDER_ENEMY_SHOT);
		
	}
}
void Enemy_YellowBall2::OnCollision(Collider* collider)
{
	App->particles->AddParticle(App->particles->explosion_enemy, position.x, position.y);
}

