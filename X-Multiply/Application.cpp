#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleLevel1.h"
#include "ModuleMenu.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModuleFonts.h"
#include "ModuleAudio.h"
#include "ModuleGameOver.h"
#include "ModuleStageCleared.h"
#include "ModulePowerUp.h"

Application::Application()
{
	int i = 0;
	modules[i++] = window = new ModuleWindow();
	modules[i++] = render = new ModuleRender();
	modules[i++] = input = new ModuleInput();
	modules[i++] = textures = new ModuleTextures();
	modules[i++] = audio = new ModuleAudio();
	modules[i++] = fonts = new ModuleFonts();
	modules[i++] = menu = new ModuleMenu();
	modules[i++] = lvl1 = new ModuleLevel1();
	modules[i++] = game_over = new ModuleGameOver();
	modules[i++] = stage_cleared = new ModuleStageCleared();
	modules[i++] = enemies = new ModuleEnemies();
	modules[i++] = player = new ModulePlayer();
	modules[i++] = powerup = new ModulePowerUp();
	modules[i++] = particles = new ModuleParticles();
	modules[i++] = collision = new ModuleCollision();
	modules[i++] = fade = new ModuleFadeToBlack();
}	

Application::~Application()
{
	for(int i = NUM_MODULES - 1; i >= 0; --i)
		delete modules[i];
}

bool Application::Init()
{
	bool ret = true;

	// Desactivate modules here unless Menu ----
	lvl1->Disable();
	game_over->Disable();
	stage_cleared->Disable();
	player->Disable();
	collision->Disable();
	enemies->Disable();
	powerup->Disable();
	// ----------------------------

	for(int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->Init();

	for(int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Start() : true;

	return ret;
}

update_status Application::Update()
{
	update_status ret = UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PreUpdate() : UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Update() : UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PostUpdate() : UPDATE_CONTINUE;

	return ret;
}

bool Application::CleanUp()
{
	bool ret = true;

	for(int i = NUM_MODULES - 1; i >= 0 && ret == true; --i)
		ret = modules[i]->IsEnabled() ? modules[i]->CleanUp() : true;

	return ret;
}