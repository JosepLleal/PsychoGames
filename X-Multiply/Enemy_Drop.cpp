#include "Application.h"
#include "Globals.h"
#include "Enemy_Drop.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModuleAudio.h"

Enemy_Drop::Enemy_Drop(int x, int y) : Enemy(x, y)
{

	life = 1000; 

	original_position.y = y;

	collider = App->collision->AddCollider({ 0, 0, 13, 7 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	drop.PushBack({ 198, 127, 13, 7 }); 
	drop.PushBack({ 214, 126, 13, 9 });
	drop.PushBack({ 230, 126, 13, 12 });
	drop.PushBack({ 247, 128, 11, 15 });
	drop.PushBack({ 264, 130, 9, 18 });
	drop.PushBack({ 280, 129, 9, 20 });

	drop.speed = 0.05f;
	animation = &drop;
}

void Enemy_Drop::Move()
{
	/*counter++;
	while (counter == 100)
	{
		drop.PushBack({ 295, 125, 11, 14 }); 
		collider->rect.h = 14;
		collider->rect.w = 11;
		position.y += 1; 
		if (position.y == 100) 
		{ 
			counter = 101; 
			break; 
		}
	}
	while (counter == 102)
	{
		drop.PushBack({ 310, 127, 13, 13 });
		collider->rect.h = 13;
		collider->rect.w = 13;
		position.y += 1; 
		if (collider->type == COLLIDER_WALL)
		{
			drop.PushBack({ 332, 131, 17, 9 }); 
			drop.PushBack({ 359, 133, 25, 7 });
		}
	} */
}

