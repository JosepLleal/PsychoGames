#include "Application.h"
#include "Diamond_Wall2.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"


Diamond_Wall2::Diamond_Wall2(int x, int y) : Enemy(x, y)
{
	Width = 16;
	Height = 64;

	idle.PushBack({ 55, 14, Width, Height });

	animation = &idle;

	original_y = y;

	collider = App->collision->AddCollider({ 0, 0, Width, Height }, COLLIDER_TYPE::COLLIDER_DIAMOND, (Module*)App->enemies);

	life = 5000;

}

void Diamond_Wall2::Move()
{

	if (touching == false)
	{
		position.y += 2;
	}

}


void Diamond_Wall2::OnCollision(Collider* collider)
{
	if (collider->type == COLLIDER_WALL || collider->type == COLLIDER_ENEMY)
	{
		touching = true;
	}
	else if (collider->type != COLLIDER_ENEMY && collider->type == COLLIDER_NONE)
	{
		touching = false;
	}

}