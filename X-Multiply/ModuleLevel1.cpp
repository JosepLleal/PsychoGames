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
#include "ModuleEnemies.h"


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
	App->enemies->Enable(); 
	App->collision->Enable();

	//TOP WALLS. FIRST WALLS = UPPER
	
	App->collision->AddCollider({ 495, 0, 2547, 12 }, COLLIDER_WALL);
	App->collision->AddCollider({ 640, 12, 70, 12 }, COLLIDER_WALL);
	App->collision->AddCollider({ 761, 12, 57, 29 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1005, 12, 104, 25 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1153, 12, 70, 12 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1423, 12, 138, 84 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1665, 12, 70, 12 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2009, 12, 213, 84 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2427, 12, 64, 29 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2917, 0, 122, 42 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3039, 41, 417, 32 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3145, 73, 408, 56 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3291, 128, 452, 32 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3397, 161, 414, 53 }, COLLIDER_WALL);
	//App->collision->AddCollider({ 3679, 215, 414, 53 }, COLLIDER_WALL); wrong
	

	//BOTTOM WALLS. FIRST WALLS = UPPER
	App->collision->AddCollider({ 0, 213, 2549, 12 }, COLLIDER_WALL);
	App->collision->AddCollider({ 405, 183, 63, 30 }, COLLIDER_WALL);
	App->collision->AddCollider({ 495, 188, 104, 25 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1024, 201, 70, 12 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1263, 188, 104, 25 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1423, 129, 138, 84 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1788, 183, 63, 30 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2009, 129, 213, 84 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2549, 188, 318, 36 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2657, 188, 225, 133 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2882, 247, 105, 73 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2987, 275, 76, 45 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3040, 320, 172, 170 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3212, 354, 72, 137 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3284, 375, 94, 117 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3378, 427, 177, 64 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3552, 461, 131, 53 }, COLLIDER_WALL);
	
	//Shrimp --- 
	App->enemies->AddEnemy(ENEMY_TYPES::SHRIMP, 600, 80);
	App->enemies->AddEnemy(ENEMY_TYPES::SHRIMP, 625, 80);
	App->enemies->AddEnemy(ENEMY_TYPES::SHRIMP, 640, 80);
	App->enemies->AddEnemy(ENEMY_TYPES::SHRIMP, 665, 80);

	return true;
}

// UnLoad assets
bool ModuleLevel1::CleanUp()
{
	LOG("Unloading level 1 scene");
	App->player->Disable();
	App->enemies->Disable(); 
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

	if(App->render->camera.x < -6100 && App->render->camera.x > -7000) 
	{
		App->render->camera.y -= 1; 
	}

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

