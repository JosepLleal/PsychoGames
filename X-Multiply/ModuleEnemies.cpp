#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleEnemies.h"
#include "ModuleParticles.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "Enemy.h"
#include "ModuleAudio.h"

#include "Enemy_Red_Ball.h"
#include "Enemy_Red_Ball1.h"
#include "Enemy_Red_Ball2.h"
#include "Enemy_Red_Ball3.h"
#include "Enemy_Red_Ball4.h"
#include "Enemy_Red_Ball5.h"

#include "Enemy_YellowBall.h"
#include "Diamond_Wall.h"

#define SPAWN_MARGIN 50

ModuleEnemies::ModuleEnemies()
{
	for(uint i = 0; i < MAX_ENEMIES; ++i)
		enemies[i] = nullptr;
}

// Destructor
ModuleEnemies::~ModuleEnemies()
{
}

bool ModuleEnemies::Start()
{
	//enemies sprites
	sprites = App->textures->Load("image/lvl5_enemies.png");

	//Loading FX
	enemy_death = App->audio->LoadFX("Sound/xmultipl-100.wav");

	return true;
}

update_status ModuleEnemies::PreUpdate()
{
	// check camera position to decide what to spawn
	for(uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if(queue[i].type != ENEMY_TYPES::NO_TYPE)
		{
			if(queue[i].x * SCREEN_SIZE < App->render->camera.x + (App->render->camera.w * SCREEN_SIZE) + SPAWN_MARGIN)
			{
				SpawnEnemy(queue[i]);
				queue[i].type = ENEMY_TYPES::NO_TYPE;
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before render is available
update_status ModuleEnemies::Update()
{
	for(uint i = 0; i < MAX_ENEMIES; ++i)
		if(enemies[i] != nullptr) enemies[i]->Move();

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr) enemies[i]->Draw(sprites);

	return UPDATE_CONTINUE;
}

update_status ModuleEnemies::PostUpdate()
{
	// check camera position to decide what to spawn
	for(uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if(enemies[i] != nullptr)
		{
			if(enemies[i]->position.x * SCREEN_SIZE < (App->render->camera.x) - SPAWN_MARGIN)
			{
				delete enemies[i];
				enemies[i] = nullptr;
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleEnemies::CleanUp()
{
	LOG("Freeing all enemies");

	App->textures->Unload(sprites);
	App->audio->UnloadFX(enemy_death);

	for(uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if(enemies[i] != nullptr)
		{
			delete enemies[i];
			enemies[i] = nullptr;
		}
		queue[i].type = NO_TYPE;
	}

	return true;
}

bool ModuleEnemies::AddEnemy(ENEMY_TYPES type, int x, int y)
{
	bool ret = false;

	for(uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if(queue[i].type == ENEMY_TYPES::NO_TYPE)
		{
			queue[i].type = type;
			queue[i].x = x;
			queue[i].y = y;
			ret = true;
			break;
		}
	}

	return ret;
}

void ModuleEnemies::SpawnEnemy(const EnemyInfo& info)
{
	// find room for the new enemy
	uint i = 0;
	for(; enemies[i] != nullptr && i < MAX_ENEMIES; ++i);

	if(i != MAX_ENEMIES)
	{
		switch(info.type)
		{
		case ENEMY_TYPES::REDBALL:
			enemies[i] = new Enemy_Red_Ball(info.x,info.y);
			break;
		case ENEMY_TYPES::REDBALL1:
			enemies[i] = new Enemy_Red_Ball1(info.x, info.y);
			break;
		case ENEMY_TYPES::REDBALL2:
			enemies[i] = new Enemy_Red_Ball2(info.x, info.y);
			break;
		case ENEMY_TYPES::REDBALL3:
			enemies[i] = new Enemy_Red_Ball3(info.x, info.y);
			break;
		case ENEMY_TYPES::REDBALL4:
			enemies[i] = new Enemy_Red_Ball4(info.x, info.y);
			break;
		case ENEMY_TYPES::REDBALL5:
			enemies[i] = new Enemy_Red_Ball5(info.x, info.y);
			break;
		case ENEMY_TYPES::YELLOWBALL:
			enemies[i] = new Enemy_YellowBall(info.x, info.y);
			break;
		case ENEMY_TYPES::DIAMOND_WALL:
			enemies[i] = new Diamond_Wall(info.x, info.y);
			break;

		}
	}
}

void ModuleEnemies::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		//if (enemies[i] != nullptr && enemies[i]->GetCollider() == c1 && c1->type == COLLIDER_DIAMOND)
		//{
		//	enemies[i]->OnCollision(c2);

		//	//Add diamond FX

		//}
		if (enemies[i] != nullptr && enemies[i]->GetCollider() == c1)
		{
			enemies[i]->OnCollision(c2);
			App->particles->AddParticle(App->particles->shot_impact, enemies[i]->position.x, enemies[i]->position.y);
			--(enemies[i]->life);


			if (enemies[i]->life <= 0) 
			{

				enemies[i]->OnCollision(c2);

				App->particles->AddParticle(App->particles->shot_impact, enemies[i]->position.x, enemies[i]->position.y);
				App->audio->ChunkPlay(enemy_death);


				delete enemies[i];
				enemies[i] = nullptr;
				break;
			}

		}

	}
}