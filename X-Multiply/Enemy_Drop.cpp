#include "Application.h"
#include "Globals.h"
#include "Enemy_Drop.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModuleAudio.h"
#include "ModuleParticles.h"

Enemy_Drop::Enemy_Drop(int x, int y) : Enemy(x, y)
{

	life = 1000; 

	original_position.y = y;
	original_position.x = x;

	collider = App->collision->AddCollider({ 0, 0, 13, 7 }, COLLIDER_TYPE::COLLIDER_DIAMOND, (Module*)App->enemies);

	drop.PushBack({ 198, 127, 13, 7 }); 
	drop.PushBack({ 214, 126, 13, 9 });
	drop.PushBack({ 230, 126, 13, 12 });
	drop.PushBack({ 247, 128, 11, 15 });
	drop.PushBack({ 264, 130, 9, 18 });
	drop.PushBack({ 280, 129, 9, 20 });

	drop.speed = 0.025f;
	animation = &drop;

	splash.PushBack({ 332, 130, 17, 9 });
	splash.PushBack({ 358, 130, 27, 11 });
	splash.PushBack({200, 160, 29, 13 });
	splash.speed = 0.4f;
	splash.loop = false;

	splash2.PushBack({ 195, 175, 45, 38 });
	splash2.PushBack({ 250, 175, 50, 38 });
	splash2.PushBack({ 307, 175, 47, 38 });
	splash2.PushBack({ 360, 175, 36, 38 });
	splash2.PushBack({ 404, 175, 37, 38 });
	splash2.PushBack({ 454, 175, 41, 38 });
	splash2.PushBack({ 499, 175, 47, 38 });
	splash2.PushBack({ 549, 175, 58, 38 });
	splash2.PushBack({ 612, 175, 55, 38 });
	//splash2.PushBack({ 258, 276, 35, 17 });
	//splash2.PushBack({ 294, 277, 55, 23 });
	splash2.speed = 0.1f;
	splash2.loop = false;
	

}

void Enemy_Drop::Move()
{
	if (animation == &drop || animation == &drop2 || animation == &drop3)
	{
		counter++;
		splash.Reset();
		splash2.Reset();
		if (counter == 100)
		{
			animation = &drop2;
			drop2.PushBack({ 295, 125, 11, 14 });

		}
		else if (counter == 110)
		{
			animation = &drop3;
			drop3.PushBack({ 310, 127, 13, 13 });

		}
		if (counter >= 100)
		{
			position.y += counter / 45;
		}
	}
	else if(animation == &splash)
	{

		counter = 0;
		position.y += 0;

		if (splash.Finished() == true) 
		{
			animation = &drop;
			drop.Reset();
			position.y = original_position.y;
			position.x = original_position.x; 
		}
	}
	else if (animation == &splash2)
	{
		counter = 0;
		counter3++;
		position.y += 0;

		if (counter3 > 50)
		{
			if (counter3 == 51) {
				App->particles->AddParticle(App->particles->drop_shot, original_position.x, original_position.y + 160, COLLIDER_ENEMY_SHOT);
			}
		}

		if (splash2.Finished() == true) 
		{
			counter2 = 0; 
			animation = &drop;
			drop.Reset();
			position.y = original_position.y;
			position.x = original_position.x;
		}
	}

}

void Enemy_Drop::OnCollision(Collider* collider)
{
	if (collider->type == COLLIDER_WALL)
	{
		animation = &splash;
	}
	else if (collider->type == COLLIDER_NONE)
	{
		counter2++;
		animation = &splash2;
		if (counter == 0)
		{
			position.y -= 12;
			position.x -= 15;
		}
	}
}

