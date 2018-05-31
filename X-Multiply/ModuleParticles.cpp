#include <math.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleInput.h"

#include "SDL/include/SDL_timer.h"

ModuleParticles::ModuleParticles()
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		active[i] = nullptr;
	explosion_enemy.anim.PushBack({ 17, 244, 30, 29 });
	explosion_enemy.anim.PushBack({ 50, 247, 29, 25 });
	explosion_enemy.anim.PushBack({ 79, 240, 48, 36 });
	explosion_enemy.anim.PushBack({ 131, 242, 41, 31 });
	explosion_enemy.anim.PushBack({ 177, 241, 45, 34 });
	explosion_enemy.anim.PushBack({ 21, 287, 42, 39 });
	explosion_enemy.anim.PushBack({ 69, 286, 40, 38 });
	explosion_enemy.anim.PushBack({ 116, 287, 39, 37 });
	explosion_enemy.anim.PushBack({ 163, 286, 43, 43 });
	explosion_enemy.anim.loop = false;
	explosion_enemy.anim.speed = 0.3f;

	enemy_shot.anim.PushBack({ 253, 9, 10, 10 });
	enemy_shot.anim.PushBack({ 271, 10, 10, 10 });
	enemy_shot.anim.PushBack({ 254, 25, 10, 10 });
	enemy_shot.anim.PushBack({ 271, 25, 10, 10 });
	enemy_shot.anim.speed = 0.1f;
	enemy_shot.anim.loop = true;
	enemy_shot.speed.x = -2;
	enemy_shot.speed.y = 1;
	enemy_shot.life = 4000;

	player_death.anim.PushBack({ 220, 50, 40, 42 });
	player_death.anim.PushBack({ 268, 50, 40, 42 });
	player_death.anim.PushBack({ 316, 144, 40, 42 });
	player_death.anim.PushBack({ 364, 144, 40, 42 });
	player_death.anim.PushBack({ 412, 144, 40, 42 });
	player_death.anim.speed = 0.2f;
	player_death.anim.loop = false;

	//SMALL BLUE EXPLOSION COORDINATES
	/*player_death.anim.PushBack({ 112, 144, 16, 16 });
	player_death.anim.PushBack({ 96, 144, 16, 16 });
	player_death.anim.PushBack({ 80, 144, 16, 16 });
	player_death.anim.PushBack({ 64, 144, 16, 16 });
	player_death.anim.PushBack({ 48, 144, 16, 16 });
	player_death.anim.PushBack({ 32, 144, 16, 16 });
	player_death.anim.PushBack({ 16, 144, 16, 16 });
	player_death.anim.PushBack({ 0, 144, 16, 16 });
	player_death.anim.speed = 0.5f;
	player_death.anim.loop = false;*/

	shot_impact.anim.PushBack({ 82, 34, 12, 12 });
	shot_impact.anim.PushBack({ 102, 37, 8, 9 });
	shot_impact.anim.speed = 0.3f;
	shot_impact.anim.loop = false;

	//BALL EXPLOSION COORDINATES
	/*shot_impact.anim.PushBack({ 132, 34, 12, 12 });
	shot_impact.anim.PushBack({ 147, 34, 12, 12 });
	shot_impact.anim.PushBack({ 163, 34, 12, 12 });*/

	shot.anim.PushBack({ 64, 38, 16, 5 });
	shot.anim.speed = 0.0f;
	shot.speed.x = 7;
	shot.life = 950;

	tent_shot.anim.PushBack({ 115, 38, 12, 5 });
	tent_shot.anim.speed = 0.0f;
	tent_shot.speed.x = 7;
	tent_shot.life = 950;

	bomb_explosion.anim.PushBack({ 47, 173, 30, 28 });
	bomb_explosion.anim.PushBack({ 80, 173, 30, 28 });
	bomb_explosion.anim.PushBack({ 112, 173, 30, 28 });
	bomb_explosion.anim.speed = 0.3f;
	bomb_explosion.anim.loop = false;

	bomb.anim.PushBack({ 235, 106, 15, 15 });
	bomb.anim.PushBack({ 253, 106, 15, 15 });
	bomb.anim.PushBack({ 267, 106, 15, 15 });
	bomb.anim.PushBack({ 286, 106, 15, 15 });
	bomb.anim.PushBack({ 302, 106, 15, 15 });
	bomb.anim.loop = false;
	bomb.anim.speed = 0.1f;
	bomb.speed.x = 4;
	bomb.speed.y = 3;
	bomb.life = 4000;

	//anemona shot 1 
	anemona_shot1.anim.PushBack({ 253, 9, 10, 10 });
	anemona_shot1.anim.PushBack({ 271, 10, 10, 10 });
	anemona_shot1.anim.PushBack({ 254, 25, 10, 10 });
	anemona_shot1.anim.PushBack({ 271, 25, 10, 10 });
	anemona_shot1.anim.loop = true;
	anemona_shot1.anim.speed = 0.3f;
	anemona_shot1.speed.x = -3;
	anemona_shot1.speed.y = -1;
	anemona_shot1.life = 4000;

	//anemona shot 2
	anemona_shot2.anim.PushBack({ 253, 9, 10, 10 });
	anemona_shot2.anim.PushBack({ 271, 10, 10, 10 });
	anemona_shot2.anim.PushBack({ 254, 25, 10, 10 });
	anemona_shot2.anim.PushBack({ 271, 25, 10, 10 });
	anemona_shot2.anim.loop = true;
	anemona_shot2.anim.speed = 0.3f;
	anemona_shot2.speed.x = -2;
	anemona_shot2.speed.y = -2;
	anemona_shot2.life = 4000;

	//anemona shot 3
	anemona_shot3.anim.PushBack({ 253, 9, 10, 10 });
	anemona_shot3.anim.PushBack({ 271, 10, 10, 10 });
	anemona_shot3.anim.PushBack({ 254, 25, 10, 10 });
	anemona_shot3.anim.PushBack({ 271, 25, 10, 10 });
	anemona_shot3.anim.loop = true;
	anemona_shot3.anim.speed = 0.3f;
	anemona_shot3.speed.x = 0;
	anemona_shot3.speed.y = -2;
	anemona_shot3.life = 4000;

	//anemona shot 4 
	anemona_shot4.anim.PushBack({ 253, 9, 10, 10 });
	anemona_shot4.anim.PushBack({ 271, 10, 10, 10 });
	anemona_shot4.anim.PushBack({ 254, 25, 10, 10 });
	anemona_shot4.anim.PushBack({ 271, 25, 10, 10 });
	anemona_shot4.anim.loop = true;
	anemona_shot4.anim.speed = 0.3f;
	anemona_shot4.speed.x = 2;
	anemona_shot4.speed.y = -2;
	anemona_shot4.life = 4000;

	//anemona shot 5
	anemona_shot5.anim.PushBack({ 253, 9, 10, 10 });
	anemona_shot5.anim.PushBack({ 271, 10, 10, 10 });
	anemona_shot5.anim.PushBack({ 254, 25, 10, 10 });
	anemona_shot5.anim.PushBack({ 271, 25, 10, 10 });
	anemona_shot5.anim.loop = true;
	anemona_shot5.anim.speed = 0.3f;
	anemona_shot5.speed.x = 3;
	anemona_shot5.speed.y = -1;
	anemona_shot5.life = 4000;

	//anemona upsidedown 1
	anemona_shotud1.anim.PushBack({ 253, 9, 10, 10 });
	anemona_shotud1.anim.PushBack({ 271, 10, 10, 10 });
	anemona_shotud1.anim.PushBack({ 254, 25, 10, 10 });
	anemona_shotud1.anim.PushBack({ 271, 25, 10, 10 });
	anemona_shotud1.anim.loop = true;
	anemona_shotud1.anim.speed = 0.3f;
	anemona_shotud1.speed.x = -3;
	anemona_shotud1.speed.y = 1;
	anemona_shotud1.life = 4000;

	//anemona upsidedown 2
	anemona_shotud2.anim.PushBack({ 253, 9, 10, 10 });
	anemona_shotud2.anim.PushBack({ 271, 10, 10, 10 });
	anemona_shotud2.anim.PushBack({ 254, 25, 10, 10 });
	anemona_shotud2.anim.PushBack({ 271, 25, 10, 10 });
	anemona_shotud2.anim.loop = true;
	anemona_shotud2.anim.speed = 0.3f;
	anemona_shotud2.speed.x = -2;
	anemona_shotud2.speed.y = 2;
	anemona_shotud2.life = 4000;

	//anemona upsidedown 3
	anemona_shotud3.anim.PushBack({ 253, 9, 10, 10 });
	anemona_shotud3.anim.PushBack({ 271, 10, 10, 10 });
	anemona_shotud3.anim.PushBack({ 254, 25, 10, 10 });
	anemona_shotud3.anim.PushBack({ 271, 25, 10, 10 });
	anemona_shotud3.anim.loop = true;
	anemona_shotud3.anim.speed = 0.3f;
	anemona_shotud3.speed.x = 0;
	anemona_shotud3.speed.y = 2;
	anemona_shotud3.life = 4000;

	//anemona upsidedown 4
	anemona_shotud4.anim.PushBack({ 253, 9, 10, 10 });
	anemona_shotud4.anim.PushBack({ 271, 10, 10, 10 });
	anemona_shotud4.anim.PushBack({ 254, 25, 10, 10 });
	anemona_shotud4.anim.PushBack({ 271, 25, 10, 10 });
	anemona_shotud4.anim.loop = true;
	anemona_shotud4.anim.speed = 0.3f;
	anemona_shotud4.speed.x = 2;
	anemona_shotud4.speed.y = 2;
	anemona_shotud4.life = 4000;

	//anemona upsidedown 5
	anemona_shotud5.anim.PushBack({ 253, 9, 10, 10 });
	anemona_shotud5.anim.PushBack({ 271, 10, 10, 10 });
	anemona_shotud5.anim.PushBack({ 254, 25, 10, 10 });
	anemona_shotud5.anim.PushBack({ 271, 25, 10, 10 });
	anemona_shotud5.anim.loop = true;
	anemona_shotud5.anim.speed = 0.3f;
	anemona_shotud5.speed.x = 3;
	anemona_shotud5.speed.y = 1;
	anemona_shotud5.life = 4000;
	
	//drop explosion when touch the water
	drop_shot.anim.PushBack({ 288, 12, 6, 5 });
	drop_shot.anim.loop = true;
	drop_shot.speed.x = 0;
	drop_shot.speed.y = -2; 
	drop_shot.life = 4000; 

	drop_shot2.anim.PushBack({ 288, 12, 6, 5 });
	drop_shot2.anim.loop = false;
	drop_shot2.speed.x = 0;
	drop_shot2.speed.y = 2;
	drop_shot2.life = 4000;
}

