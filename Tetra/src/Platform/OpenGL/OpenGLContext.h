#pragma once

#include "Tetra/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Tetra {

	// This is the implementation of the context for the OpenGL3 API
	// It basically is a reference to where we can draw on the screen

	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;
	private:
		GLFWwindow* m_WindowHandle;
	};

}