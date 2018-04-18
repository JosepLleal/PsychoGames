#include "Globals.h"
#include "Application.h"
#include "ModuleLevel2.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleInput.h"
#include "ModuleLevel1.h"
#include "ModuleMenu.h"
#include "ModuleCredits.h"
#include "ModuleAudio.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"



ModuleLevel2::ModuleLevel2()
{
	// tilemap
	ground.x = 0;
	ground.y = 0;
	ground.w = 1323;
	ground.h = 513;

	//background 
	background.x = 0; 
	background.y = 0; 
	background.w = 1500; 
	background.h = 600; 
}

ModuleLevel2::~ModuleLevel2()
{}

// Load assets
bool ModuleLevel2::Start()
{
	LOG("Loading level 2 scene");
	bool ret = true;
	tilemap = App->textures->Load("image/LV2_Tilemap.png");
	graphics = App->textures->Load("image/LV2_Background.png"); 
	App->audio->MusicPlay("Sound/07_Babe_Good-Lookin_Stage_2_.ogg", 0.5f);

	App->player->Enable();
	App->particles->Enable();

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	//PLayer Initial Position
	App->player->position.x = 100;
	App->player->position.y = 30;

	App->collision->Enable(); 

	//MonsterCollision

	App->collision->AddCollider({ 263, 179, 347, 43 }, COLLIDER_WALL);
	App->collision->AddCollider({ 298, 222, 390, 13 }, COLLIDER_WALL);
	App->collision->AddCollider({ 330, 165, 200, 7 }, COLLIDER_WALL);
	App->collision->AddCollider({ 306, 172, 225, 7 }, COLLIDER_WALL);
	App->collision->AddCollider({ 427, 164, 127, 191 }, COLLIDER_WALL);
	App->collision->AddCollider({ 665, 254, 357, 94 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1037, 275, 156, 78 }, COLLIDER_WALL);
	App->collision->AddCollider({ 554, 235, 102, 111 }, COLLIDER_WALL);
	App->collision->AddCollider({ 407, 242, 33, 50 }, COLLIDER_WALL);
	App->collision->AddCollider({ 815, 182, 128, 72 }, COLLIDER_WALL);
	App->collision->AddCollider({ 943, 194, 76, 60 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1022, 250, 15, 100 }, COLLIDER_WALL);
	App->collision->AddCollider({ 850, 348, 197, 26 }, COLLIDER_WALL);
	App->collision->AddCollider({ 656, 253, 9, 92 }, COLLIDER_WALL);

	//ear 
	App->collision->AddCollider({ 350, 150, 51, 19 }, COLLIDER_WALL);

	//wing
	App->collision->AddCollider({ 554, 176, 104, 61 }, COLLIDER_WALL);
	App->collision->AddCollider({ 656, 201, 44, 53 }, COLLIDER_WALL);

	return ret;
}

// Load assets
bool ModuleLevel2::CleanUp()
{
	LOG("Unloading level 2 scene");

	App->player->Disable();
	App->textures->Unload(tilemap);
	App->textures->Unload(graphics);
	App->collision->Disable();
	App->lvl2->Disable();
	App->particles->Disable();

	return true; 
}

// Update: draw background
update_status ModuleLevel2::Update()
{

	int scrollSpeed = 2;

	
	App->player->position.x += 1; 
	App->render->camera.x += scrollSpeed;

	if (App->render->camera.x > 75 && App->render->camera.x < 150 && App->render->camera.y < 300)
	{
		App->render->camera.y += 1;
	}

	if (App->render->camera.x > 225 && App->render->camera.x < 300 && App->render->camera.y < 300)
	{
		App->render->camera.y -= 1;
	}

	if (App->render->camera.x > 337 && App->render->camera.x < 345 && App->render->camera.y < 300)
	{
		App->render->camera.y += 1;
	}

	if (App->render->camera.x > 360 && App->render->camera.x < 367 && App->render->camera.y < 300)
	{
		App->render->camera.y += 1;
	}

	if (App->render->camera.x > 382 && App->render->camera.x < 390 && App->render->camera.y < 300)
	{
		App->render->camera.y += 1;
	}

	if (App->render->camera.x > 675 && App->render->camera.x < 825 && App->render->camera.y < 300)
	{
		App->render->camera.y += scrollSpeed;
	}

	if (App->render->camera.x > 900 && App->render->camera.x < 975)
	{
		App->render->camera.y -= 1;
	}

	if (App->render->camera.x > 976 && App->render->camera.x < 990)
	{
		App->render->camera.y -= 1;
		App->render->camera.x -= 1;
	}

	if (App->render->camera.x > 1500 && App->render->camera.x < 1650)
	{
		App->render->camera.y += 1;
	}

	if (App->render->camera.x > 1800 && App->render->camera.x < 1950)
	{
		App->render->camera.y += 1;
		App->render->camera.x -= 1;
	}

	if (App->render->camera.x > 2200 && App->render->camera.x < 2203)
	{
		App->render->camera.y += 1;
		App->render->camera.x -= scrollSpeed;
		if (App->render->camera.y > 300) {
			App->render->camera.x = 2199;
		}
	}

	if (App->render->camera.x > 2000 && App->render->camera.x < 1800)
	{
		App->render->camera.y -= 1;
	}

	if (App->render->camera.x < 2200 && App->render->camera.x > 0 && App->render->camera.y > 300)
	{
		App->render->camera.x -= 4;
		App->player->position.x += 2;
	}

	if (App->render->camera.x > 900 && App->render->camera.x < 975 && App->render->camera.y > 300)
	{
		App->render->camera.y -= 1;
	}

	// Draw everything --------------------------------------	
	App->render->Blit(graphics, 0, 0, &background, 1);
	App->render->Blit(tilemap, (tilemap_w) / 3.5, 0, &ground, 1); //tilemap
	
	if (App->input->keyboard[SDL_SCANCODE_SPACE])
		App->fade->FadeToBlack(this, App->credit, 1);

	return UPDATE_CONTINUE;
}