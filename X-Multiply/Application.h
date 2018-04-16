#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 13

class Module;
class ModuleWindow;
class ModuleRender;
class ModuleInput;
class ModuleTextures; 
class ModulePlayer;
class ModuleAudio;
class ModuleMenu;
class ModuleLevel1;
class ModuleLevel2;
class ModuleCredits;
class ModuleCollision;
class ModuleEnemies;
class ModuleParticles;
class ModuleFadeToBlack;

class Application
{
public:

	Module* modules[NUM_MODULES];
	ModuleWindow* window;

	ModuleRender* render;
	ModuleInput* input;
	ModuleTextures* textures;
	ModuleAudio* audio; 
	ModuleMenu* menu;
	ModuleLevel1* lvl1;
	ModuleLevel2* lvl2;
	ModuleCredits* credit;
	ModuleCollision* collision;
	ModuleParticles* particles;
	ModuleEnemies* enemies;
	ModulePlayer* player;
	ModuleFadeToBlack* fade;

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