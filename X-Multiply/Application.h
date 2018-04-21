#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 16

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModuleParticles;
class ModuleAudio;
class ModuleLevel1;
class ModuleMenu;
class ModuleGameOver;
class ModuleStageCleared;
class ModulePlayer;
class ModuleFadeToBlack;
class ModuleCollision;
class ModuleEnemies;
class ModuleFonts;
class ModulePowerUp;
class Module;

class Application
{
public:

	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleRender* render;
	ModuleInput* input;
	ModuleTextures* textures;
	ModuleLevel1* lvl1;
	ModuleMenu* menu;
	ModuleGameOver* game_over;
	ModuleStageCleared* stage_cleared;
	ModuleCollision* collision;
	ModulePlayer* player;
	ModuleFadeToBlack* fade;
	ModuleParticles* particles;
	ModuleEnemies* enemies;
	ModuleFonts* fonts;
	ModuleAudio* audio;
	ModulePowerUp* powerup;

public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__