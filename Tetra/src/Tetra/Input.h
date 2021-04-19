#pragma once

#include "Tetra/Core.h"

namespace Tetra {

	// TODO: Add GetKeyDown() which returns true on only the first frame of a Key or button down
	// TODO: Implement a conversion table for the key codes and the different frameworks I'll implement eventually
	//		Note: do it when I implement the frameworks, not earlier.

	class TETRA_API Input 
	{
	public:
		// Returns whether a key is pressed or not, 
		// for more specific info check out each implementation
		inline static bool IsKeyPressed(int keycode) { return s_Instance->IsKeyPressedImpl(keycode); }


		// Returns whether a mouse button is pressed or not, for more specific info check out each implementation
		inline static bool IsMouseButtonPressed(int button) { return s_Instance->IsMouseButtonPressedImpl(button); }
		// Returns the position of the mouse on both the X and Y axis
		inline static std::pair<float, float> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }
		// Returns the position of the mouse on the X axis
		inline static float GetMouseX() { return s_Instance->GetMouseXImpl(); }
		// Returns the position of the mouse on the Y axis
		inline static float GetMouseY() { return s_Instance->GetMouseYImpl(); }

	protected:
		virtual bool IsKeyPressedImpl(int keycode) = 0;

		virtual bool IsMouseButtonPressedImpl(int button) = 0;
		virtual std::pair<float, float> GetMousePositionImpl() = 0;
		virtual float GetMouseXImpl() = 0;
		virtual float GetMouseYImpl() = 0;

	private:
		static Input* s_Instance;
	};

}