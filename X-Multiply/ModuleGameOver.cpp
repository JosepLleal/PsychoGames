#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleFadeToBlack.h"
#include "ModuleMenu.h"
#include "ModuleGameOver.h"
#include "ModuleAudio.h"
#include "ModulePLayer.h"


ModuleGameOver::ModuleGameOver()
{}

ModuleGameOver::~ModuleGameOver()
{}

// Load assets
bool  ModuleGameOver::Start()
{
	LOG("Loading GameOver");

	background = App->textures->Load("image/Game_Over.png");
	App->audio->MusicPlay("Sound/16_Game_Over.ogg", 1.5f);

	App->render->camera.x = App->render->camera.y = 0;
	
	return true;
}

// UnLoad assets
bool  ModuleGameOver::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(background);

	return true;
}

// Update: draw background
update_status  ModuleGameOver::Update()
{
	App->render->Blit(background, (SCREEN_WIDTH/2)-80, (SCREEN_HEIGHT/2)-30, NULL);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN && App->fade->IsFading() == false)
	{
		App->fade->FadeToBlack(this, (Module*)App->menu);
	}

	return UPDATE_CONTINUE;
}