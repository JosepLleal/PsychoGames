#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleLevel1.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleInput.h"
#include "ModuleLevel2.h"


// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleLevel1::ModuleLevel1()
{
	// tilemap
	ground.x = 0;
	ground.y = 0;
	ground.w = 4961;
	ground.h = 513;

	// Background / sky
	background.x = 0;
	background.y = 0;
	background.w = 4961;
	background.h = 512;
}

ModuleLevel1::~ModuleLevel1()
{}

// Load assets
bool ModuleLevel1::Start()
{
	LOG("Loading ken scene");
	
	graphics = App->textures->Load("image/background completed.png");
	tilemap1 = App->textures->Load("image/LV1_TilemapCompleted.png");

	// TODO 1: Enable (and properly disable) the player module
	App->player->Enable();

	return true;
}

// UnLoad assets
bool ModuleLevel1::CleanUp()
{
	LOG("Unloading ken scene");
	App->player->Disable();
	App->textures->Unload(graphics);
	return true;
}

// Update: draw background
update_status ModuleLevel1::Update()
{
	int speed_graphics = 4;
	int speed_tilemap = 5;

	if (background_w < 4961) {
		background_w -= speed_graphics;
	}
	if (tilemap_w < 4961) {
		tilemap_w -= speed_tilemap;
	}

	// Draw everything --------------------------------------
	App->render->Blit(graphics, (background_w) / 3.5, 0, &background, 0.75f); // backround
	App->render->Blit(tilemap1, (tilemap_w) / 3.5, 0, &ground, 0.75f); //tilemap
	// TODO 2: make so pressing SPACE the HONDA stage is loaded
	if (App->input->keyboard[SDL_SCANCODE_SPACE])
	{
		App->fade->FadeToBlack(this, App->lvl2, 1);
		App->player->position.x = 100;
		App->player->position.y = 30;

	}
	return UPDATE_CONTINUE;
}