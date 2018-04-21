#ifndef __MODULEPOWERUP_H__
#define __MODULEPOWERUP_H__

#include "Module.h"
#include "ModuleTextures.h"

#define MAX_POWERUPS 20

enum POWERUP_TYPES
{
	NONE,
};

class PowerUp;

struct PowerUpInfo
{
	POWERUP_TYPES type = POWERUP_TYPES::NONE;
	int x, y;
};

class ModulePowerUp : public Module
{
public:

	ModulePowerUp();
	~ModulePowerUp();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

	bool AddPowerUp(POWERUP_TYPES type, int x, int y);

private:

	void SpawnPowerUp(const PowerUpInfo& info);

private:

	PowerUpInfo queue[MAX_POWERUPS];
	PowerUp* powerup[MAX_POWERUPS];

	SDL_Texture* sprites;

	uint powerup_pickup; //FX when enemy dies
};

#endif // __ModuleEnemies_H__