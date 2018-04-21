#ifndef __MODULESTAGECLEARED_H__
#define __MODULESTAGECLEARED_H__

#include "Module.h"

struct SDL_Texture;

class ModuleStageCleared : public Module
{
public:
	ModuleStageCleared();
	~ModuleStageCleared();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture * background = nullptr;
	uint fx = 0;
};

#endif // __MODULESCENEINTRO_H__
