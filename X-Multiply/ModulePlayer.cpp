#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"

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
	upward.PushBack({ 4, 0, 38, 10 });
	upward.speed = 0.06f;

	downward.PushBack({ 148, 0, 38, 16 });
	downward.PushBack({ 196, 0, 38, 16 });
	downward.speed = 0.06f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("image/Main_Character_Effects.png"); // arcade version
	return ret;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	Animation* current_animation = &idle;

	int speed = 3;

	if (App->input->keyboard[SDL_SCANCODE_D] == 1)
	{
		position.x += speed;
	}
	if (App->input->keyboard[SDL_SCANCODE_W] == 1)
	{
		current_animation = &upward;
		position.y -= speed;
	}
	if (App->input->keyboard[SDL_SCANCODE_S] == 1)
	{
		current_animation = &downward;
		position.y += speed;
	}
	if (App->input->keyboard[SDL_SCANCODE_A] == 1)
	{
		position.x -= speed;
	}
	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	App->render->Blit(graphics, position.x, position.y - r.h, &r);
	
	return UPDATE_CONTINUE;
}