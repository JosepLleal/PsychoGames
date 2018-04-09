#include "Globals.h"
#include "Application.h"
#include "ModuleAudio.h"
#include "SDL/include/SDL.h"
#include "SDL_mixer/include/SDL_mixer.h"
#include "ModuleMenu.h"

#pragma comment (lib, "SDL_mixer/libx86/SDL2_mixer.lib")

#define MUSIC 50

ModuleAudio::ModuleAudio() : Module() {}

ModuleAudio::~ModuleAudio() {}

bool ModuleAudio::Init()
{
	LOG("Creating the music");
	bool ret = true;

	if (SDL_Init(SDL_INIT_AUDIO) != 0)
	{
		LOG("Broken: %s ", SDL_GetError());
		ret = false;
	}

	else
	{
		// Initialize Audio
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);

	}

	return ret;
}

bool ModuleAudio::Start()	//load the start music
{
	// Music
	LoadMusic(music, "Sound/01_X-Multiply_Title_.ogg");

	return true;
}

update_status ModuleAudio::Update()
{

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1)	
	{
		currentScreen++;

		musicRunning = false;

	}

	if (currentScreen == StageStatus::MAIN_MENU && musicRunning == false)
	{

		music = Mix_LoadMUS("Sound/01_X-Multiply_Title_.ogg");
		Mix_FadeInMusic(music, 1, 1000);
		Mix_VolumeMusic(MUSIC);
		
		musicRunning = true; 

	}

	else if (currentScreen == StageStatus::STAGE_1 && musicRunning == false)
	{

		music = Mix_LoadMUS("Sound/04_Into_the_Human_Body_Stage_1_.ogg");
		Mix_FadeInMusic(music, 1, 1000);
		Mix_VolumeMusic(MUSIC);

		musicRunning = true;
	}

	else if (currentScreen == StageStatus::STAGE_2 && musicRunning == false)
	{

		music = Mix_LoadMUS("Sound/07_Babe_Good-Lookin_Stage_2_.ogg");
		Mix_FadeInMusic(music, 1, 1000);
		Mix_VolumeMusic(MUSIC);

		musicRunning = true;
	}

	else if (currentScreen == StageStatus::END_MENU && musicRunning == false)
	{

		music = Mix_LoadMUS("Sound/15_Body_Scratchers_Name_Entry_.ogg");
		Mix_FadeInMusic(music, 1, 1000);
		Mix_VolumeMusic(MUSIC);

		musicRunning = true; 
	}
	 
	else 
	{
		currentScreen = StageStatus::MAIN_MENU;
	}

	return update_status::UPDATE_CONTINUE;
}

bool ModuleAudio::CleanUp()
{
	if (music != nullptr)
	{
		Mix_FreeMusic(music);
	}

	Mix_Quit();

	return true;
}

void ModuleAudio::LoadMusic(Mix_Music* music, char* audioPath)
{
	bool ret = true;

	music = Mix_LoadMUS(audioPath);

	if (music == nullptr)
	{
		LOG("Couldn't load music: %s", SDL_GetError());
		ret = false;
	}

	else
	{
		Mix_FadeInMusic(music, 1, 1000);
		Mix_VolumeMusic(MUSIC);
	}
}