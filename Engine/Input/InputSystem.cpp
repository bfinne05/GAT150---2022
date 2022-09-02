#include "InputSystem.h"
#include <SDL.h>
#include <iostream>

namespace gre
{
	const uint32_t key_space = SDL_SCANCODE_SPACE;
	const uint32_t key_up = SDL_SCANCODE_UP;
	const uint32_t key_down = SDL_SCANCODE_DOWN;
	const uint32_t key_left = SDL_SCANCODE_LEFT;
	const uint32_t key_right = SDL_SCANCODE_RIGHT;
	const uint32_t key_z = SDL_SCANCODE_Z;

	const uint32_t key_w = SDL_SCANCODE_W;
	const uint32_t key_a = SDL_SCANCODE_A;
	const uint32_t key_s = SDL_SCANCODE_S;
	const uint32_t key_d= SDL_SCANCODE_D;

	const uint32_t button_left = 0;
	const uint32_t button_middle = 1;
	const uint32_t button_right = 2;

	const uint32_t key_tab = SDL_SCANCODE_TAB;

	const uint32_t key_escape = SDL_SCANCODE_ESCAPE;

void gre::InputSystem::Initialize()
{
	const uint8_t* keyboardState = SDL_GetKeyboardState(&m_numKeys);

	m_keyboardState.resize(m_numKeys);
	std::copy(keyboardState, keyboardState + m_numKeys, m_keyboardState.begin());

	m_prevKeyboardState = m_keyboardState;
}

void gre::InputSystem::ShutDown()
{
	//
}

void gre::InputSystem::Update()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	//save previous keyboard state
	m_prevKeyboardState = m_keyboardState;

	//get current keyboard state
	const uint8_t* keyboardState = SDL_GetKeyboardState(nullptr);
	std::copy(keyboardState, keyboardState + m_numKeys, m_keyboardState.begin());
	//gets mouse state

	m_prevmouseButtonState = m_mouseButtonState;
	int x, y;
	uint32_t buttons = SDL_GetMouseState(&x, &y);
	m_mousePosition = gre::Vector2{ x , y };
	m_mouseButtonState[0] = buttons & SDL_BUTTON_LMASK; // buttons [0001] & [0RML] 
	m_mouseButtonState[1] = buttons & SDL_BUTTON_MMASK; // buttons [0010] & [0RML] 
	m_mouseButtonState[2] = buttons & SDL_BUTTON_RMASK; // buttons [0100] & [0RML] 
}
InputSystem::KeyState InputSystem::GetKeyState(uint32_t key)
{
	KeyState keyState = KeyState::Idle;

	bool keyDown = GetKeyDown(key);
	bool prevKeyDown = GetPreviousKeyDown(key);

	// set the keyState if keyDown (true) and prevKeyDown (true)
	if (keyDown == true && prevKeyDown == true) {keyState = Held;}
	// set the keyState if keyDown (true) and prevKeyDown (false) 
	if (keyDown == true && prevKeyDown == false) {keyState = Pressed;}
	// set the keyState if keyDown (false) and prevKeyDown (true) 
	if (keyDown == false && prevKeyDown == true) {keyState = Released;}
	// set the keyState if keyDown (false) and prevKeyDown (false) 
	if (keyDown == false && prevKeyDown == false) {keyState = Idle;}
	
	return keyState;
}

InputSystem::KeyState InputSystem::GetButtonState(uint32_t button)
{
	KeyState keyState = KeyState::Idle;

	bool buttonDown = GetButtonDown(button);
	bool prevButtonDown = GetPreviousButtonDown(button);

	// set the keyState if buttonDown (true) and prevButtonDown (true) 
	if (buttonDown == true && prevButtonDown == true)
	{
		keyState = Held;
	}
	// set the keyState if keyDown (true) and prevKeyDown (false) 
	if (buttonDown == true && prevButtonDown == false)
	{
		keyState = Pressed;
	}
	// set the keyState if keyDown (false) and prevKeyDown (true) 
	if (buttonDown == false && prevButtonDown == true)
	{
		keyState == Released;
	}
	// set the keyState if keyDown (false) and prevKeyDown (false) 
	if (buttonDown == false && prevButtonDown == false)
	{
		keyState = Idle;
	}

	return keyState;
}



}