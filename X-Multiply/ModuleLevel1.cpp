#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModulePowerUp.h"
#include "ModuleLevel1.h"
#include "ModuleAudio.h"

ModuleLevel1::ModuleLevel1()
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

ModuleLevel1::~ModuleLevel1()
{}

// Load assets
bool ModuleLevel1::Start()
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
bool ModuleLevel1::CleanUp()
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
update_status ModuleLevel1::Update()
{
	// Move camera forward -----------------------------
	if (App->render->camera.x < 4219)
	{
		App->render->camera.x += 1 * SCREEN_SIZE;
		App->player->position.x += 1; 
	}

	HUDhitbox->SetPos((App->render->camera.x)/2 , App->render->camera.y + 257);

	// Draw everything --------------------------------------
	App->render->Blit(background, 0, 0, &background_parallax, 0.75f, true); // backround
	App->render->Blit(tilemap1, 0, 0, &ground_parallax, 1.0f, true);
	App->render->Blit(hud, 0, 257, NULL, 0.0f, false);

	return UPDATE_CONTINUE;
}