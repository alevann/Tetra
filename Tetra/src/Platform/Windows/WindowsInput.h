#pragma once

#include "Tetra/Input.h"

namespace Tetra {

	class WindowsInput : public Input
	{
	protected:
		// Returns whether a key is pressed or not, true if pressed or repeat
		// false otherwise
		virtual bool IsKeyPressedImpl(int keycode) override;
		// Returns whether a mouse button is pressed or not
		virtual bool IsMouseButtonPressedImpl(int button) override;

		virtual std::pair<float, float> GetMousePositionImpl() override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
	};

}