#ifndef __MODULELEVEL1_H__
#define __MODULELEVEL1_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleLevel1 : public Module
{
public:
	ModuleLevel1();
	~ModuleLevel1();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	
	SDL_Texture* graphics = nullptr;
	SDL_Texture* tilemap1 = nullptr;
	SDL_Rect ground;
	SDL_Rect foreground;
	SDL_Rect background;
	
	int background_w = 0;
	int tilemap_w = 0;

	float foreground_pos;
	bool forward;
};

#endif // __MODULESCENEKEN_H__