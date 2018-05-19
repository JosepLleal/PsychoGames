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
	diamond = App->textures->Load("image/LV5_diamond.png");

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
	App->collision->AddCollider({ 257, 18, 15, 72 }, COLLIDER_WALL);
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

	//BOTTOM FIXES
	App->collision->AddCollider({ 224, 214, 15, 24 }, COLLIDER_WALL);
	App->collision->AddCollider({ 354, 226, 15, 12 }, COLLIDER_WALL);
	App->collision->AddCollider({ 384, 214, 15, 24 }, COLLIDER_WALL);
	App->collision->AddCollider({ 502, 228, 20, 10 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1424, 214, 15, 24 }, COLLIDER_WALL);

	//BOTTOM BOXES 
	App->collision->AddCollider({ 294, 228, 20, 10 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1030, 228, 20, 10 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1096, 228, 20, 10 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1159, 228, 20, 10 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1224, 228, 20, 10 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1336, 228, 20, 10 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1368, 228, 20, 10 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1464, 228, 80, 10 }, COLLIDER_WALL);

	//COllider for Diamond animation
	App->collision->AddCollider({ 708, 90, 1, 30 }, COLLIDER_NONE);
    App->collision->AddCollider({ 1102, 80, 1, 40 }, COLLIDER_NONE);

	//Diamonds
	/*App->enemies->AddEnemy(ENEMY_TYPES::DIAMOND_WALL, 700, 90);
	App->enemies->AddEnemy(ENEMY_TYPES::DIAMOND_WALL, 1094, 80);
	App->enemies->AddEnemy(ENEMY_TYPES::DIAMOND_WALL, 1630, 18);*/

	
	//GOOD POSITION
	App->enemies->AddEnemy(ENEMY_TYPES::YELLOWBALL, 320, 202);
	App->enemies->AddEnemy(ENEMY_TYPES::YELLOWBALL2, 450, 30);
	App->enemies->AddEnemy(ENEMY_TYPES::YELLOWBALL2, 510, 25);
	App->enemies->AddEnemy(ENEMY_TYPES::YELLOWBALL, 575, 202);
	App->enemies->AddEnemy(ENEMY_TYPES::YELLOWBALL2, 625, 25);
	App->enemies->AddEnemy(ENEMY_TYPES::YELLOWBALL2, 673, 20);
	App->enemies->AddEnemy(ENEMY_TYPES::YELLOWBALL2, 735, 20);
	App->enemies->AddEnemy(ENEMY_TYPES::YELLOWBALL, 735, 202);

	App->enemies->AddEnemy(ENEMY_TYPES::REDBALL2, 250, 68);
	App->enemies->AddEnemy(ENEMY_TYPES::REDBALL, 235, 85);
	App->enemies->AddEnemy(ENEMY_TYPES::REDBALL1, 245, 103);
	App->enemies->AddEnemy(ENEMY_TYPES::REDBALL3, 270, 86);

	App->enemies->AddEnemy(ENEMY_TYPES::REDBALL4, 300, 130);
	App->enemies->AddEnemy(ENEMY_TYPES::REDBALL4, 273, 198);
	App->enemies->AddEnemy(ENEMY_TYPES::REDBALL1, 337, 179 );

	App->enemies->AddEnemy(ENEMY_TYPES::REDBALL5, 334, 55);
	App->enemies->AddEnemy(ENEMY_TYPES::REDBALL, 328, 85);
	App->enemies->AddEnemy(ENEMY_TYPES::REDBALL2, 345, 80);
	App->enemies->AddEnemy(ENEMY_TYPES::REDBALL3, 360, 70);

	App->enemies->AddEnemy(ENEMY_TYPES::REDBALL, 420, 185);
	App->enemies->AddEnemy(ENEMY_TYPES::REDBALL1, 435, 179);

	App->enemies->AddEnemy(ENEMY_TYPES::REDBALL3, 515, 50);
	App->enemies->AddEnemy(ENEMY_TYPES::REDBALL5, 528, 70);
	App->enemies->AddEnemy(ENEMY_TYPES::REDBALL, 530, 90);
	App->enemies->AddEnemy(ENEMY_TYPES::REDBALL2, 545, 80);
	App->enemies->AddEnemy(ENEMY_TYPES::REDBALL3, 550, 100);

	App->enemies->AddEnemy(ENEMY_TYPES::REDBALL, 624, 160);
	App->enemies->AddEnemy(ENEMY_TYPES::REDBALL4, 590, 160);

	App->enemies->AddEnemy(ENEMY_TYPES::REDBALL, 700, 50);
	App->enemies->AddEnemy(ENEMY_TYPES::REDBALL4, 725, 60);
		

	//HUD hitbox
	HUDhitbox = App->collision->AddCollider({ 0, 0, SCREEN_WIDTH, 3 }, COLLIDER_HUD, this);

	//PowerUps
	//App->powerup->AddPowerUp(POWERUP_TYPES::SPEED_UP, 750, 100);
	//App->powerup->AddPowerUp(POWERUP_TYPES::POWERUP_ENEMY, 750, 87);

	//Bomb
	/*App->powerup->AddPowerUp(POWERUP_TYPES::BOMB, 750, 123);
	App->powerup->AddPowerUp(POWERUP_TYPES::POWERUP_ENEMY, 750, 110);*/

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