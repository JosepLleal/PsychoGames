#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleMixer.h"

#include "SDL/include/SDL.h"
#include "SDL_mixer/include/SDL_mixer.h"

#pragma comment (lib, "SDL_mixer/libx86/SDL2_mixer.lib")

ModuleMixer::ModuleMixer() : Module()
{}

// Destructor
ModuleMixer::~ModuleMixer()
{}

bool ModuleMixer::Init()
{
	LOG("Init Audio SDL and library");

	bool ret = true;

	if (SDL_Init(SDL_INIT_AUDIO) < 0)
	{
		LOG("SDL_AUDIO could not initialize! SDL_Error:\n");

		LOG(SDL_GetError());

		ret = false;
	}

	else {

		int init = Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096); // frequency, Uint16 format, channel, chunksize

		if (init == -1)
		{
			LOG("Could not initialize Mixer lib. Mix_Init: %s", Mix_GetError());
			ret = false;
		}

		//Load music and sound if everything initialized correctly

		music = Mix_LoadMUS("Assets/04_Into_the_Human_Body_Stage_1_.ogg");

		Mix_FadeInMusic(music, -1, 2000); //pointer to where the music is (already loaded), 0 don't play music and -1 to loop 
										  //forever the music, milisecond in which the fade in enters

	}
	return ret;
}

bool ModuleMixer::CleanUp() {

	Mix_FreeMusic(music);

	Mix_CloseAudio();

	return true;
}