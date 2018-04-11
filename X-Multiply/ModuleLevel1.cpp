#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModulePlayer.h"
#include "ModuleLevel1.h"
#include "ModuleLevel2.h"
#include "ModuleFadeToBlack.h"


ModuleLevel1::ModuleLevel1()
{
	// tilemap
	ground.x = 0;
	ground.y = 1;
	ground.w = 4961;
	ground.h = 513;

	// Background 
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
	LOG("Loading level 1 scene");
	
	backround = App->textures->Load("image/background completed.png");
	tilemap1 = App->textures->Load("image/LV1_TilemapCompleted.png");
	App->audio->MusicPlay("Sound/04_Into_the_Human_Body_Stage_1_.ogg", 0.5f);
	App->render->camera.x = 0;
	App->render->camera.y = 0;
	
	App->player->Enable();
	App->collision->Enable();

	//TOP WALLS. FIRST WALLS = UPPER
	
	App->collision->AddCollider({ 495, 0, 2040, 12 }, COLLIDER_WALL);
	App->collision->AddCollider({ 640, 12, 70, 12 }, COLLIDER_WALL);
	App->collision->AddCollider({ 761, 12, 57, 29 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1005, 12, 104, 25 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1153, 12, 70, 12 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1423, 12, 138, 84 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1665, 12, 70, 12 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2009, 12, 213, 84 }, COLLIDER_WALL);
	

	//BOTTOM WALLS. FIRST WALLS = UPPER
	App->collision->AddCollider({ 0, 213, 2867, 12 }, COLLIDER_WALL);
	App->collision->AddCollider({ 405, 183, 63, 30 }, COLLIDER_WALL);
	App->collision->AddCollider({ 495, 188, 104, 25 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1024, 201, 70, 12 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1263, 188, 104, 25 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1423, 129, 138, 84 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2009, 129, 213, 84 }, COLLIDER_WALL);
	


	return true;
}

// UnLoad assets
bool ModuleLevel1::CleanUp()
{
	LOG("Unloading level 1 scene");
	App->player->Disable();
	App->collision->Disable();
	App->textures->Unload(backround);
	App->textures->Unload(tilemap1);
	
	return true;
}

// Update: draw background
update_status ModuleLevel1::Update()
{
	/*int speed_backround = 4;
	int speed_tilemap = 5;

	if (background_w < 4961) {
		background_w -= speed_backround;
	}
	if (tilemap_w < 4961) {
		tilemap_w -= speed_tilemap;
	}*/

	int scrollSpeed = 2;

	App->player->position.x += 1;
	App->render->camera.x -= scrollSpeed;

	//Camera Diagonal Scroll. UNFINISHED.

	/*if (App->render->camera.x > 3040) 
	{
		App->render->camera.x -= scrollSpeed;
		App->render->camera.y -= scrollSpeed;
	}*/

	// Draw everything --------------------------------------
	App->render->Blit(backround, 0, 0, &background, 0.75f); // backround
	App->render->Blit(tilemap1, 0, 0, &ground, 1.0f); //tilemap
	

	if (App->input->keyboard[SDL_SCANCODE_SPACE])
	{
		App->fade->FadeToBlack(this, App->lvl2, 1);
		App->player->position.x = 100;
		App->player->position.y = 30;
	}
	return UPDATE_CONTINUE;
}

