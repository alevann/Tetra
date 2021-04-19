#include "trpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <Glad/glad.h>
#include <GL/GL.h>

namespace Tetra {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle) 
	{
		TR_CORE_ASSERT(windowHandle, "Window Handle is null in OpenGLContext")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);

		// Initialize GLAD
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		TR_CORE_ASSERT(status, "Could not initialize GLAD");

		TR_CORE_INFO("OpenGL info:");
		TR_CORE_INFO("  Vendor : {0}", glGetString(GL_VENDOR));
		TR_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
		TR_CORE_INFO("  Rederer: {0}", glGetString(GL_RENDERER));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}