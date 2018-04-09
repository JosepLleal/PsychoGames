#ifndef __ModuleAudio_H__
#define __ModuleAudio_H__

#include "Module.h"
#include "Globals.h"


typedef struct _Mix_Music Mix_Music;



class ModuleAudio : public Module
{

public:
	ModuleAudio();
	~ModuleAudio();

	bool Init();
	bool CleanUp();

	bool MusicPlay(const char * path, float fade_time);

public:

	Mix_Music * music = nullptr;


};

#endif