ModuleParticles::~ModuleParticles()
{}

// Load assets
bool ModuleParticles::Start()
{
	LOG("Loading particles");
	graphics = App->textures->Load("image/particles.png");

	

	return true;
}

// Unload assets
bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");
	App->textures->Unload(graphics);

	// Unload fx

	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if(active[i] != nullptr)
		{
			delete active[i];
			active[i] = nullptr;
		}
	}

	return true;
}

// Update: draw background
update_status ModuleParticles::Update()
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		Particle* p = active[i];

		if(p == nullptr)
			continue;

		if(p->Update() == false)
		{
			delete p;
			active[i] = nullptr;
		}
		else if(SDL_GetTicks() >= p->born)
		{
			App->render->Blit(graphics, p->position.x, p->position.y, &(p->anim.GetCurrentFrame()));
			if(p->fx_played == false)
			{
				p->fx_played = true;
				// play the audio SFX
			}

		}
		
	}

	return UPDATE_CONTINUE;
}

void ModuleParticles::AddParticle(const Particle& particle, int x, int y, COLLIDER_TYPE collider_type, Uint32 delay)
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if(active[i] == nullptr)
		{
			Particle* p = new Particle(particle);
			p->born = SDL_GetTicks() + delay;
			p->position.x = x;
			p->position.y = y;
			if(collider_type != COLLIDER_NONE)
				p->collider = App->collision->AddCollider(p->anim.GetCurrentFrame(), collider_type, this);
			active[i] = p;
			break;
		}
	}
}

