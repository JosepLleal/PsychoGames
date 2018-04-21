#include "Application.h"
#include "Enemy_Anemone.h"
#include "ModuleCollision.h"
#include "Globals.h"
#include "ModuleParticles.h"


Enemy_Anemone::Enemy_Anemone(int x, int y) : Enemy(x, y)
{
	Width = 56;
	Height = 43;

	static_movement.PushBack({ 0, 162, Width, Height });
	static_movement.PushBack({ 56, 162, Width, Height });
	static_movement.PushBack({ 112, 162, Width, Height });
	static_movement.speed = 0.05f;
	animation = &static_movement;

	collider = App->collision->AddCollider({0, 0, Width, Height }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;
}
