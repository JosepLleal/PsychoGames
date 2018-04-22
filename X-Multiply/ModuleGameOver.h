#ifndef __MODULEGAMEOVER_H__
#define __MODULEGAMEOVER_H__

#include "Module.h"

struct SDL_Texture;

class ModuleGameOver : public Module
{
public:
	ModuleGameOver();
	~ModuleGameOver();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	int font_score = -1;
	char score_text[10];
	uint score = 0;

	SDL_Texture * background = nullptr;
	uint fx = 0;
};

#endif // __MODULESCENEINTRO_H__