void ModuleParticles::OnCollision(Collider* c1, Collider* c2)
{
	
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		
		if(active[i] != nullptr && active[i]->collider == c1)
		{
			if (c1->type == COLLIDER_PLAYER_SHOT)
				AddParticle(shot_impact, active[i]->position.x, active[i]->position.y, COLLIDER_NONE);

			if (c1->type == COLLIDER_BOMB)
				AddParticle(bomb_explosion, active[i]->position.x, active[i]->position.y, COLLIDER_NONE);

			delete active[i];
			active[i] = nullptr;
			break;
		}
	}
}

// -------------------------------------------------------------
// -------------------------------------------------------------

Particle::Particle()
{
	position.SetToZero();
	speed.SetToZero();
}

Particle::Particle(const Particle& p) : 
anim(p.anim), position(p.position), speed(p.speed),
fx(p.fx), born(p.born), life(p.life)
{}

Particle::~Particle()
{
	if (collider != nullptr)
		collider->to_delete = true;
}

bool Particle::Update()
{
	bool ret = true;

	if(life > 0)
	{
		if((SDL_GetTicks() - born) > life)
			ret = false;
	}
	else
		if(anim.Finished())
			ret = false;

	position.x += speed.x;
	position.y += speed.y;

	if(collider != nullptr)
		collider->SetPos(position.x, position.y);

	return ret;
}

