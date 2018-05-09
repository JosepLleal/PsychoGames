#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModulePowerUp.h"
#include "ModuleLevel5.h"
#include "ModuleAudio.h"

ModuleLevel5::ModuleLevel5()
{
	// tilemap
	ground_parallax.x = 0;
	ground_parallax.y = 0;
	ground_parallax.w = 4608;
	ground_parallax.h = 256;

	// Background 
	background_parallax.x = 0;
	background_parallax.y = 0;
	background_parallax.w = 4608;
	background_parallax.h = 256;
}

ModuleLevel5::~ModuleLevel5()
{}

// Load assets
bool ModuleLevel5::Start()
{
	LOG("Loading space scene");

	background = App->textures->Load("image/Tilemap/Backround_lvl5.png");
	tilemap1 = App->textures->Load("image/Tilemap/LV5_Tilemap.png");
	hud = App->textures->Load("image/xmultiply_hud.png");

	App->audio->MusicPlay("Sound/11_Bloody_Bloom_Stage_5_.ogg", 0.5f);

	App->player->Enable();
	App->particles->Enable();
	App->collision->Enable();
	App->enemies->Enable();
	App->powerup->Enable();

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	//-----------------------------------------//
	//				COLLIDER_WALL			   //
	//-----------------------------------------//

	//TOP ALL LEVEL 
	App->collision->AddCollider({ 241, 0, 48, 18 }, COLLIDER_WALL);
	App->collision->AddCollider({ 340, 0, 2690, 18 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3080, 0, 1550, 24 }, COLLIDER_WALL);

	//TOP COLUMNS 
	App->collision->AddCollider({ 257, 18, 15, 72}, COLLIDER_WALL);
	App->collision->AddCollider({ 353, 18, 15, 55 }, COLLIDER_WALL);
	App->collision->AddCollider({ 545, 18, 14, 55 }, COLLIDER_WALL);
	App->collision->AddCollider({ 898, 18, 15, 36 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1009, 18, 15, 55 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1073, 18, 16, 92 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1105, 18, 15, 55 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1153, 18, 15, 55 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1185, 18, 16, 92 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1329, 18, 15, 55 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1569, 18, 15, 55 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1601, 18, 16, 92 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1761, 18, 15, 36 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1905, 18, 15, 55 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2402, 18, 15, 72 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2498, 18, 15, 36 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2577, 18, 15, 92 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2610, 18, 15, 55 }, COLLIDER_WALL);
	
	//TOP SQUARES 
	App->collision->AddCollider({ 1977, 18, 80, 45 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2147, 18, 110, 18 }, COLLIDER_WALL);

	//BOTTOM ALL LEVEL 
	App->collision->AddCollider({ 200, 238, 2201, 18 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2417, 238, 280, 18 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2721, 238, 112, 18 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2881, 238, 112, 18 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3080, 232, 1550, 24 }, COLLIDER_WALL);

	//BOTTOM COLUMNS
	App->collision->AddCollider({ 209, 183, 15, 55 }, COLLIDER_WALL);
	App->collision->AddCollider({ 369, 183, 15, 55 }, COLLIDER_WALL);
	App->collision->AddCollider({ 450, 202, 15, 36 }, COLLIDER_WALL);
	App->collision->AddCollider({ 640, 166, 15, 72 }, COLLIDER_WALL);
	App->collision->AddCollider({ 802, 202, 15, 36 }, COLLIDER_WALL);
	App->collision->AddCollider({ 930, 202, 15, 36 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1266, 166, 15, 72 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1409, 183, 15, 55 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1681, 202, 15, 36 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1841, 202, 15, 36 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1920, 183, 15, 55 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2033, 146, 15, 92 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2081, 202, 15, 36 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2143, 126, 15, 112 }, COLLIDER_WALL);//4 Columns
	App->collision->AddCollider({ 2158, 183, 19, 55 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2177, 126, 15, 112 }, COLLIDER_WALL);//4 Columns
	App->collision->AddCollider({ 2192, 163, 18, 75 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2210, 126, 15, 112 }, COLLIDER_WALL);//4 Columns
	App->collision->AddCollider({ 2225, 153, 15, 85 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2240, 126, 15, 112 }, COLLIDER_WALL);//4 Columns

	//HUD hitbox
	HUDhitbox = App->collision->AddCollider({ 0, 0, SCREEN_WIDTH, 3 }, COLLIDER_HUD, this);

	//PowerUps
	App->powerup->AddPowerUp(POWERUP_TYPES::SPEED_UP, 750, 100);
	App->powerup->AddPowerUp(POWERUP_TYPES::POWERUP_ENEMY, 750, 87);

	//Bomb
	App->powerup->AddPowerUp(POWERUP_TYPES::BOMB, 1000, 133);
	App->powerup->AddPowerUp(POWERUP_TYPES::POWERUP_ENEMY, 1000, 120);

	return true;
}

// UnLoad assets
bool ModuleLevel5::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(background);
	App->textures->Unload(tilemap1);
	App->textures->Unload(hud);

	App->enemies->Disable();
	App->collision->Disable();
	App->particles->Disable();
	App->player->Disable();
	App->powerup->Disable();

	return true;
}

// Update: draw background
update_status ModuleLevel5::Update()
{
	// Move camera forward -----------------------------
	if (App->render->camera.x < 4219)
	{
		App->render->camera.x += 1 * SCREEN_SIZE;
		App->player->position.x += 1; 
	}

	HUDhitbox->SetPos((App->render->camera.x)/1 , App->render->camera.y + 257);

	// Draw everything --------------------------------------
	App->render->Blit(background, 0, 0, &background_parallax, 0.75f, true); // backround
	App->render->Blit(tilemap1, 0, 0, &ground_parallax, 1.0f, true);
	App->render->Blit(hud, 0, 257, NULL, 0.0f, false);

	return UPDATE_CONTINUE;
}