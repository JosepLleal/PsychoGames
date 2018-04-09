#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleInput.h"
#include "ModuleCredits.h"
#include "ModuleMenu.h"
#include "ModuleAudio.h"





ModuleCredits::ModuleCredits()
{
	// Background 
	credit.x = 0;
	credit.y = 0;
	credit.w = 384;
	credit.h = 288;
}

ModuleCredits::~ModuleCredits()
{}

// Load assets
bool ModuleCredits::Start()
{
	LOG("Loading credit scene");

	graphics = App->textures->Load("image/credits.png");
	App->audio->MusicPlay("Sound/14_The_End_of_Operation_All_Clear_.ogg", 0.5f);

	return true;
}

// UnLoad assets
bool ModuleCredits::CleanUp()
{
	LOG("Unloading credit scene");
	App->textures->Unload(graphics);
	return true;
}

// Update: draw background
update_status ModuleCredits::Update()
{

	// Draw everything --------------------------------------
	App->render->Blit(graphics, (credit_w) / 3.5, 0, &credit, 0); // background

	if (App->input->keyboard[SDL_SCANCODE_SPACE])
	{
		App->fade->FadeToBlack(this, App->menu, 1);
	}
	return UPDATE_CONTINUE;
	}