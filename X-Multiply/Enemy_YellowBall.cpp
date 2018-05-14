#include "Application.h"
#include "Enemy_YellowBall.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "SDL/include/SDL_timer.h"

Enemy_YellowBall::Enemy_YellowBall(int x, int y) : Enemy(x, y)
{
	inflate.PushBack({ 34, 351, 29, 38 });
	inflate.PushBack({ 66, 351, 29, 38 });
	inflate.PushBack({ 102, 351, 29, 38 });
	inflate.PushBack({ 134, 351, 29, 38 });
	inflate.speed = 0.03f;
	animation = &inflate;

	collider = App->collision->AddCollider({ 0, 0, 29, 38 }, COLLIDER_TYPE::COLLIDER_REDBALL, (Module*)App->enemies);

	original_position.x = x;
	original_position.y = y;
}
