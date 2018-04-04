#include "Globals.h"
#include "Application.h"
#include "ModuleLevel2.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleInput.h"
#include "ModuleLevel1.h"

// Reference at https://youtu.be/6OlenbCC4WI?t=382

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
	LOG("Loading background assets");
	bool ret = true;
	tilemap = App->textures->Load("image/LV2_Tilemap.png");

	// TODO 1: Enable (and properly disable) the player module
	App->player->Enable();
	return ret;
}

// Load assets
bool ModuleLevel2::CleanUp()
{
	// TODO 5: Remove all memory leaks
	LOG("Unloading honda stage");
	App->player->Disable();
	App->textures->Unload(graphics);
	return true;
}

// Update: draw background
update_status ModuleLevel2::Update()
{
	// Draw everything --------------------------------------	
	App->render->Blit(tilemap, (tilemap_w) / 3.5, 0, &ground, 0.75f); //tilemap

	// TODO 2: make so pressing SPACE the KEN stage is loaded
	if (App->input->keyboard[SDL_SCANCODE_SPACE])
		App->fade->FadeToBlack(this, App->lvl1);

	return UPDATE_CONTINUE;
}