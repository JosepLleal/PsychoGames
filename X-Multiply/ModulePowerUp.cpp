#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePowerUp.h"
#include "ModuleParticles.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "PowerUp.h"

//add powerup.h's
#include "PowerUp_Enemy.h"
#include "PowerUp_SpeedUp.h"
#include "PowerUp_Bomb.h"
#include "ModuleAudio.h"

#define SPAWN_MARGIN 50

ModulePowerUp::ModulePowerUp()
{
	for (uint i = 0; i < MAX_POWERUPS; ++i)
		powerup[i] = nullptr;
}

ModulePowerUp::~ModulePowerUp()
{}

bool ModulePowerUp::Start()
{
	//enemies sprites
	sprites = App->textures->Load("image/PowerUps.png");

	//Loading FX
	powerup_killed = App->audio->LoadFX("sound/xmultipl-055.wav");
	SpeedUp = App->audio->LoadFX("sound/xmultipl-050.wav");
	Bomb = App->audio->LoadFX("sound/xmultipl-048.wav");

	return true;
}

update_status ModulePowerUp::PreUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_POWERUPS; ++i)
	{
		if (queue[i].type != POWERUP_TYPES::NONE)
		{
			if (queue[i].x * SCREEN_SIZE < App->render->camera.x + (App->render->camera.w * SCREEN_SIZE) + SPAWN_MARGIN)
			{
				SpawnPowerUp(queue[i]);
				queue[i].type = POWERUP_TYPES::NONE;
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before render is available
update_status ModulePowerUp::Update()
{
	for (uint i = 0; i < MAX_POWERUPS; ++i)
		if (powerup[i] != nullptr) powerup[i]->Move();

	for (uint i = 0; i < MAX_POWERUPS; ++i)
		if (powerup[i] != nullptr) powerup[i]->Draw(sprites);

	return UPDATE_CONTINUE;
}

update_status ModulePowerUp::PostUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_POWERUPS; ++i)
	{
		if (powerup[i] != nullptr)
		{
			if (powerup[i]->position.x * SCREEN_SIZE < (App->render->camera.x) - SPAWN_MARGIN)
			{
				delete powerup[i];
				powerup[i] = nullptr;
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModulePowerUp::CleanUp()
{
	LOG("Freeing all enemies");

	App->textures->Unload(sprites);
	App->audio->UnloadFX(powerup_killed);
	App->audio->UnloadFX(SpeedUp);
	App->audio->UnloadFX(Bomb);

	for (uint i = 0; i < MAX_POWERUPS; ++i)
	{
		if (powerup[i] != nullptr)
		{
			delete powerup[i];
			powerup[i] = nullptr;
		}
		queue[i].type = NONE;
	}

	return true;
}

bool ModulePowerUp::AddPowerUp(POWERUP_TYPES type, int x, int y)
{
	bool ret = false;

	for (uint i = 0; i < MAX_POWERUPS; ++i)
	{
		if (queue[i].type == POWERUP_TYPES::NONE)
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

void ModulePowerUp::SpawnPowerUp(const PowerUpInfo& info)
{
	
	uint i = 0;
	for (; powerup[i] != nullptr && i < MAX_POWERUPS; ++i);
	if (i != MAX_POWERUPS)
	{
		switch (info.type)
		{
		case POWERUP_TYPES::POWERUP_ENEMY:
			powerup[i] = new PowerUp_Enemy(info.x, info.y);
			break;

		case POWERUP_TYPES::SPEED_UP:
			powerup[i] = new PowerUp_SpeedUp(info.x, info.y);
			break;
		case POWERUP_TYPES::BOMB:
			powerup[i] = new PowerUp_Bomb(info.x, info.y);
			break;
		}
	}
}

void ModulePowerUp::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_POWERUPS; ++i)
	{
		if (powerup[i] != nullptr && powerup[i]->GetCollider() == c1)
		{
			powerup[i]->OnCollision(c2);

			delete powerup[i];
			powerup[i] = nullptr;
			break;
		}
	}
}