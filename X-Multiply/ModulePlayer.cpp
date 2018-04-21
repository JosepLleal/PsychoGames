#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleFadeToBlack.h"
#include "ModuleFonts.h"
#include "ModulePlayer.h"
#include "ModuleAudio.h"

#include<stdio.h>


ModulePlayer::ModulePlayer()
{
	// idle animation (just the ship)
	idle.PushBack({ 100, 0, 38, 16 });

	// go upward animation 
	upward.PushBack({ 52, 0, 38, 16 });
	upward.PushBack({ 4, 0, 38, 16 });
	upward.loop = false;
	upward.speed = 0.1f;

	// Move down
	downward.PushBack({ 148, 0, 38, 16 });
	downward.PushBack({ 196, 0, 38, 16 });
	downward.loop = false;
	downward.speed = 0.1f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	graphics = App->textures->Load("Image/Main_Character_Effects.png");

	shot = App->audio->LoadFX("Sound/xmultipl-122.wav"); //Loading FX of shot
	death = App->audio->LoadFX("Sound/xmultipl-044.wav"); //Loading FX when player dies

	destroyed = false;
	godmode = false;
	
	position.x = 150;
	position.y = 120;
	score = 0;

	playerHitbox = App->collision->AddCollider({ position.x, position.y, 7, 6 }, COLLIDER_PLAYER, this);

	// X-Multiply font
	font_score = App->fonts->Load("image/fonts_xmultiply2.png", "0123456789ם.-=יט()ףעבת`´!?abcdefghijklmnopqrstuvwxyz", 2);


	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);
	App->fonts->UnLoad(font_score);

	//Unloading FX
	App->audio->UnloadFX(shot);
	App->audio->UnloadFX(death);

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	//position.x += 1; // Automatic movement

	if(App->player->lives>=0)
	{

		int speed = 1;

		if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
		{
			position.x -= speed * 2;
		}

		if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
		{
			position.x += speed * 2;
		}

		if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
		{
			position.y += speed * 2;
			if (current_animation != &downward)
			{
				downward.Reset();
				current_animation = &downward;
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT)
		{
			position.y -= speed * 2;
			if (current_animation != &upward)
			{
				upward.Reset();
				current_animation = &upward;
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
		{
			App->particles->AddParticle(App->particles->shot, position.x + 28, position.y + 6, COLLIDER_PLAYER_SHOT);
			App->audio->ChunkPlay(shot);

		}

		if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_IDLE)
			current_animation = &idle;

		// Camera Limits
		//X Limits:
		if (position.x <= abs(App->render->camera.x) / SCREEN_SIZE)
		{
			position.x = 1 + (abs(App->render->camera.x) / SCREEN_SIZE);
		}
		else if (position.x >= ((abs(App->render->camera.x) / SCREEN_SIZE + SCREEN_WIDTH - 38)))
		{
			position.x = -1 + ((abs(App->render->camera.x) / SCREEN_SIZE + SCREEN_WIDTH - 38));
		}

		//Y Limits:

		if (position.y <= abs(App->render->camera.y) / SCREEN_SIZE)
		{
			position.y = 1 + abs(App->render->camera.y) / SCREEN_SIZE;
		}
		else if (position.y >= (abs(App->render->camera.y) / SCREEN_SIZE) + SCREEN_HEIGHT - 45)
		{
			position.y = -1 + (abs(App->render->camera.y) / SCREEN_SIZE) + SCREEN_HEIGHT - 45;
		}

		//If end level go to STAGE CLEARED
		if (App->render->camera.x == 9150)
		{
			App->fade->FadeToBlack((Module*)App->lvl1, (Module*)App->stage_cleared);
		}


	}

	//GOD MODE FUNCTION ---------------------------------------------------------------------------------------------------
	if (App->player->lives >= 0)
	{
		if (App->input->keyboard[SDL_SCANCODE_F5] == KEY_DOWN)
		{
			godmode = !godmode;

			if (godmode == true)
			{
				LOG("GodMode on");
				playerHitbox->to_delete = true;
				playerHitbox = nullptr;
			}
			else if (godmode == false)
			{
				LOG("GodMode off");
				playerHitbox = App->collision->AddCollider({ position.x, position.y, 36, 16 }, COLLIDER_PLAYER, this);
			}
		}
		if (godmode == false)
			playerHitbox->SetPos(position.x + 9, position.y + 5);

		if (App->input->keyboard[SDL_SCANCODE_F3] == KEY_STATE::KEY_DOWN && App->fade->IsFading() == false)
		{
			App->audio->ChunkPlay(death);
			App->particles->AddParticle(App->particles->player_death, position.x, position.y, COLLIDER_NONE);
			App->player->Disable();
			App->fade->FadeToBlack((Module*)App->lvl1, (Module*)App->game_over);
		}
	}

	//-----------------------------------------------------------------------------------------------------------------------

	if(destroyed == false)
		App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()), true);
	
	// Draw UI (score) -------------------------------------------------
	sprintf_s(score_text, 10, "%7d", score);

	// TODO 3: Blit the text of the score in at the bottom of the screen
	App->fonts->BlitText(70, 273, font_score, score_text);
	App->fonts->BlitText(35, 273, font_score, "1");
	App->fonts->BlitText(43, 273, font_score, "up");
	App->fonts->BlitText(145, 273, font_score, "top");
	//------------------------------------------------------------------


	return UPDATE_CONTINUE;
}

void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	if(c1 == playerHitbox && destroyed == false && App->fade->IsFading() == false)
	{
		App->particles->AddParticle(App->particles->player_death, position.x, position.y, COLLIDER_NONE);
		App->audio->ChunkPlay(death);
		if (App->player->lives > 0)
		{
			LOG("Lives -1");
			App->player->lives -= 1;
			App->fade->FadeToBlack((Module*)App->lvl1, (Module*)App->lvl1);
		}
		if (App->player->lives == 0)
		{
			App->fade->FadeToBlack((Module*)App->lvl1, (Module*)App->game_over, 2.0f);
			
		}
		
		playerHitbox->to_delete = true;
		destroyed = true;
	}
}