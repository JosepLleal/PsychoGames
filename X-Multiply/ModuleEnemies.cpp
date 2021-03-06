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

#include "Enemy_Drop.h"
#include "Enemy_YellowBall.h"
#include "Enemy_YellowBall2.h"
#include "Enemy_Boss.h"
#include "Diamond_Wall.h"
#include "Diamond_Wall2.h"

#define SPAWN_MARGIN 50

ModuleEnemies::ModuleEnemies()
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
		enemies[i] = nullptr;
}

// Destructor
ModuleEnemies::~ModuleEnemies()
{
}

bool ModuleEnemies::Start()
{
	//enemies sprites
	sprites = App->textures->Load("image/lvl5_enemies2.png");

	//Loading FX
	redball = App->audio->LoadFX("Sound/xmultipl-100.wav");
	//drop = App->audio->LoadFX("Sound/")
	yellow_ball = App->audio->LoadFX("Sound/xmultipl-094.wav");
	diamond_fall = App->audio->LoadFX("Sound/xmultipl-080.wav");
	boss_attack = App->audio->LoadFX("Sound/xmultipl-067.wav");

	return true;
}

update_status ModuleEnemies::PreUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (queue[i].type != ENEMY_TYPES::NO_TYPE)
		{
			if (queue[i].type == ENEMY_TYPES::REDBALL || queue[i].type == ENEMY_TYPES::REDBALL1 || queue[i].type == ENEMY_TYPES::REDBALL2 || queue[i].type == ENEMY_TYPES::REDBALL3 || queue[i].type == ENEMY_TYPES::REDBALL4 || queue[i].type == ENEMY_TYPES::REDBALL5)
			{
				if (queue[i].x * SCREEN_SIZE < App->render->camera.x + (App->render->camera.w * SCREEN_SIZE) + (SPAWN_MARGIN/2) + (SPAWN_MARGIN/4) )
				{
					SpawnEnemy(queue[i]);
					queue[i].type = ENEMY_TYPES::NO_TYPE;
				}
			}
			else
			{
				if (queue[i].x * SCREEN_SIZE < App->render->camera.x + (App->render->camera.w * SCREEN_SIZE) + SPAWN_MARGIN)
				{
					SpawnEnemy(queue[i]);
					queue[i].type = ENEMY_TYPES::NO_TYPE;
				}
			}
			
		}
	}

	return UPDATE_CONTINUE;
}

// Called before render is available
update_status ModuleEnemies::Update()
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr) enemies[i]->Move();

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr) enemies[i]->Draw(sprites);

	return UPDATE_CONTINUE;
}

update_status ModuleEnemies::PostUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			if (enemies[i]->position.x * SCREEN_SIZE < (App->render->camera.x) - SPAWN_MARGIN)
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
	//App->audio->UnloadFX(drop);
	App->audio->UnloadFX(redball);
	App->audio->UnloadFX(yellow_ball);
	App->audio->UnloadFX(diamond_fall);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
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

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (queue[i].type == ENEMY_TYPES::NO_TYPE)
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
	for (; enemies[i] != nullptr && i < MAX_ENEMIES; ++i);

	if (i != MAX_ENEMIES)
	{
		switch (info.type)
		{
		case ENEMY_TYPES::REDBALL:
			enemies[i] = new Enemy_Red_Ball(info.x, info.y);
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
		case ENEMY_TYPES::DROP: 
			enemies[i] = new Enemy_Drop(info.x, info.y);
			break;
		case ENEMY_TYPES::YELLOWBALL:
			enemies[i] = new Enemy_YellowBall(info.x, info.y);
			break;
		case ENEMY_TYPES::YELLOWBALL2:
			enemies[i] = new Enemy_YellowBall2(info.x, info.y);
			break;
		case ENEMY_TYPES::DIAMOND_WALL:
			enemies[i] = new Diamond_Wall(info.x, info.y);
			break;
		case ENEMY_TYPES::DIAMOND_WALL2:
			enemies[i] = new Diamond_Wall2(info.x, info.y);
			break;
		case ENEMY_TYPES::BOSS:
			enemies[i] = new Enemy_Boss(info.x, info.y);
			break;

		}
	}
}

void ModuleEnemies::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		
		if (enemies[i] != nullptr && enemies[i]->GetCollider() == c1)
		{
			enemies[i]->OnCollision(c2);
			if (c1->type == COLLIDER_PLAYER_SHOT || c2->type == COLLIDER_PLAYER_SHOT)
			{
				--(enemies[i]->life);
			}

			if (enemies[i]->life <= 0)
			{

				enemies[i]->OnCollision(c2);
				

				delete enemies[i];
				enemies[i] = nullptr;
				break;
			}
			

		}

	}
}