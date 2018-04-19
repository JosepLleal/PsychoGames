#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleMenu.h"
#include "ModuleLevel1.h"
#include "ModuleLevel2.h"
#include "ModuleParticles.h"
#include "ModuleFadeToBlack.h"
#include "ModuleFonts.h"

#include<stdio.h>


// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer::ModulePlayer()
{
	position.x = 100;
	position.y = 30;

	// idle animation (arcade sprite sheet)
	idle.PushBack({ 100, 0, 38, 16 });
	idle.speed = 0.2f;

	// go upward animation 
	upward.PushBack({ 52, 0, 38, 16 });
	upward.PushBack({ 4, 0, 38, 16 });
	upward.loop = false;
	upward.speed = 0.06f;

	downward.PushBack({ 148, 0, 38, 16 });
	downward.PushBack({ 196, 0, 38, 16 });
	downward.loop = false;
	downward.speed = 0.06f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("Image/Main_Character_Effects.png"); // arcade version
	shot = App->audio->LoadFX("Sound/xmultipl-122.wav");
	font_score = App->fonts->Load("image/xmultiply_redyellowfont.png", "0123456789@.-=<>()|&*/""!?abcdefghijklmnopqrstuvwxyz", 2);

	playerHitBox = App->collision->AddCollider({ position.x, position.y, 36, 16 }, COLLIDER_PLAYER, this);

	destroyed = false;

	return ret;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	Animation* current_animation = &idle;

	int speed = 2;

	if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
	{
		position.x += speed;
	}
	if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
	{
		position.y -= speed;
		current_animation = &upward;
		downward.Reset();
		
	}
	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
	{
		position.y += speed;
		current_animation = &downward;
		upward.Reset();
		
	}
	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
	{
		position.x -= speed*2;
	}
	if (App->input->keyboard[SDL_SCANCODE_Q] == KEY_STATE::KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->shot, position.x + 28, position.y +6, COLLIDER_PLAYER_SHOT);
		
		App->audio->ChunkPlay(shot);
	}

	playerHitBox->SetPos(position.x, position.y);

	
	//// Limits -------------------------------------
	/*if (position.x <= App->render->camera.x)
	{
		position.x = App->render->camera.x;
	}*/
	//else if (position.x >= SCREEN_WIDTH - 35)
	//{
	//	position.x = SCREEN_WIDTH - 35;
	//}

	//if (position.y <= 12)
	//{
	//	position.y = 12;
	//}
	//else if (position.y >= SCREEN_HEIGHT)
	//{
	//	position.y = SCREEN_HEIGHT;
	//}

	// Draw UI (score) --------------------------------------
	sprintf_s(score_text, 10, "%7d", score);

    //Blit the text of the score in at the bottom of the screen
	App->fonts->BlitText(10, 265, font_score, score_text);

	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	if(destroyed == false)
		App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()), true);
	
	
	return UPDATE_CONTINUE;
}

bool ModulePlayer::CleanUp()
{
	LOG("Unloading player assets:");

	App->textures->Unload(graphics);
	App->fonts->UnLoad(font_score);
	

	if (playerHitBox)
		playerHitBox->to_delete = true;

	return true;
}

void ModulePlayer::OnCollision(Collider* coll_1, Collider* coll_2)
{
	if (coll_1->type == COLLIDER_WALL || coll_2->type == COLLIDER_WALL || coll_1->type == COLLIDER_ENEMY || coll_2->type == COLLIDER_ENEMY || coll_1->type == COLLIDER_ENEMY_SHOT || coll_2->type == COLLIDER_ENEMY_SHOT)
	{
		App->player->Disable();
		App->particles->AddParticle(App->particles->player_death, position.x, position.y, COLLIDER_NONE);
		//App->lvl1->Disable();
		App->fade->FadeToBlack((Module*)App->lvl1, (Module*)App->menu);
		
		destroyed = true;
	}
}
