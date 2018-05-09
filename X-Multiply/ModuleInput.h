#ifndef __ModuleInput_H__
#define __ModuleInput_H__

#include "Module.h"
#include "Globals.h"
#include "SDL\include\SDL_scancode.h"
#include "SDL\include\SDL_gamecontroller.h"

#define MAX_KEYS 300
#define MAX_BUTTONS 5

enum KEY_STATE
{
	KEY_IDLE = 0,
	KEY_DOWN,
	KEY_REPEAT,
	KEY_UP
};

enum BUTTONS {
	DOWN = 0,
	UP,
	LEFT,
	RIGHT,
	BUTTON_A
};


class ModuleInput : public Module
{
public:
	
	ModuleInput();
	~ModuleInput();

	bool Init();
	update_status PreUpdate();
	bool CleanUp();

public:
	KEY_STATE keyboard[MAX_KEYS];

	SDL_GameController *gamepad = NULL;
	SDL_Joystick* joy1;
	Sint16 x_move, y_move;

	bool controller_state[MAX_BUTTONS];
	KEY_STATE controller[MAX_BUTTONS];
};

#endif // __ModuleInput_H__