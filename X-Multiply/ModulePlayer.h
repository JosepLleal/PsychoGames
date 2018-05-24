#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;
struct Collider;

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

public:

	SDL_Texture* graphics;
	SDL_Texture* live; 
	int font_score = -1;
	char score_text[10];
	uint score = 0;
	int counter = 0;

	Animation* current_animation = nullptr;
	Animation idle;
	Animation upward;
	Animation downward;
	Animation speedboost;
	Animation tentacles;

	iPoint position;
	Collider* playerHitbox;

	Collider* t1;
	Collider* t2;

	uint shot; //fx shot sound
	uint death; //fx when player dies

	int lives = 2; //Lives of Player

	bool forward = false;
	bool backward = false;
	bool idle_movement = true;

	bool godmode = false;
	bool destroyed = false;

	uint cooldown = 0;

	//PowerUps---------
	bool Speedup = false;
	bool speedup_anim = false;

	bool Bomb = false;

	iPoint tent1_pos;
	iPoint tent2_pos;
};

#endif