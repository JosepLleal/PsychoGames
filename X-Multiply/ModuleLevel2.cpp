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



ModuleLevel2::ModuleLevel2()
{
	// tilemap
	ground.x = 0;
	ground.y = 0;
	ground.w = 1323;
	ground.h = 513;


}

ModuleLevel2::~ModuleLevel2()
{}

// Load assets
bool ModuleLevel2::Start()
{
	LOG("Loading level 2 scene");
	bool ret = true;
	tilemap = App->textures->Load("image/LV2_Tilemap.png");
	App->audio->MusicPlay("Sound/07_Babe_Good-Lookin_Stage_2_.ogg", 0.5f);
	App->player->Enable();

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
}

// Load assets
bool ModuleLevel2::CleanUp()
{
	LOG("Unloading level 2 scene");
	App->player->Disable();
	App->textures->Unload(tilemap);
	return true;
}

// Update: draw background
update_status ModuleLevel2::Update()
{

	int scrollSpeed = 2;

	App->player->position.x += 1; 
	App->render->camera.x -= scrollSpeed;

	if (App->render->camera.x < -100 && App->render->camera.x > -200 && App->render->camera.y > -400)
	{
		App->render->camera.y -= 1;
	} 

	if (App->render->camera.x < -300 && App->render->camera.x > -400 && App->render->camera.y > -400)
	{
		App->render->camera.y += 1;
	}

	if (App->render->camera.x < -450 && App->render->camera.x > -460 && App->render->camera.y > -400)
	{
		App->render->camera.y -= 1;
	}

	if (App->render->camera.x < -480 && App->render->camera.x > -490 && App->render->camera.y > -400)
	{
		App->render->camera.y -= 1;
	}

	if (App->render->camera.x < -510 && App->render->camera.x > -520 && App->render->camera.y > -400 )
	{
		App->render->camera.y -= 1;
	}

	if (App->render->camera.x < -900 && App->render->camera.x > -1100 && App->render->camera.y > -400)
	{
		App->render->camera.y -= scrollSpeed;
	}

	if (App->render->camera.x < -1200 && App->render->camera.x > -1300)
	{
		App->render->camera.y += 1;
	}

	if (App->render->camera.x < -1301 && App->render->camera.x > -1320)
	{
		App->render->camera.y += 1;
		App->render->camera.x += 1;
	}

	if (App->render->camera.x < -2000 && App->render->camera.x > -2200)
	{
		App->render->camera.y -= 1;
	}

	if (App->render->camera.x < -2400 && App->render->camera.x > -2600)
	{
		App->render->camera.y -= 1;
		App->render->camera.x += 1;
	}

	if (App->render->camera.x < -2900 && App->render->camera.x > -2903)
	{
		App->render->camera.y -= 1;
		App->render->camera.x += scrollSpeed;
		if (App->render->camera.y < -400) {
			App->render->camera.x = -2899;
		}
	}

	if (App->render->camera.x > -2900 && App->render->camera.x < 0 && App->render->camera.y < -400)
	{
		App->render->camera.x += 4; 
		App->player->position.x -= 2; 
	}

	if (App->render->camera.x < -1200 && App->render->camera.x > -1300 && App->render->camera.y < -400)
	{
		App->render->camera.y += 1;
	}

	// Draw everything --------------------------------------	
	App->render->Blit(tilemap, (tilemap_w) / 3.5, 0, &ground, 0.75f); //tilemap

	if (App->input->keyboard[SDL_SCANCODE_SPACE])
		App->fade->FadeToBlack(this, App->credit, 1);

	return UPDATE_CONTINUE;
}