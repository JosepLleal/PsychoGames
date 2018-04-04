#include "Globals.h"
#include "Application.h"
#include "ModuleLevel2.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleInput.h"
#include "ModuleLevel1.h"
#include "ModuleMenu.h"
#include "ModuleCredits.h"



ModuleLevel2::ModuleLevel2()
{
	// tilemap
	ground.x = 0;
	ground.y = 0;
	ground.w = 1323;
	ground.h = 513;


}

ModuleLevel2::~ModuleLevel2()
{}

// Load assets
bool ModuleLevel2::Start()
{
	LOG("Loading level 2 scene");
	bool ret = true;
	tilemap = App->textures->Load("image/LV2_Tilemap.png");

	App->player->Enable();
	return ret;
}

// Load assets
bool ModuleLevel2::CleanUp()
{
	LOG("Unloading level 2 scene");
	App->player->Disable();
	App->textures->Unload(graphics);
	return true;
}

// Update: draw background
update_status ModuleLevel2::Update()
{
	// Draw everything --------------------------------------	
	App->render->Blit(tilemap, (tilemap_w) / 3.5, 0, &ground, 0.75f); //tilemap

	if (App->input->keyboard[SDL_SCANCODE_SPACE])
		App->fade->FadeToBlack(this, App->credit, 1);

	return UPDATE_CONTINUE;
}