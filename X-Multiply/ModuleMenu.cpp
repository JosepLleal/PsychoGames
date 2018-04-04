#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleInput.h"
#include "ModuleLevel1.h"
#include "ModuleCredits.h"
#include "ModuleMenu.h"



ModuleMenu::ModuleMenu()
{
	// Background 
	background.x = 0;
	background.y = 0;
	background.w = 384;
	background.h = 224;


}

ModuleMenu::~ModuleMenu()
{}

// Load assets
bool ModuleMenu::Start()
{
	LOG("Loading menu scene");
	bool ret = true;
	graphics = App->textures->Load("image/main_menu.png");

	
	return ret;
}

// Load assets
bool ModuleMenu::CleanUp()
{
	
	LOG("Unloading menu scene");
	App->textures->Unload(graphics);
	return true;
}

// Update: draw background
update_status ModuleMenu::Update()
{
	// Draw everything --------------------------------------	
	App->render->Blit(graphics, (background_w) / 3.5, 0, &background, 0); // backround

	if (App->input->keyboard[SDL_SCANCODE_SPACE])
	{
		App->fade->FadeToBlack(this, App->lvl1, 1);

	}

	return UPDATE_CONTINUE;
}