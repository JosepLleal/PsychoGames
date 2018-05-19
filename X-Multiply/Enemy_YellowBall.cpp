#include "Application.h"
#include "Enemy_YellowBall.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "SDL/include/SDL_timer.h"

Enemy_YellowBall::Enemy_YellowBall(int x, int y) : Enemy(x, y)
{
	life = 1;

	inflate.PushBack({ 34, 351, 29, 38 });
	inflate.PushBack({ 66, 351, 29, 38 });
	inflate.PushBack({ 101, 350, 29, 38 });
	inflate.PushBack({ 133, 350, 29, 38 });

	inflate.PushBack({ 34, 397, 29, 38 });
	inflate.PushBack({ 66, 400, 29, 38 });
	inflate.PushBack({ 66, 400, 29, 38 });
	inflate.PushBack({ 66, 400, 29, 38 });
	inflate.PushBack({ 66, 400, 29, 38 });
	inflate.PushBack({ 66, 400, 29, 38 });

	inflate.PushBack({ 98, 399, 29, 38 });
	inflate.PushBack({ 130, 399, 29, 38 });


	inflate.speed = 0.1f;
	animation = &inflate;

	collider = App->collision->AddCollider({ 0, 0, 29, 38 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_position.x = x;
	original_position.y = y;
}

void Enemy_YellowBall::Move()
{
	if (App->render->camera.x % 136 == 0)
	{
		App->particles->AddParticle(App->particles->anemona_shot1, original_position.x + 17, original_position.y + 15, COLLIDER_ENEMY_SHOT);
		App->particles->AddParticle(App->particles->anemona_shot2, original_position.x + 17, original_position.y + 5, COLLIDER_ENEMY_SHOT);
		App->particles->AddParticle(App->particles->anemona_shot3, original_position.x + 17, original_position.y + 0, COLLIDER_ENEMY_SHOT);
		
	}
}
void Enemy_YellowBall::OnCollision(Collider* collider)
{
	App->particles->AddParticle(App->particles->explosion_enemy, position.x, position.y);
}

