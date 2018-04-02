#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleBackground.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleBackground::ModuleBackground()
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

	// flag animation
	flag.PushBack({848, 208, 40, 40});
	flag.PushBack({848, 256, 40, 40});
	flag.PushBack({848, 304, 40, 40});
	flag.speed = 0.08f;
}

ModuleBackground::~ModuleBackground()
{}

// Load assets
bool ModuleBackground::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("background completed.png");
	tilemap = App->textures->Load("LV1_TilemapCompleted.png");
	return ret;
}

// Update: draw background
update_status ModuleBackground::Update()
{
	float speed_graphics = 2; 
	float speed_tilemap = 2; 

	if (background_w < 4961) {
		background_w -= speed_graphics; 
	}
	if (tilemap_w < 4961) {
		tilemap_w -= speed_tilemap; 
	}

	// Draw everything --------------------------------------
	App->render->Blit(graphics, (background_w)/3.5, 0, &background, 0.75f); // backround
	App->render->Blit(tilemap, (tilemap_w)/3.5, 0, &ground, 0.85f); //tilemap

	//App->render->Blit(graphics, 560, 8, &(flag.GetCurrentFrame()), 0.75f); // flag animation

	// TODO 2: Draw the ship from the sprite sheet with some parallax effect
	// TODO 3: Animate the girl on the ship (see the sprite sheet)

	return UPDATE_CONTINUE;
}