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

	int fontscore = -1; 
	uint score1 = 0;
	char score_text[10];

public:

	SDL_Texture * background = nullptr;
	uint fx = 0;
};

#endif // __MODULESCENEINTRO_H__
