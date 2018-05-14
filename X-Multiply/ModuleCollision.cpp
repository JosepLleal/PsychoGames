#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"

ModuleCollision::ModuleCollision()
{
	for(uint i = 0; i < MAX_COLLIDERS; ++i)
		colliders[i] = nullptr;

	//COLLIDER_WALL CONDITIONS
	matrix[COLLIDER_WALL][COLLIDER_WALL] = false;
	matrix[COLLIDER_WALL][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_WALL][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_WALL][COLLIDER_PLAYER_SHOT] = true;
	matrix[COLLIDER_WALL][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_WALL][COLLIDER_POWERUP] = false;
	matrix[COLLIDER_WALL][COLLIDER_HUD] = false; 
	matrix[COLLIDER_WALL][COLLIDER_BOMB] = true;
	matrix[COLLIDER_WALL][COLLIDER_DIAMOND] = true;
	matrix[COLLIDER_WALL][COLLIDER_REDBALL] = true;

	//COLLIDER_PLAYER CONDITIONS
	matrix[COLLIDER_PLAYER][COLLIDER_WALL] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_ENEMY_SHOT] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_POWERUP] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_HUD] = true; 
	matrix[COLLIDER_PLAYER][COLLIDER_BOMB] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_DIAMOND] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_REDBALL] = true;


	//COLLIDER_ENEMY CONDITIONS
	matrix[COLLIDER_ENEMY][COLLIDER_WALL] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_ENEMY][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_PLAYER_SHOT] = true;
	matrix[COLLIDER_ENEMY][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_POWERUP] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_HUD] = false; 
	matrix[COLLIDER_ENEMY][COLLIDER_BOMB] = true;
	matrix[COLLIDER_ENEMY][COLLIDER_DIAMOND] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_REDBALL] = false;

	//COLLIDER_PLAYER_SHOT CONDITIONS
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_WALL] = true;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_POWERUP] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_HUD] = true; 
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_BOMB] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_DIAMOND] = true;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_REDBALL] = true;

	//ENEMY_SHOT COLLIDER CONDITIONS
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_WALL] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_POWERUP] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_HUD] = true; 
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_BOMB] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_DIAMOND] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_REDBALL] = false;

	//COLLIDER_POWERUP CONDITIONS
	matrix[COLLIDER_POWERUP][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_POWERUP][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_POWERUP][COLLIDER_WALL] = false;
	matrix[COLLIDER_POWERUP][COLLIDER_POWERUP] = false;
	matrix[COLLIDER_POWERUP][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_POWERUP][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_POWERUP][COLLIDER_HUD] = false; 
	matrix[COLLIDER_POWERUP][COLLIDER_BOMB] = false;
	matrix[COLLIDER_POWERUP][COLLIDER_DIAMOND] = false;
	matrix[COLLIDER_POWERUP][COLLIDER_REDBALL] = false;

	//COLLIDER_HUD CONDITIONS 
	matrix[COLLIDER_HUD][COLLIDER_PLAYER_SHOT] = true; 
	matrix[COLLIDER_HUD][COLLIDER_ENEMY_SHOT] = true; 
	matrix[COLLIDER_HUD][COLLIDER_WALL] = false; 
	matrix[COLLIDER_HUD][COLLIDER_ENEMY] = false; 
	matrix[COLLIDER_HUD][COLLIDER_PLAYER] = false; 
	matrix[COLLIDER_HUD][COLLIDER_POWERUP] = false; 
	matrix[COLLIDER_HUD][COLLIDER_HUD] = false; 
	matrix[COLLIDER_HUD][COLLIDER_BOMB] = false;
	matrix[COLLIDER_HUD][COLLIDER_DIAMOND] = false;
	matrix[COLLIDER_HUD][COLLIDER_REDBALL] = false;

	//COLLIDER_HUD CONDITIONS 
	matrix[COLLIDER_BOMB][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_BOMB][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_BOMB][COLLIDER_WALL] = true;
	matrix[COLLIDER_BOMB][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_BOMB][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_BOMB][COLLIDER_POWERUP] = false;
	matrix[COLLIDER_BOMB][COLLIDER_HUD] = false;
	matrix[COLLIDER_BOMB][COLLIDER_DIAMOND] = true;
	matrix[COLLIDER_BOMB][COLLIDER_REDBALL] = true;

	//COLLIDER_DIAMOND CONDITIONS 
	matrix[COLLIDER_DIAMOND][COLLIDER_PLAYER_SHOT] = true;
	matrix[COLLIDER_DIAMOND][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_DIAMOND][COLLIDER_WALL] = true;
	matrix[COLLIDER_DIAMOND][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_DIAMOND][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_DIAMOND][COLLIDER_POWERUP] = false;
	matrix[COLLIDER_DIAMOND][COLLIDER_HUD] = false;
	matrix[COLLIDER_DIAMOND][COLLIDER_BOMB] = true;
	matrix[COLLIDER_DIAMOND][COLLIDER_DIAMOND] = false;
	matrix[COLLIDER_DIAMOND][COLLIDER_REDBALL] = false;

	//COLLIDER_REDBALL CONDITIONS
	matrix[COLLIDER_REDBALL][COLLIDER_PLAYER_SHOT] = true;
	matrix[COLLIDER_REDBALL][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_REDBALL][COLLIDER_WALL] = true;
	matrix[COLLIDER_REDBALL][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_REDBALL][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_REDBALL][COLLIDER_POWERUP] = false;
	matrix[COLLIDER_REDBALL][COLLIDER_HUD] = false;
	matrix[COLLIDER_REDBALL][COLLIDER_BOMB] = true;
	matrix[COLLIDER_REDBALL][COLLIDER_REDBALL] = false; 
}

