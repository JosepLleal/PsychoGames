#ifndef __ModuleAudio_H__
#define __ModuleAudio_H__

#include "Module.h"

struct Mix_Chunk;

typedef struct _Mix_Music Mix_Music;

class ModuleAudio : public Module
{
public:
	ModuleAudio();
	~ModuleAudio();

	bool Init();
	bool CleanUp();

public:

	//music file
	Mix_Music * music = nullptr;

};



#endif //_ModuleAudio_H__
