#pragma once

namespace Tetra {

	// Context varies based on the render API used, the abstraction here provided
	// tries to make it so that any rendering done, doesn't need to change as the
	// platform changes. The Tetra Engine will automatically decide which render
	// API to use, based on the platform it's running on.

	class GraphicsContext 
	{
	public:
		virtual void Init() = 0;
		virtual void SwapBuffers() = 0;
	};
}