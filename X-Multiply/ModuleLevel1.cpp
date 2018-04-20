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

	//TOP LARGER WALL
	App->collision->AddCollider({ 495, 0, 2000, 14 }, COLLIDER_WALL); //square of all the top wall 

	//BOTTOM LARGER WALL
	App->collision->AddCollider({ 0, 242, 2549, 15 }, COLLIDER_WALL);

	//TOP OBSTACLES
	App->collision->AddCollider({ 640, 14, 70, 14 }, COLLIDER_WALL); //1st 

	App->collision->AddCollider({ 761, 14, 57, 16 }, COLLIDER_WALL); //2nd 1
	App->collision->AddCollider({ 770, 30, 30, 16 }, COLLIDER_WALL); //2nd 2

	App->collision->AddCollider({ 1010, 14, 75, 27 }, COLLIDER_WALL); //3rd 1
	App->collision->AddCollider({ 1085, 14, 20, 15 }, COLLIDER_WALL); //3rd 2

	App->collision->AddCollider({ 1153, 14, 70, 14 }, COLLIDER_WALL); //4th 

	App->collision->AddCollider({ 1665, 14, 70, 16 }, COLLIDER_WALL); //After first entrance top

	App->collision->AddCollider({ 2425, 14, 57, 16 }, COLLIDER_WALL); //After biggest entrance 1 top
	App->collision->AddCollider({ 2430, 30, 30, 16 }, COLLIDER_WALL); //After biggest entrance 2 top



	App->collision->AddCollider({ 2917, 0, 122, 43 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3039, 43, 417, 33 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3145, 75, 408, 57 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3291, 130, 452, 33 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3397, 163, 414, 54 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3650, 217, 150, 51 }, COLLIDER_WALL);

	//BOTTOM OBSTACLES
	App->collision->AddCollider({ 414, 210, 30, 16 }, COLLIDER_WALL); //1st 1
	App->collision->AddCollider({ 408, 226, 57, 16 }, COLLIDER_WALL); //1st 2

	App->collision->AddCollider({ 495, 215, 104, 27 }, COLLIDER_WALL); //2nd

	App->collision->AddCollider({ 1024, 230, 70, 12 }, COLLIDER_WALL); //3rd

	App->collision->AddCollider({ 1263, 215, 104, 27 }, COLLIDER_WALL); //4th

	App->collision->AddCollider({ 1790, 210, 30, 16 }, COLLIDER_WALL); //After first entrance 1 bottom 
	App->collision->AddCollider({ 1784, 226, 57, 16 }, COLLIDER_WALL); //After first entrance 2 bottom

	App->collision->AddCollider({ 2549, 217, 318, 36 }, COLLIDER_WALL);

	App->collision->AddCollider({ 2657, 253, 225, 133 }, COLLIDER_WALL);

	// ----------------------------------------------------------------

	//First Entrance TOP
	App->collision->AddCollider({ 1430, 14, 120, 48 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1455, 62, 90, 50 }, COLLIDER_WALL);

	//First Entrance BOTTOM 
	App->collision->AddCollider({ 1430, 196, 120, 46 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1455, 148, 90, 48 }, COLLIDER_WALL);

	//Second Entrance TOP (biggest one)
	App->collision->AddCollider({ 2009, 14, 190, 48 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2040, 62, 150, 15 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2015, 77, 130, 34 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2199, 14, 20, 35 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2219, 14, 50, 8 }, COLLIDER_WALL); //smallest square 

	//Second Entrance BOTTOM (biggest one)
	App->collision->AddCollider({ 2015, 147, 130, 32 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2040, 179, 150, 15 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2009, 194, 190, 48 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2199, 207, 20, 35 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2219, 234, 50, 8 }, COLLIDER_WALL); //smallest square

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
	App->textures->Unload(hud);
	
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
		App->fade->FadeToBlack((Module*)App->lvl1, (Module*)App->lvl2, 1);
		
	}
	return UPDATE_CONTINUE;
}