// Destructor
ModuleCollision::~ModuleCollision()
{}

update_status ModuleCollision::PreUpdate()
{
	// Remove all colliders scheduled for deletion
	for(uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if(colliders[i] != nullptr && colliders[i]->to_delete == true)
		{
			delete colliders[i];
			colliders[i] = nullptr;
		}
	}

	// Test all collisions
	Collider* c1;
	Collider* c2;

	for(uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		// skip empty colliders
		if(colliders[i] == nullptr)
			continue;

		c1 = colliders[i];

		// avoid checking collisions already checked
		for(uint k = i+1; k < MAX_COLLIDERS; ++k)
		{
			// skip empty colliders
			if(colliders[k] == nullptr)
				continue;

			c2 = colliders[k];

			if(c1->CheckCollision(c2->rect) == true)
			{
				if(matrix[c1->type][c2->type] && c1->callback) 
					c1->callback->OnCollision(c1, c2);
				
				if(matrix[c2->type][c1->type] && c2->callback) 
					c2->callback->OnCollision(c2, c1);
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before render is available
update_status ModuleCollision::Update()
{

	DebugDraw();

	return UPDATE_CONTINUE;
}

void ModuleCollision::DebugDraw()
{
	if(App->input->keyboard[SDL_SCANCODE_F1] == KEY_DOWN)
		debug = !debug;

	if(debug == false)
		return;

	Uint8 alpha = 80;
	for(uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if(colliders[i] == nullptr)
			continue;
		
		switch(colliders[i]->type)
		{
			case COLLIDER_NONE: // white
			App->render->DrawQuad(colliders[i]->rect, 255, 255, 255, alpha);
			break;
			case COLLIDER_WALL: // blue
			App->render->DrawQuad(colliders[i]->rect, 0, 0, 255, alpha);
			break;
			case COLLIDER_PLAYER: // green
			App->render->DrawQuad(colliders[i]->rect, 0, 255, 0, alpha);
			break;
			case COLLIDER_ENEMY: // red
			App->render->DrawQuad(colliders[i]->rect, 255, 0, 0, alpha);
			break;
			case COLLIDER_PLAYER_SHOT: // yellow
			App->render->DrawQuad(colliders[i]->rect, 255, 255, 0, alpha);
			break;
			case COLLIDER_ENEMY_SHOT: // magenta
			App->render->DrawQuad(colliders[i]->rect, 0, 255, 255, alpha);
			break;
			case COLLIDER_POWERUP: // orange
			App->render->DrawQuad(colliders[i]->rect, 255, 128, 0, alpha);
			break;
			case COLLIDER_HUD: //brown
			App->render->DrawQuad(colliders[i]->rect, 128, 0, 0, alpha);
			break; 
			case COLLIDER_BOMB: //violet
			App->render->DrawQuad(colliders[i]->rect, 128, 0, 255, alpha);
			break;
			case COLLIDER_DIAMOND: //grey
			App->render->DrawQuad(colliders[i]->rect, 128, 128, 128, alpha);
			break;
			case COLLIDER_REDBALL: //red
			App->render->DrawQuad(colliders[i]->rect, 255, 0, 0, alpha);
			break; 
		}
	}
}

// Called before quitting
bool ModuleCollision::CleanUp()
{
	LOG("Freeing all colliders");

	for(uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if(colliders[i] != nullptr)
		{
			delete colliders[i];
			colliders[i] = nullptr;
		}
	}

	return true;
}

Collider* ModuleCollision::AddCollider(SDL_Rect rect, COLLIDER_TYPE type, Module* callback)
{
	Collider* ret = nullptr;

	for(uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if(colliders[i] == nullptr)
		{
			ret = colliders[i] = new Collider(rect, type, callback);
			break;
		}
	}

	return ret;
}

// -----------------------------------------------------

bool Collider::CheckCollision(const SDL_Rect& r) const
{
	return (rect.x < r.x + r.w &&
			rect.x + rect.w > r.x &&
			rect.y < r.y + r.h &&
			rect.h + rect.y > r.y);
}