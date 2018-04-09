#ifndef __ModuleAudio_H__
#define __ModuleAudio_H__

#include "Module.h"
#include "Globals.h"
#include "ModuleInput.h"

typedef struct _Mix_Music Mix_Music;

enum StageStatus 
{
	MAIN_MENU,
	STAGE_1,
	STAGE_2,
	END_MENU
};

class ModuleAudio : public Module
{

public:
	ModuleAudio();
	~ModuleAudio();

	bool Init();
	bool Start();
	update_status Update();
	bool CleanUp();

	void LoadMusic(Mix_Music* music, char* audioPath);

public:

	int currentScreen = StageStatus::MAIN_MENU;	
	bool musicRunning = false;		

	Mix_Music * music = nullptr;

};

#endif