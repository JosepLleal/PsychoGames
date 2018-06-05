#ifndef __MODULELEVEL5_H__
#define __MODULELEVEL5_H__

#include "Module.h"

struct SDL_Texture;

class ModuleLevel5 : public Module
{
public:
	ModuleLevel5();
	~ModuleLevel5();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	
	SDL_Texture* background = nullptr;
	SDL_Texture* hud = nullptr;
	SDL_Texture* tilemap1 = nullptr;
	SDL_Texture* diamond = nullptr;

	float opacity;
	bool fading = false;
	bool boss = true;
	int dark_counter;

	SDL_Rect background_parallax;
	SDL_Rect ground_parallax;

	Collider* HUDhitbox; 
};

#endif // __MODULESCENESPACE_H__