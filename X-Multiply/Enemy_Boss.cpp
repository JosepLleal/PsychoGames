#include "Application.h"
#include "Enemy_Boss.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleEnemies.h"
#include "SDL/include/SDL_timer.h"

Enemy_Boss::Enemy_Boss(int x, int y) : Enemy(x, y)
{
	life = 78;

	left_goup.PushBack({ 6, 448, 170, 224 });
	left_goup.PushBack({ 188, 448, 198, 224 });
	left_goup.PushBack({ 393, 449, 194, 224 });
	left_goup.PushBack({ 632, 449, 184, 224 });
	left_goup.PushBack({ 851, 449, 170, 231 });
	left_goup.PushBack({ 5, 693, 170, 232 });

	left_goup.speed = 0.1f;
	animation = &left_goup;

	left_shoot.PushBack({ 185, 692, 170, 232 });
	left_shoot.PushBack({ 367, 692, 170, 232 });
	left_shoot.PushBack({ 549, 692, 170, 232 });
	left_shoot.PushBack({ 732, 692, 170, 232 });

	left_shoot.speed = 0.1f;
	animation = &left_shoot;

	left_godown.PushBack({ 5, 693, 170, 232 });
	left_godown.PushBack({ 851, 449, 170, 231 });
	left_godown.PushBack({ 632, 449, 184, 224 });
	left_godown.PushBack({ 393, 449, 194, 224 });
	left_godown.PushBack({ 188, 448, 198, 224 });
	left_godown.PushBack({ 6, 448, 170, 224 });

	left_godown.speed = 0.1f;
	animation = &left_godown;

	left_goup.PushBack({ 6, 448, 170, 224 });
	left_goup.PushBack({ 188, 448, 198, 224 });
	left_goup.PushBack({ 393, 449, 194, 224 });
	left_goup.PushBack({ 632, 449, 184, 224 });
	left_goup.PushBack({ 851, 449, 170, 231 });
	left_goup.PushBack({ 5, 693, 170, 232 });

	left_goup.speed = 0.1f;
	animation = &left_goup;

	left_shoot.PushBack({ 185, 692, 170, 232 });
	left_shoot.PushBack({ 367, 692, 170, 232 });
	left_shoot.PushBack({ 549, 692, 170, 232 });
	left_shoot.PushBack({ 732, 692, 170, 232 });

	left_shoot.speed = 0.1f;
	animation = &left_shoot;

	left_godown.PushBack({ 5, 693, 170, 232 });
	left_godown.PushBack({ 851, 449, 170, 231 });
	left_godown.PushBack({ 632, 449, 184, 224 });
	left_godown.PushBack({ 393, 449, 194, 224 });
	left_godown.PushBack({ 188, 448, 198, 224 });
	left_godown.PushBack({ 6, 448, 170, 224 });

	left_godown.speed = 0.1f;
	animation = &left_godown;
	////////////////////////////////////
	left_goup.PushBack({ 16, 949, 155, 202 });
	left_goup.PushBack({ 190, 949, 155, 202 });
	left_goup.PushBack({ 371, 949, 155, 202 });
	left_goup.PushBack({ 553, 949, 155, 202 });
	left_goup.PushBack({ 736, 949, 155, 202 });
	left_goup.PushBack({ 16, 1165, 155, 202 });
	left_goup.PushBack({ 190, 1165, 155, 202 });

	left_goup.speed = 0.1f;
	animation = &left_goup;

	left_shoot.PushBack({ 370, 1165, 155, 202 });
	left_shoot.PushBack({ 554, 1165, 155, 202 });
	left_shoot.PushBack({ 735, 1170, 155, 202 });

	left_shoot.speed = 0.1f;
	animation = &left_shoot;

	left_godown.PushBack({ 190, 1165, 155, 202 });
	left_godown.PushBack({ 16, 1165, 155, 202 });
	left_godown.PushBack({ 736, 949, 155, 202 });
	left_godown.PushBack({ 553, 949, 155, 202 });
	left_godown.PushBack({ 371, 949, 155, 202 });
	left_godown.PushBack({ 190, 949, 155, 202 });
	left_godown.PushBack({ 16, 949, 155, 202 });

	left_godown.speed = 0.1f;
	animation = &left_godown;
	


	collider = App->collision->AddCollider({ 0, 0, 29, 38 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_position.x = x;
	original_position.y = y;
}

void Enemy_Boss::Move()
{
	/* boss shooting
	if (shooting_counter % 185 == 0)
	{
		App->audio->ChunkPlay(App->enemies->boss_attack);
	}*/
}
void Enemy_Boss::OnCollision(Collider* collider)
{
	//boss lives
	/*if (life == 1)
	{
		
	}*/

}
