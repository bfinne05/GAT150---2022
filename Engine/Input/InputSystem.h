#pragma once
#include "../Math/Vector2.h"
#include <cstdint>
#include <vector>
#include <array>

namespace gre
{
	class InputSystem
	{
	public: 
		enum KeyState
		{
			Idle,
			Pressed,
			Held,
			Released

		};

	public:
		InputSystem() = default;
		~InputSystem() = default;

		void Initialize();
		void ShutDown();

		void Update();


		KeyState GetKeyState(uint32_t key);
		bool GetKeyDown(uint32_t key) { return m_keyboardState[key]; }
		bool GetPreviousKeyDown(uint32_t key) { return m_prevKeyboardState[key]; }

		
		const Vector2& GetMousePosition() const { return m_mousePosition; }
		
		KeyState GetButtonState(uint32_t button);
		bool GetButtonDown(uint32_t button) { return m_mouseButtonState[button]; }
		bool GetPreviousButtonDown(uint32_t button) {return m_prevmouseButtonState[button];}

	private:
		int m_numKeys;
		//keyboard
		std::vector<uint8_t> m_keyboardState;
		std::vector<uint8_t> m_prevKeyboardState;
		//mouse
		Vector2 m_mousePosition;
		std::array<uint8_t, 3> m_mouseButtonState;
		std::array<uint8_t, 3> m_prevmouseButtonState;
	};
	//arrow keys
	extern const uint32_t key_space;
	extern const uint32_t key_up;
	extern const uint32_t key_down;
	extern const uint32_t key_left;
	extern const uint32_t key_right;
	//wasd
	extern const uint32_t key_w;
	extern const uint32_t key_a;
	extern const uint32_t key_s;
	extern const uint32_t key_d;

	extern const uint32_t key_tab;
	//mouse
	extern const uint32_t button_left;
	extern const uint32_t button_middle;
	extern const uint32_t button_right;
	//escape
	extern const uint32_t key_escape;

}