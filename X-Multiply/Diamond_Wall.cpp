#include "Application.h"
#include "Diamond_Wall.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"


Diamond_Wall::Diamond_Wall(int x, int y) : Enemy(x, y)
{
	Width = 17;
	Height = 80;

	idle.PushBack({ 23, 15, Width, Height });

	animation = &idle;

	original_y = y;

	collider = App->collision->AddCollider({ 0, 0, Width, Height }, COLLIDER_TYPE::COLLIDER_DIAMOND, (Module*)App->enemies);

	life = 5000;

}

void Diamond_Wall::Move()
{

	if (touching == false)
	{
		position.y += 1;
	}

}


void Diamond_Wall::OnCollision(Collider* collider)
{
	if (collider->type == COLLIDER_WALL || collider->type == COLLIDER_REDBALL)
	{
		touching = true;
	}
	
}