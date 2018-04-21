#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleFadeToBlack.h"
#include "ModuleMenu.h"
#include "ModuleStageCleared.h"
#include "ModuleAudio.h"
#include "ModulePLayer.h"


ModuleStageCleared::ModuleStageCleared()
{}

ModuleStageCleared::~ModuleStageCleared()
{}

// Load assets
bool  ModuleStageCleared::Start()
{
	LOG("Loading GameOver");

	background = App->textures->Load("image/stage1_cleared.png");
	App->audio->MusicPlay("Sound/06_Stage_Clear.ogg", 1.5f);

	App->render->camera.x = App->render->camera.y = 0;

	return true;
}

// UnLoad assets
bool  ModuleStageCleared::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(background);

	return true;
}

// Update: draw background
update_status  ModuleStageCleared::Update()
{
	App->render->Blit(background, 0, 0, NULL);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN && App->fade->IsFading() == false)
	{
		App->fade->FadeToBlack(this, (Module*)App->menu);
	}

	return UPDATE_CONTINUE;
}