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

//include POWERUPS---------
#include "PowerUp_SpeedUp.h"
//--------------------------
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

	//SpeedUp PowerUp
	speedboost.PushBack({ 11,167,42,14 });
	speedboost.PushBack({ 58,166,42,14 });
	speedboost.PushBack({ 102,168,42,14 });
	speedboost.PushBack({ 58,166,42,14 });
	speedboost.PushBack({ 102,168,42,14 });
	speedboost.PushBack({ 58,166,42,14 });
	speedboost.PushBack({ 102,168,42,14 });
	speedboost.PushBack({ 58,166,42,14 });
	speedboost.PushBack({ 102,168,42,14 });
	speedboost.loop = true;
	speedboost.speed = 0.2f;

	//tentacles
	tentacles.PushBack({ 90, 19, 19, 8 });
	tentacles.PushBack({ 122, 19, 19, 7 });
	tentacles.PushBack({ 154, 19, 19, 6 });
	tentacles.PushBack({ 185, 20, 19, 7 });
	tentacles.PushBack({ 10, 34, 19, 10 });
	tentacles.loop = true;
	tentacles.speed = 0.06f;

}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	graphics = App->textures->Load("Image/Main_Character_Effects.png");
	live = App->textures->Load("Image/Lives.png"); 

	shot = App->audio->LoadFX("Sound/xmultipl-122.wav"); //Loading FX of shot
	laser = App->audio->LoadFX("Sound/xmultipl-121.wav"); //Loading FX of laser
	death = App->audio->LoadFX("Sound/xmultipl-044.wav"); //Loading FX when player dies

	destroyed = false;
	godmode = false;
	speedup_anim = false;
	Bomb = false;
	Laser = false; 

	idle_movement = true;
	
	
	position.x = 100;
	position.y = 120;

	tent1_pos.y = position.y - 25;
	tent2_pos.y = position.y + 25;

	App->render->camera.x = 0;
	App->render->camera.y = 0;
	frame = 0;
	

	playerHitbox = App->collision->AddCollider({ position.x, position.y, 7, 6 }, COLLIDER_PLAYER, this);
	t1 = App->collision->AddCollider({ tent1_pos.x, tent1_pos.y, 19, 7 }, COLLIDER_TENTACLES);
	t2 = App->collision->AddCollider({ tent2_pos.x, tent2_pos.y, 19, 7 }, COLLIDER_TENTACLES);

	// X-Multiply font
	font_score = App->fonts->Load("image/fonts_xmultiply2.png", "0123456789ם.-=יט()ףעבת`´!?abcdefghijklmnopqrstuvwxyz", 2);


	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);
	App->textures->Unload(live);
	App->fonts->UnLoad(font_score);

	Speedup = false;

	//Unloading FX
	App->audio->UnloadFX(shot);
	App->audio->UnloadFX(laser);
	App->audio->UnloadFX(death);

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	//tentacles position
	

	t1->SetPos(tent1_pos.x, tent1_pos.y);
	t2->SetPos(tent2_pos.x, tent2_pos.y);
	if ( (forward == false && backward == false) || (forward == true && backward == true))
	{
		if (frame < 0) { frame+=1; }
		else if (frame > 0) { frame-=1; }
	
	}
	else if (forward == true)
	{
		frame+=2;
		if (frame > 32) { frame = 32; }

	}
	else if (backward == true)
	{
		frame-=2;
		if (frame < -32) { frame = -32; }
		
	}

	// ---------- DIFFERENT TENTACLES POSITION ------------------------
	if (frame == 0)
	{
		tent1_pos.y = position.y - 35;
		tent2_pos.y = position.y + 45;
		tent1_pos.x = position.x + 12;
		tent2_pos.x = position.x + 12;
	}
	else if (frame >= -8 && frame < 0)
	{
		tent1_pos.y = position.y - 25;
		tent2_pos.y = position.y + 35;
		tent1_pos.x = position.x + 24;
		tent2_pos.x = position.x + 24;
	}
	else if (frame >= -16 && frame < -8)
	{
		tent1_pos.y = position.y - 15;
		tent2_pos.y = position.y + 25;
		tent1_pos.x = position.x + 35;
		tent2_pos.x = position.x + 35;
	}
	else if (frame >= -24 && frame < -16)
	{
		tent1_pos.y = position.y - 5;
		tent2_pos.y = position.y + 15;
		tent1_pos.x = position.x + 40;
		tent2_pos.x = position.x + 40;
	}
	else if (frame >= -32 && frame < -16)
	{
		tent1_pos.y = position.y + 5;
		tent2_pos.y = position.y + 5;
		tent1_pos.x = position.x + 45;
		tent2_pos.x = position.x + 45;
	}
	else if (frame <= 8 && frame > 0)
	{
		tent1_pos.y = position.y - 25;
		tent2_pos.y = position.y + 35;
		tent1_pos.x = position.x + 0;
		tent2_pos.x = position.x + 0;
	}
	else if (frame <= 16 && frame > 8)
	{
		tent1_pos.y = position.y - 15;
		tent2_pos.y = position.y + 25;
		tent1_pos.x = position.x - 25;
		tent2_pos.x = position.x - 25;
	}
	else if (frame <=24 && frame > 16)
	{
		tent1_pos.y = position.y - 5;
		tent2_pos.y = position.y + 15;
		tent1_pos.x = position.x - 30;
		tent2_pos.x = position.x - 30;
	}
	else if (frame <= 32 && frame > 24)
	{
		tent1_pos.y = position.y + 5;
		tent2_pos.y = position.y + 5;
		tent1_pos.x = position.x - 35;
		tent2_pos.x = position.x - 35;
	}
	//------------------------------------------------------------------
	if (destroyed == false)
	{
		App->render->Blit(graphics, tent1_pos.x, tent1_pos.y, &(tentacles.GetCurrentFrame()));
		App->render->Blit(graphics, tent2_pos.x, tent2_pos.y, &(tentacles.GetCurrentFrame()));
	}




	if (speedup_anim == true) {
		if (counter < 70) {
			App->render->Blit(graphics, position.x - 40, position.y + 2, &(speedboost.GetCurrentFrame()));
			counter++;
		}
		else
		{
			counter = 0;
			speedup_anim = false;
		}
		
	}

	if(App->player->lives>=0)
	{
		if (App->input->keyboard[SDL_SCANCODE_F6] == KEY_STATE::KEY_REPEAT)
		{
			Speedup = true;
		}
		float speed = 0;
		//PowerUp SpeedUp -----------------------------------
		if (Speedup == true) {
			speed = 3.0f;
		}
		else
		{
			speed = 2.0f;
		}
		//---------------------------------------------------

		if (App->input->keyboard[SDL_SCANCODE_F7] == KEY_STATE::KEY_REPEAT)
		{
			Bomb = true;
		}
		//PowerUp Bomb ---------------------------------------------------------------------------------------------------

		if (Bomb == true)
		{
			if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN && destroyed == false && cooldown == 3)
			{
				App->particles->AddParticle(App->particles->bomb, position.x + 28, position.y + 3, COLLIDER_BOMB);
				cooldown = 0;
			}
		}
		//----------------------------------------------------------------------------------------------------------------

		if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT || App->input->controller[LEFT] == KEY_STATE::KEY_REPEAT )
		{
			position.x -= speed;
			backward = true;
		}
		else
		{
			backward = false;
		}
		

		if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT || App->input->controller[RIGHT] == KEY_STATE::KEY_REPEAT )
		{
			position.x += speed;
			forward = true;
		}
		else 
		{
			forward = false; 
		}

		if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT || App->input->controller[DOWN] == KEY_STATE::KEY_REPEAT )
		{
			position.y += speed;
			

			if (current_animation != &downward)
			{
				downward.Reset();
				current_animation = &downward;
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT || App->input->controller[UP] == KEY_STATE::KEY_REPEAT  )
		{
			position.y -= speed;
			
			if (current_animation != &upward)
			{
				upward.Reset();
				current_animation = &upward;	
			}
		}

	
		if ((App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN || App->input->controller[BUTTON_A] == KEY_STATE::KEY_DOWN) && destroyed == false)
		{
			if (Laser == false)
			{
				App->particles->AddParticle(App->particles->shot, position.x + 28, position.y + 6, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->tent_shot, tent1_pos.x + 19, tent1_pos.y + 3, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->tent_shot, tent2_pos.x + 19, tent2_pos.y + 3, COLLIDER_PLAYER_SHOT);
				App->audio->ChunkPlay(shot);
				cooldown++;
			}
			else 
			{
				App->particles->AddParticle(App->particles->laser, position.x, position.y + 6, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser, tent1_pos.x, tent1_pos.y, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser, tent2_pos.x, tent2_pos.y, COLLIDER_PLAYER_SHOT);
				App->audio->ChunkPlay(laser);
				cooldown++;
			}
		}
		
		
		
		
		if ((App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_REPEAT || App->input->controller[BUTTON_A] == KEY_STATE::KEY_REPEAT) && destroyed == false)
		{
			if (App->render->camera.x % 40 == 0)
			{
				if (Laser == false)
				{
					App->particles->AddParticle(App->particles->shot, position.x + 28, position.y + 6, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->tent_shot, tent1_pos.x + 19, tent1_pos.y + 3, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->tent_shot, tent2_pos.x + 19, tent2_pos.y + 3, COLLIDER_PLAYER_SHOT);
					App->audio->ChunkPlay(shot);
				}
				else
				{
					App->particles->AddParticle(App->particles->laser, position.x, position.y, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser, tent1_pos.x, tent1_pos.y, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser, tent2_pos.x , tent2_pos.y, COLLIDER_PLAYER_SHOT);
					App->audio->ChunkPlay(laser);
				}
					
			}
		}
		

		if ((App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_IDLE && App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_IDLE))
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
			App->fade->FadeToBlack((Module*)App->lvl5, (Module*)App->stage_cleared);
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
				playerHitbox = App->collision->AddCollider({ position.x, position.y, 7, 6 }, COLLIDER_PLAYER, this);
			}
		}
		if (godmode == false)
			playerHitbox->SetPos(position.x + 9, position.y + 5);

		if (App->input->keyboard[SDL_SCANCODE_F3] == KEY_STATE::KEY_DOWN && App->fade->IsFading() == false)
		{
			App->audio->ChunkPlay(death);
			App->particles->AddParticle(App->particles->player_death, position.x, position.y, COLLIDER_NONE);
			App->player->Disable();
			App->fade->FadeToBlack((Module*)App->lvl5, (Module*)App->game_over, 5.0f);
		}

		if (App->input->keyboard[SDL_SCANCODE_F2] == KEY_STATE::KEY_DOWN && App->fade->IsFading() == false)
		{
			App->fade->FadeToBlack((Module*)App->lvl5, (Module*)App->stage_cleared, 1.0f);
		}
	}

	//-----------------------------------------------------------------------------------------------------------------------

	if(destroyed == false && current_animation!=nullptr )
		App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()), true);
	
	// Draw UI (score) -------------------------------------------------
	sprintf_s(score_text, 10, "%7d", score);

	// TODO 3: Blit the text of the score in at the bottom of the screen
	App->fonts->BlitText(70, 273, font_score, score_text);
	App->fonts->BlitText(35, 273, font_score, "1");
	App->fonts->BlitText(43, 273, font_score, "up");
	App->fonts->BlitText(145, 273, font_score, "top");
	//------------------------------------------------------------------
	
	// ------- LIVES -------
	if (lives == 2)
	{
		App->render->Blit(live, 63, 257, NULL, 0.0f, false);
		App->render->Blit(live, 70, 257, NULL, 0.0f, false);
	
	}
	if (lives == 1)
	{
		App->render->Blit(live, 63, 257, NULL, 0.0f, false);
		
	}
	
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
			
			App->fade->FadeToBlack((Module*)App->lvl5, (Module*)App->lvl5, 3.0f);
		}
		if (App->player->lives == 0)
		{
			App->fade->FadeToBlack((Module*)App->lvl5, (Module*)App->game_over, 5.0f);
			
		}
		speedup_anim = false;
		playerHitbox->to_delete = true;
		destroyed = true;
	}
}