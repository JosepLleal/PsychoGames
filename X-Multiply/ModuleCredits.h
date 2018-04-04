
#ifndef __MODULECREDITS_H__
#define __MODULECREDITS_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleCredits : public Module
{
public:
	ModuleCredits();
	~ModuleCredits();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Rect background;

	int background_w = 0;
	

	float foreground_pos;
};

#endif // __MODULESCENEKEN_H__