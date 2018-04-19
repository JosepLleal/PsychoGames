#include "Application.h"
#include "Enemy_Anemone.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"


Enemy_Anemone::Enemy_Anemone(int x, int y) : Enemy(x, y)
{
	Width = 56;
	Height = 43;

	static_movement.PushBack({ 0, 0, Width, Height });
	static_movement.PushBack({ 0, 56, Width, Height });
	static_movement.PushBack({ 0, 112, Width, Height });

	static_movement.speed = 0.5f;

	animation = &static_movement;

	collider = App->collision->AddCollider({ NULL, NULL, Width, Height }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
}