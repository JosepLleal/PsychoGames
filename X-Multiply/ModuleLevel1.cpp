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
#include "ModuleParticles.h"
#include "ModuleEnemies.h"


ModuleLevel1::ModuleLevel1()
{
	// tilemap
	ground.x = 0;
	ground.y = 1;
	ground.w = 4961;
	ground.h = 587;

	// Background 
	background.x = 0;
	background.y = 0;
	background.w = 4961;
	background.h = 587;
}

ModuleLevel1::~ModuleLevel1()
{}

// Load assets
bool ModuleLevel1::Start()
{
	LOG("Loading level 1 scene");
	
	backround = App->textures->Load("image/background completed.png");
	tilemap1 = App->textures->Load("image/LV1_TilemapCompleted.png");
	hud = App->textures->Load("image/xmultiply_hud.png");

	App->audio->MusicPlay("Sound/04_Into_the_Human_Body_Stage_1_.ogg", 0.5f);
    App->render->camera.x = 0;
	App->render->camera.y = 0;
	
	App->player->Enable();
	App->particles->Enable();
	App->enemies->Enable(); 
	App->collision->Enable();

	//Player Initial position
	App->player->position.x = 100;
	App->player->position.y = 30;

	//TOP WALLS. FIRST WALLS = UPPER

	App->collision->AddCollider({ 495, 0, 2100, 12 }, COLLIDER_WALL);
	App->collision->AddCollider({ 640, 12, 70, 12 }, COLLIDER_WALL);
	App->collision->AddCollider({ 761, 12, 57, 29 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1005, 12, 104, 25 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1153, 12, 70, 12 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1665, 12, 70, 12 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2427, 12, 64, 29 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2917, 0, 122, 42 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3039, 41, 417, 32 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3145, 73, 408, 56 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3291, 128, 452, 32 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3397, 161, 414, 53 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3650, 215, 150, 50 }, COLLIDER_WALL);


	//BOTTOM WALLS. FIRST WALLS = UPPER
	App->collision->AddCollider({ 0, 213, 2549, 12 }, COLLIDER_WALL);
	App->collision->AddCollider({ 405, 183, 63, 30 }, COLLIDER_WALL);
	App->collision->AddCollider({ 495, 188, 104, 25 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1024, 201, 70, 12 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1263, 188, 104, 25 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2549, 188, 318, 36 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2657, 224, 225, 133 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1788, 183, 63, 30 }, COLLIDER_WALL);

	// ----------------------------------------------------------------

	//First Entrance TOP
	App->collision->AddCollider({ 1430, 12, 120, 48 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1460, 60, 90, 36 }, COLLIDER_WALL);

	//First Entrance BOTTOM 
	App->collision->AddCollider({ 1430, 165, 120, 48 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1460, 129, 90, 36 }, COLLIDER_WALL);

	//Second Entrance TOP (biggest one)
	App->collision->AddCollider({ 2009, 12, 190, 48 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2009, 60, 140, 36 }, COLLIDER_WALL);

	//Second Entrance BOTTOM (biggest one)
	App->collision->AddCollider({ 2009, 129, 140, 36 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2009, 165, 190, 48 }, COLLIDER_WALL);

	//Before Scroll
	App->collision->AddCollider({ 2710, 165, 53, 23 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2800, 178, 40, 10 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2882, 247, 105, 73 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2987, 275, 76, 45 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3040, 320, 172, 170 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3212, 354, 72, 137 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3284, 375, 94, 117 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3378, 427, 177, 64 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3552, 461, 131, 53 }, COLLIDER_WALL);

	//After Scroll TOP
	App->collision->AddCollider({ 3800, 257, 1200, 12 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4333, 269, 104, 25 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3725, 257, 177, 69 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3900, 265, 89, 30 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3821, 329, 40, 10 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4493, 267, 129, 33 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4526, 300, 90, 53 }, COLLIDER_WALL);

	//After Scroll BOTTOM
	App->collision->AddCollider({ 3675, 470, 1300, 12 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3953, 445, 104, 25 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4225, 458, 70, 12 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4345, 440, 63, 30 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4493, 437, 129, 33 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4526, 384, 90, 53 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4790, 470, 40, 10 }, COLLIDER_WALL);
	
	//Shrimp --- 
	
	App->enemies->AddEnemy(ENEMY_TYPES::SHRIMP, 500, 30);
	App->enemies->AddEnemy(ENEMY_TYPES::SHRIMP, 600, 50);
	//App->enemies->AddEnemy(ENEMY_TYPES::SHRIMP, 700, 50);
	

	return true;
}

// UnLoad assets
bool ModuleLevel1::CleanUp()
{
	LOG("Unloading level 1 scene");
	App->player->Disable();
	App->enemies->Disable(); 
	App->particles->Disable();
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
	App->render->camera.x += scrollSpeed;

	if (App->render->camera.x > 5300 && App->render->camera.x < 6835)
	{
		if (App->render->camera.x % 3 == 0)
		{
			App->render->camera.y += 2;
		}
	}

	//Camera Diagonal Scroll. UNFINISHED.

	/*if (App->render->camera.x > 3040) 
	{
		App->render->camera.x -= scrollSpeed;
		App->render->camera.y -= scrollSpeed;
	}*/

	// Draw everything --------------------------------------
	App->render->Blit(backround, 0, 0, &background, 0.75f, true); // backround
	App->render->Blit(tilemap1, 0, 0, &ground, 1.0f, true); //tilemap
	App->render->Blit(hud, 0, 257, NULL, 0.0f, false); // hud
	

	if (App->input->keyboard[SDL_SCANCODE_SPACE])
	{
		App->fade->FadeToBlack(this, App->lvl2, 1);
		
	}
	return UPDATE_CONTINUE;
}

