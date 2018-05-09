#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "SDL/include/SDL.h"

ModuleInput::ModuleInput() : Module()
{
	for(uint i = 0; i < MAX_KEYS; ++i)
		keyboard[i] = KEY_IDLE;
}

// Destructor
ModuleInput::~ModuleInput()
{
}

// Called before render is available
bool ModuleInput::Init()
{
	LOG("Init SDL input event system");
	bool ret = true;
	SDL_Init(0);

	if(SDL_InitSubSystem(SDL_INIT_EVENTS) < 0)
	{
		LOG("SDL_EVENTS could not initialize! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}

	if (SDL_Init(SDL_INIT_GAMECONTROLLER) < 0)
	{
		LOG("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		ret = false;
	}

	if (SDL_Init(SDL_INIT_JOYSTICK) < 0)
	{
		LOG("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		ret = false;
	}

	for (int i = 0; i < SDL_NumJoysticks(); ++i) 
	{
		if (SDL_IsGameController(i)) {
			gamepad = SDL_GameControllerOpen(i);
			if (gamepad) {
				break;
			}
			else {
				LOG("Could not open gamecontroller");
			}
		}
	}

	if (SDL_NumJoysticks() > 0) 
	{
		// Open joystick
		joy1 = SDL_JoystickOpen(0);
	}

	

	return ret;
}

// Called every draw update
update_status ModuleInput::PreUpdate()
{
	SDL_PumpEvents();

	const Uint8* keys = SDL_GetKeyboardState(NULL);

	for(int i = 0; i < MAX_KEYS; ++i)
	{
		if(keys[i] == 1)
		{
			if(keyboard[i] == KEY_IDLE)
				keyboard[i] = KEY_DOWN;
			else
				keyboard[i] = KEY_REPEAT;
		}
		else
		{
			if(keyboard[i] == KEY_REPEAT || keyboard[i] == KEY_DOWN)
				keyboard[i] = KEY_UP;
			else
				keyboard[i] = KEY_IDLE;
		}
	}

	controller_state[UP] = SDL_GameControllerGetButton(gamepad, SDL_CONTROLLER_BUTTON_DPAD_UP);
	controller_state[DOWN] = SDL_GameControllerGetButton(gamepad, SDL_CONTROLLER_BUTTON_DPAD_DOWN);
	controller_state[LEFT] = SDL_GameControllerGetButton(gamepad, SDL_CONTROLLER_BUTTON_DPAD_LEFT);
	controller_state[RIGHT] = SDL_GameControllerGetButton(gamepad, SDL_CONTROLLER_BUTTON_DPAD_RIGHT);
	controller_state[BUTTON_A] = SDL_GameControllerGetButton(gamepad, SDL_CONTROLLER_BUTTON_A);

	for (int i = 0; i < MAX_BUTTONS; ++i)
	{
		if (controller_state[i] == 1) {
			if (controller[i] == KEY_IDLE)
				controller[i] = KEY_DOWN;
			else
				controller[i] = KEY_REPEAT;
		}
		else
		{
			if (controller[i] == KEY_REPEAT || controller[i] == KEY_DOWN)
				controller[i] = KEY_UP;
			else
				controller[i] = KEY_IDLE;
		}
	}

	x_move = SDL_JoystickGetAxis(joy1, 0);
	y_move = SDL_JoystickGetAxis(joy1, 1);

	if(keyboard[SDL_SCANCODE_ESCAPE])
		return update_status::UPDATE_STOP;


	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleInput::CleanUp()
{
	SDL_GameControllerClose(gamepad);
	gamepad = NULL;

	// Close if opened
	if (SDL_JoystickGetAttached(joy1)) {
		SDL_JoystickClose(joy1);
	}

	LOG("Quitting SDL input event subsystem");
	SDL_QuitSubSystem(SDL_INIT_EVENTS);
	return true;

}