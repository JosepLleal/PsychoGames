#ifndef __ModuleMixer_H__
#define __ModuleMixer_H__

#include "Module.h"

struct Mix_Chunk;

typedef struct _Mix_Music Mix_Music;

class ModuleMixer : public Module
{
public:
	ModuleMixer();
	~ModuleMixer();

	bool Init();
	bool CleanUp();

public:

	Mix_Music * music = nullptr;

};



#endif //_ModuleMixer_H_
