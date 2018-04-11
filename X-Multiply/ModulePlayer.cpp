#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleAudio.h"
#include "ModuleParticles.h"
#include "ModuleFadeToBlack.h"
#include "ModuleMenu.h"

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
	playerHitBox = App->collision->AddCollider({ position.x, position.y, 37, 16 }, COLLIDER_PLAYER, this);


	return ret;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	Animation* current_animation = &idle;

	int speed = 1;

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
		position.x -= (speed * 2);
	}
	if (App->input->keyboard[SDL_SCANCODE_Q] == KEY_STATE::KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->shot, position.x + 27, position.y + 8);
		App->audio->ChunkPlay(shot);
	}

	playerHitBox->SetPos(position.x, position.y);
	

	//// Limits -------------------------------------
	//if (position.x <= 0)
	//{
	//	position.x = 0;
	//}
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


	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));
	
	
	return UPDATE_CONTINUE;
}

bool ModulePlayer::CleanUp()
{
	LOG("Unloading player assets:");
	App->collision->Disable();

	return true;
}

void ModulePlayer::OnCollision(Collider* coll_1, Collider* coll_2)
{
	if (coll_1->type == COLLIDER_WALL || coll_2->type == COLLIDER_WALL)
	{
		App->player->Disable();
		App->fade->FadeToBlack(this, App->menu, 2);
	}
}