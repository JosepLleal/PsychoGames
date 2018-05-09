#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleFadeToBlack.h"
#include "ModuleMenu.h"
#include "ModuleGameOver.h"
#include "ModuleAudio.h"
#include "ModulePlayer.h"
#include "ModuleFonts.h"

#include <stdio.h>

ModuleGameOver::ModuleGameOver()
{}

ModuleGameOver::~ModuleGameOver()
{}

// Load assets
bool  ModuleGameOver::Start()
{
	LOG("Loading GameOver");

	background = App->textures->Load("image/Game_Over.png");
	App->audio->MusicPlay("Sound/16_Game_Over.ogg", 1.5f);

	App->render->camera.x = App->render->camera.y = 0;

	font_score = App->fonts->Load("Image/fonts.png", "0123456789ם.-=יט()ףעבת`´!?abcdefghijklmnopqrstuvwxyz", 2);

	score +=  + App->player->score;
	
	return true;
}

// UnLoad assets
bool  ModuleGameOver::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(background);

	return true;
}

// Update: draw background
update_status  ModuleGameOver::Update()
{
	App->render->Blit(background, (SCREEN_WIDTH/2)-80, (SCREEN_HEIGHT/2)-30, NULL);

	if ((App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN || App->input->controller[BUTTON_A] == KEY_DOWN) && App->fade->IsFading() == false)
	{
		App->fade->FadeToBlack(this, (Module*)App->menu);
	}

	// Draw UI (score) ------------------------------------------------
	sprintf_s(score_text, 10, "%7d", score);
	App->fonts->BlitText(140, 180, font_score, score_text);
	App->fonts->BlitText(100, 150, font_score, "total score");

	return UPDATE_CONTINUE;
}