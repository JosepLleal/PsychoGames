#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleFadeToBlack.h"
#include "ModuleMenu.h"
#include "ModuleAudio.h"
#include "ModulePLayer.h"


ModuleMenu::ModuleMenu()
{}

ModuleMenu::~ModuleMenu()
{}

// Load assets
bool  ModuleMenu::Start()
{
	LOG("Loading space intro");
	
	background = App->textures->Load("image/main_menu.png");
	App->audio->MusicPlay("Sound/01_X-Multiply_Title_.ogg", 1.5f);

	App->render->camera.x = App->render->camera.y = 0;
	App->player->lives = 2;
	App->player->score = 0;
	
	return true;
}

// UnLoad assets
bool  ModuleMenu::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(background);
	
	return true;
}

// Update: draw background
update_status  ModuleMenu::Update()
{
	App->render->Blit(background, 0, 0, NULL);

	if((App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN || App->input->controller[BUTTON_A] == KEY_DOWN) && App->fade->IsFading() == false)
	{
		App->fade->FadeToBlack(this, (Module*)App->lvl5);
	}

	return UPDATE_CONTINUE;
}