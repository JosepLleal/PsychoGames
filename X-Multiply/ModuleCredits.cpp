#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleInput.h"
#include "ModuleCredits.h"
#include "ModuleMenu.h"





ModuleCredits::ModuleCredits()
{
	// Background 
	credit.x = 0;
	credit.y = 0;
	credit.w = 384;
	credit.h = 224;
}

ModuleCredits::~ModuleCredits()
{}

// Load assets
bool ModuleCredits::Start()
{
	LOG("Loading credit scene");

	graphics = App->textures->Load("image/credits.png");

	App->player->Enable();

	return true;
}

// UnLoad assets
bool ModuleCredits::CleanUp()
{
	LOG("Unloading credit scene");
	App->player->Disable();
	App->textures->Unload(graphics);
	return true;
}

// Update: draw background
update_status ModuleCredits::Update()
{

	// Draw everything --------------------------------------
	App->render->Blit(graphics, (credit_w) / 3.5, 0, &credit, 0.75f); // background

																	   // TODO 2: make so pressing SPACE the HONDA stage is loaded
	if (App->input->keyboard[SDL_SCANCODE_SPACE])
	{
		App->fade->FadeToBlack(this, App->menu, 1);
	}
	return UPDATE_CONTINUE;
	}