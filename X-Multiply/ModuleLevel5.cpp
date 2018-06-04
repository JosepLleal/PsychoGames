#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModulePowerUp.h"
#include "ModuleLevel5.h"
#include "ModuleAudio.h"

ModuleLevel5::ModuleLevel5()
{
	// tilemap
	ground_parallax.x = 0;
	ground_parallax.y = 0;
	ground_parallax.w = 4608;
	ground_parallax.h = 256;

	// Background 
	background_parallax.x = 0;
	background_parallax.y = 0;
	background_parallax.w = 4608;
	background_parallax.h = 256;
}

ModuleLevel5::~ModuleLevel5()
{}

// Load assets
bool ModuleLevel5::Start()
{
	LOG("Loading space scene");

	background = App->textures->Load("image/Tilemap/Backround_lvl5.png");
	tilemap1 = App->textures->Load("image/Tilemap/LV5_Tilemap.png");
	hud = App->textures->Load("image/xmultiply_hud.png");
	diamond = App->textures->Load("image/LV5_diamond.png");

	App->audio->MusicPlay("Sound/11_Bloody_Bloom_Stage_5_.ogg", 0.5f);

	App->player->Enable();
	App->particles->Enable();
	App->collision->Enable();
	App->enemies->Enable();
	App->powerup->Enable();

	App->render->camera.x = 0;//3100
	App->render->camera.y = 0;

	//-----------------------------------------//
	//				COLLIDER_WALL			   //
	//-----------------------------------------//

	//TOP ALL LEVEL 
	App->collision->AddCollider({ 241, 0, 48, 18 }, COLLIDER_WALL);
	App->collision->AddCollider({ 340, 0, 2690, 18 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3080, 0, 1550, 24 }, COLLIDER_WALL);

	//TOP COLUMNS 
	App->collision->AddCollider({ 257, 18, 15, 72 }, COLLIDER_WALL);
	App->collision->AddCollider({ 353, 18, 15, 55 }, COLLIDER_WALL);
	App->collision->AddCollider({ 545, 18, 14, 55 }, COLLIDER_WALL);
	App->collision->AddCollider({ 898, 18, 15, 36 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1009, 18, 15, 55 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1073, 18, 16, 92 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1105, 18, 15, 55 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1153, 18, 15, 55 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1185, 18, 16, 92 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1329, 18, 15, 55 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1569, 18, 15, 55 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1601, 18, 16, 92 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1761, 18, 15, 36 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1905, 18, 15, 55 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2402, 18, 15, 72 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2498, 18, 15, 36 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2577, 18, 15, 92 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2610, 18, 15, 55 }, COLLIDER_WALL);

	//TOP SQUARES ON DROPS
	App->collision->AddCollider({ 3117, 24, 15, 49 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3151, 24, 15, 30 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3214, 24, 15, 40 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3278, 24, 15, 30 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3374, 24, 15, 49 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3406, 24, 15, 30 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3470, 24, 15, 40 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3534, 24, 15, 30 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3630, 24, 15, 49 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3662, 24, 15, 30 }, COLLIDER_WALL);//
	App->collision->AddCollider({ 3726, 24, 15, 30 }, COLLIDER_WALL);//
	App->collision->AddCollider({ 3790, 24, 15, 30 }, COLLIDER_WALL);//
	App->collision->AddCollider({ 3855, 24, 15, 40 }, COLLIDER_WALL);//
	App->collision->AddCollider({ 3918, 24, 15, 30 }, COLLIDER_WALL);//
	App->collision->AddCollider({ 3983, 24, 15, 40 }, COLLIDER_WALL);//
	App->collision->AddCollider({ 4045, 24, 15, 30 }, COLLIDER_WALL);//
	App->collision->AddCollider({ 4110, 24, 15, 40 }, COLLIDER_WALL);//
	App->collision->AddCollider({ 4174, 24, 15, 30 }, COLLIDER_WALL);//
	App->collision->AddCollider({ 4238, 24, 15, 49 }, COLLIDER_WALL);//double
	App->collision->AddCollider({ 4270, 24, 15, 49 }, COLLIDER_WALL);//double
	App->collision->AddCollider({ 4302, 24, 15, 30 }, COLLIDER_WALL);//
	App->collision->AddCollider({ 4366, 24, 15, 40 }, COLLIDER_WALL);//
	App->collision->AddCollider({ 4430, 24, 15, 30 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4526, 24, 15, 49 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4558, 24, 15, 30 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4598, 24, 15, 40 }, COLLIDER_WALL);

	//TOP SQUARES 
	App->collision->AddCollider({ 1977, 18, 80, 45 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2147, 18, 110, 18 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2695, 18, 20, 20 }, COLLIDER_WALL);//bigBox1
	App->collision->AddCollider({ 2715, 18, 110, 45 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2825, 18, 20, 20 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2885, 18, 110, 45 }, COLLIDER_WALL);//bigBox2
	App->collision->AddCollider({ 2995, 18, 20, 20 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2865, 18, 20, 20 }, COLLIDER_WALL);

	//BOTTOM ALL LEVEL 
	App->collision->AddCollider({ 200, 238, 2199, 18 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2417, 238, 280, 18 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3080, 232, 1550, 24 }, COLLIDER_WALL);

	//BOTTOM COLUMNS
	App->collision->AddCollider({ 209, 183, 15, 55 }, COLLIDER_WALL);
	App->collision->AddCollider({ 369, 183, 15, 55 }, COLLIDER_WALL);
	App->collision->AddCollider({ 450, 202, 15, 36 }, COLLIDER_WALL);
	App->collision->AddCollider({ 640, 166, 15, 72 }, COLLIDER_WALL);
	App->collision->AddCollider({ 802, 202, 15, 36 }, COLLIDER_WALL);
	App->collision->AddCollider({ 930, 202, 15, 36 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1266, 166, 15, 72 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1409, 183, 15, 55 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1681, 202, 15, 36 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1841, 202, 15, 36 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1920, 183, 15, 55 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2033, 146, 15, 92 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2081, 202, 15, 36 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2385, 202, 15, 36 }, COLLIDER_WALL); 
	App->collision->AddCollider({ 2418, 202, 15, 36 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2498, 166, 15, 72 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2642, 146, 15, 92 }, COLLIDER_WALL);
	
	//BOTTOM COLUMNS ON DROPS
	App->collision->AddCollider({ 3117, 166, 15, 66 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3151, 193, 15, 39 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3214, 183, 15, 49 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3278, 193, 15, 39 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3342, 183, 15, 49 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3406, 193, 15, 39 }, COLLIDER_WALL);

	//First 4 Columns 
	App->collision->AddCollider({ 2145, 126, 15, 112 }, COLLIDER_WALL);//4 Columns
	App->collision->AddCollider({ 2160, 183, 17, 55 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2177, 126, 15, 112 }, COLLIDER_WALL);//4 Columns
	App->collision->AddCollider({ 2192, 163, 18, 75 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2210, 126, 15, 112 }, COLLIDER_WALL);//4 Columns
	App->collision->AddCollider({ 2225, 148, 18, 90 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2243, 126, 15, 112 }, COLLIDER_WALL);//4 Columns

	//Second 4 Columns  
	App->collision->AddCollider({ 2721, 146, 15, 108 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2736, 203, 17, 51 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2753, 146, 15, 108 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2768, 183, 18, 71 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2786, 146, 14, 108 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2800, 168, 18, 90 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2818, 146, 15, 108 }, COLLIDER_WALL);

	//Third 4 Columns  
	App->collision->AddCollider({ 2881, 146, 15, 108 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2896, 203, 17, 51 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2913, 146, 15, 108 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2928, 183, 18, 71 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2946, 146, 14, 108 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2960, 168, 18, 90 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2978, 146, 15, 108 }, COLLIDER_WALL);

	//TOP FIXES 
	App->collision->AddCollider({ 272, 18, 15, 12 }, COLLIDER_WALL);
	App->collision->AddCollider({ 368, 18, 15, 20 }, COLLIDER_WALL);
	App->collision->AddCollider({ 560, 18, 15, 20 }, COLLIDER_WALL);

	//BOTTOM FIXES
	App->collision->AddCollider({ 224, 214, 15, 24 }, COLLIDER_WALL);
	App->collision->AddCollider({ 354, 226, 15, 12 }, COLLIDER_WALL);
	App->collision->AddCollider({ 384, 214, 15, 24 }, COLLIDER_WALL);
	App->collision->AddCollider({ 502, 228, 20, 10 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1424, 214, 15, 24 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2003, 219, 30, 19 }, COLLIDER_WALL);

	//BOTTOM BOXES 
	App->collision->AddCollider({ 294, 228, 20, 10 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1030, 228, 20, 10 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1096, 228, 20, 10 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1159, 228, 20, 10 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1224, 228, 20, 10 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1336, 228, 20, 10 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1368, 228, 20, 10 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1464, 228, 80, 10 }, COLLIDER_WALL);

	//COllider for Diamond and Drop animation
	

	
	//App->enemies->AddEnemy(ENEMY_TYPES::DROP, 3534, 57);

	////Diamonds
	//App->enemies->AddEnemy(ENEMY_TYPES::DIAMOND_WALL2, 1095, 100);
	//App->collision->AddCollider({1100, 120, 2, 40}, COLLIDER_NONE);
	//App->enemies->AddEnemy(ENEMY_TYPES::DIAMOND_WALL, 1647, 140);
	//App->collision->AddCollider({ 1652, 160, 2, 15 }, COLLIDER_NONE);
	//App->enemies->AddEnemy(ENEMY_TYPES::DIAMOND_WALL, 1990, 140);
	//App->collision->AddCollider({ 1995, 160, 2, 15 }, COLLIDER_NONE);
	///*App->enemies->AddEnemy(ENEMY_TYPES::DIAMOND_WALL, 1990, 140);
	//App->collision->AddCollider({ 11, 120, 2, 40 }, COLLIDER_NONE);*/
	////Three diamond together
	//App->enemies->AddEnemy(ENEMY_TYPES::DIAMOND_WALL, 2160, 40);
	//App->collision->AddCollider({ 2163, 60, 2, 40 }, COLLIDER_NONE);
	//App->enemies->AddEnemy(ENEMY_TYPES::DIAMOND_WALL, 2192, 40);
	//App->collision->AddCollider({ 2197, 60, 2, 25 }, COLLIDER_NONE);
	//App->enemies->AddEnemy(ENEMY_TYPES::DIAMOND_WALL, 2225, 40);
	//App->collision->AddCollider({ 2231, 60, 2, 10 }, COLLIDER_NONE);
	////Diamond that falls. 
	//App->enemies->AddEnemy(ENEMY_TYPES::DIAMOND_WALL, 2400, 100);
	//App->collision->AddCollider({ 2406, 120, 2, 40 }, COLLIDER_NONE);

	////Drops
	//App->enemies->AddEnemy(ENEMY_TYPES::DROP, 3118, 76);
	//App->enemies->AddEnemy(ENEMY_TYPES::DROP, 3151, 57);
	//App->enemies->AddEnemy(ENEMY_TYPES::DROP, 3214, 67);
	//App->enemies->AddEnemy(ENEMY_TYPES::DROP, 3278, 57);
	//App->enemies->AddEnemy(ENEMY_TYPES::DROP, 3374, 76);
	//App->enemies->AddEnemy(ENEMY_TYPES::DROP, 3406, 57);

	//App->collision->AddCollider({ 3534, 230, 13, 1 }, COLLIDER_NONE);
	//App->enemies->AddEnemy(ENEMY_TYPES::DROP, 3534, 57);
	//App->collision->AddCollider({ 3662, 230, 13, 1 }, COLLIDER_NONE);
	//App->enemies->AddEnemy(ENEMY_TYPES::DROP, 3662, 57);
	//App->collision->AddCollider({ 3726, 230, 13, 1 }, COLLIDER_NONE);
	//App->enemies->AddEnemy(ENEMY_TYPES::DROP, 3726, 57);
	//App->collision->AddCollider({ 3790, 230, 13, 1 }, COLLIDER_NONE);
	//App->enemies->AddEnemy(ENEMY_TYPES::DROP, 3790, 57);
	//App->collision->AddCollider({ 3855, 230, 13, 1 }, COLLIDER_NONE);
	//App->enemies->AddEnemy(ENEMY_TYPES::DROP, 3855, 67);
	//App->collision->AddCollider({ 3918, 230, 13, 1 }, COLLIDER_NONE);
	//App->enemies->AddEnemy(ENEMY_TYPES::DROP, 3918, 57);
	//App->collision->AddCollider({ 3983, 230, 13, 1 }, COLLIDER_NONE);
	//App->enemies->AddEnemy(ENEMY_TYPES::DROP, 3983, 67);
	//App->collision->AddCollider({ 4045, 230, 13, 1 }, COLLIDER_NONE);
	//App->enemies->AddEnemy(ENEMY_TYPES::DROP, 4045, 57);
	//App->collision->AddCollider({ 4110, 230, 13, 1 }, COLLIDER_NONE);
	//App->enemies->AddEnemy(ENEMY_TYPES::DROP, 4110, 67);
	//App->collision->AddCollider({ 4174, 230, 13, 1 }, COLLIDER_NONE);
	//App->enemies->AddEnemy(ENEMY_TYPES::DROP, 4174, 57);
	//App->collision->AddCollider({ 4270, 230, 13, 1 }, COLLIDER_NONE);
	//App->enemies->AddEnemy(ENEMY_TYPES::DROP, 4270, 77);
	//App->collision->AddCollider({ 4302, 229, 13, 1 }, COLLIDER_NONE);
	//App->enemies->AddEnemy(ENEMY_TYPES::DROP, 4302, 57);
	//App->collision->AddCollider({ 4366, 230, 13, 1 }, COLLIDER_NONE);
	//App->enemies->AddEnemy(ENEMY_TYPES::DROP, 4366, 67);
	//App->collision->AddCollider({ 4430, 229, 13, 1 }, COLLIDER_NONE);
	//App->enemies->AddEnemy(ENEMY_TYPES::DROP, 4430, 57);
	//App->collision->AddCollider({ 4526, 230, 13, 1 }, COLLIDER_NONE);
	//App->enemies->AddEnemy(ENEMY_TYPES::DROP, 4526, 77);
	//App->collision->AddCollider({ 4558, 229, 13, 1 }, COLLIDER_NONE);
	//App->enemies->AddEnemy(ENEMY_TYPES::DROP, 4558, 57);
	//
	////GOOD POSITION
	//App->enemies->AddEnemy(ENEMY_TYPES::YELLOWBALL, 320, 202);
	////App->enemies->AddEnemy(ENEMY_TYPES::YELLOWBALL2, 450, 30);
	//App->enemies->AddEnemy(ENEMY_TYPES::YELLOWBALL2, 510, 25);
	////App->enemies->AddEnemy(ENEMY_TYPES::YELLOWBALL, 575, 202);
	//App->enemies->AddEnemy(ENEMY_TYPES::YELLOWBALL2, 625, 25);
	////App->enemies->AddEnemy(ENEMY_TYPES::YELLOWBALL2, 673, 20);
	//App->enemies->AddEnemy(ENEMY_TYPES::YELLOWBALL2, 735, 20);
	////App->enemies->AddEnemy(ENEMY_TYPES::YELLOWBALL, 735, 202);
	//App->enemies->AddEnemy(ENEMY_TYPES::YELLOWBALL2, 805, 20);
	////App->enemies->AddEnemy(ENEMY_TYPES::YELLOWBALL, 893, 195);
	//App->enemies->AddEnemy(ENEMY_TYPES::YELLOWBALL2, 970, 20);
	////App->enemies->AddEnemy(ENEMY_TYPES::YELLOWBALL, 1055, 202);
	//App->enemies->AddEnemy(ENEMY_TYPES::YELLOWBALL, 1118, 202);
	////App->enemies->AddEnemy(ENEMY_TYPES::YELLOWBALL2, 1290, 25);
	//App->enemies->AddEnemy(ENEMY_TYPES::YELLOWBALL, 1340, 200);


	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL2, 250, 68);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL, 235, 85);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL1, 245, 103);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL3, 270, 86);

	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL4, 300, 130);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL4, 273, 198);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL1, 337, 179 );

	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL5, 334, 55);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL, 328, 85);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL2, 345, 80);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL3, 360, 70);

	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL, 420, 185);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL1, 435, 179);

	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL3, 515, 50);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL5, 528, 70);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL, 530, 90);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL2, 545, 80);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL3, 550, 100);

	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL, 624, 160);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL4, 590, 160);

	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL, 700, 50);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL4, 725, 60);

	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL4, 785, 180);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL5, 815, 170);

	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL1, 920, 160);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL2, 930, 170);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL3, 940, 180);

	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL1, 990, 80);

	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL2, 1030, 180);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL3, 1045, 180);

	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL4, 1050, 110);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL, 1065, 100);

	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL4, 1170, 110);

	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL, 1340, 70);


	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL3, 1360, 110);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL5, 1350, 130);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL4, 1380, 140);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL, 1385, 150);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL3, 1400, 170);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL3, 1400, 170);
	//App->enemies->AddEnemy(ENEMY_TYPES::YELLOWBALL2, 1418  , 20);
	//App->enemies->AddEnemy(ENEMY_TYPES::YELLOWBALL2, 1455, 20);
	//App->enemies->AddEnemy(ENEMY_TYPES::YELLOWBALL, 1455, 202);
	//App->enemies->AddEnemy(ENEMY_TYPES::YELLOWBALL, 1558, 202);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL1, 1581, 130);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL1, 1608, 97);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL1, 1608, 154);

	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL, 1647, 117);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL5, 1647, 174);

	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL3, 1673, 146);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL5, 1682, 134);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL1, 1695, 116);
	//App->enemies->AddEnemy(ENEMY_TYPES::YELLOWBALL2, 1718, 20);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL2, 1837, 139);
	//App->enemies->AddEnemy(ENEMY_TYPES::YELLOWBALL2, 1863, 20);

	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL1, 1869, 63);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL5, 1877, 86);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL3, 1869, 113);

	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL2, 1938, 34);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL5, 1964, 62);

	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL4, 1986, 120);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL, 1986, 200);

	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL1, 1998, 62);

	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL1, 2100, 42);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL1, 2110, 32);

	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL1, 2152, 32);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL1, 2185, 46);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL1, 2201, 30);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL1, 2222, 46);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL1, 2235, 30);
	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL1, 2265, 30);

	//App->enemies->AddEnemy(ENEMY_TYPES::YELLOWBALL2, 2324, 20);
	//App->enemies->AddEnemy(ENEMY_TYPES::YELLOWBALL2, 2355, 20);
	//App->enemies->AddEnemy(ENEMY_TYPES::YELLOWBALL, 2355, 202);

	//App->enemies->AddEnemy(ENEMY_TYPES::REDBALL, 2385, 80); 


	//HUD hitbox
	HUDhitbox = App->collision->AddCollider({ 0, 0, SCREEN_WIDTH, 3 }, COLLIDER_HUD, this);

	//PowerUps
	//App->powerup->AddPowerUp(POWERUP_TYPES::SPEED_UP, 750, 100);
	//App->powerup->AddPowerUp(POWERUP_TYPES::POWERUP_ENEMY, 750, 87);
	App->powerup->AddPowerUp(POWERUP_TYPES::LASER, 500, 80);
	//Bomb
	/*App->powerup->AddPowerUp(POWERUP_TYPES::BOMB, 750, 123);
	App->powerup->AddPowerUp(POWERUP_TYPES::POWERUP_ENEMY, 750, 110);*/

	return true;
}

// UnLoad assets
bool ModuleLevel5::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(background);
	App->textures->Unload(tilemap1);
	App->textures->Unload(hud);

	App->enemies->Disable();
	App->collision->Disable();
	App->particles->Disable();
	App->player->Disable();
	App->powerup->Disable();

	return true;
}

// Update: draw background
update_status ModuleLevel5::Update()
{
	// Move camera forward -----------------------------
	if (App->render->camera.x < 4219)
	{
		App->render->camera.x += 1 * SCREEN_SIZE;
		App->player->position.x += 1; 
	}

	HUDhitbox->SetPos((App->render->camera.x)/1 , App->render->camera.y + 257);

	// Draw everything --------------------------------------
	App->render->Blit(background, 0, 0, &background_parallax, 0.75f, true); // backround
	App->render->Blit(tilemap1, 0, 0, &ground_parallax, 1.0f, true);
	App->render->Blit(hud, 0, 257, NULL, 0.0f, false);

	return UPDATE_CONTINUE;
}