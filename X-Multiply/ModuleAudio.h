#ifndef __ModuleAudio_H__
#define __ModuleAudio_H__

#include "Module.h"
#include "Globals.h"


typedef struct _Mix_Music Mix_Music;
struct Mix_Chunk; 

class ModuleAudio : public Module
{

public:
	ModuleAudio();
	~ModuleAudio();

	bool Init();
	bool CleanUp();

	bool MusicPlay(const char * path, float fade_time);
	bool ChunkPlay(const char* path);

	bool UnloadFX(uint id); 

public:

	Mix_Music * music = nullptr;
	Mix_Chunk * FX = nullptr;

};

#endif