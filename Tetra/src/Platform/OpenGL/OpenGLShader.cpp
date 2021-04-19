#include "trpch.h"
#include "OpenGLShader.h"

#include <glad/glad.h>

static void TerminateShaderProc(const GLuint shader, const std::string err);
static GLint CompileShaderSource(const GLuint shader, const std::string src);

namespace Tetra {

	OpenGLShader::OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc)
		: m_RendererID(0)
	{
		// Create an empty vertex shader handle
		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

		// Compile the vertex shader
		GLint isCompiled = CompileShaderSource(vertexShader, vertexSrc);
		if (isCompiled == GL_FALSE)
		{
			TerminateShaderProc(vertexShader, "Vertex shader compilation error");
			return;
		}

		// Create an empty fragment shader handle
		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		// Compile the fragment shader
		isCompiled = CompileShaderSource(fragmentShader, fragmentSrc);
		if (isCompiled == GL_FALSE)
		{
			TerminateShaderProc(fragmentShader, "Fragment shader compilation error");
			return;
		}

		// With vertex and fragment shaders compiled we can link them into a program.
		m_RendererID = glCreateProgram();

		// Attach our shaders to our program
		glAttachShader(m_RendererID, vertexShader);
		glAttachShader(m_RendererID, fragmentShader);

		// Link our program
		glLinkProgram(m_RendererID);

		// Note the different functions here: glGetProgram* instead of glGetShader*.
		GLint isLinked = 0;
		glGetProgramiv(m_RendererID, GL_LINK_STATUS, (int*)&isLinked);
		if (isLinked == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetProgramiv(m_RendererID, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			std::vector<GLchar> infoLog(maxLength);
			glGetProgramInfoLog(m_RendererID, maxLength, &maxLength, &infoLog[0]);

			// We don't need the program anymore.
			glDeleteProgram(m_RendererID);
			// Don't leak shaders either.
			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);

			TR_CORE_ERROR("{0}", infoLog.data());
			TR_CORE_ASSERT(false, "Shader linking shader compilation error");

			return;
		}

		// Always detach shaders after a successful link.
		glDetachShader(m_RendererID, vertexShader);
		glDetachShader(m_RendererID, fragmentShader);
	}

	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(m_RendererID);
	}

	void OpenGLShader::Bind() const
	{
		glUseProgram(m_RendererID);
	}

	void OpenGLShader::Unbind() const
	{
		glUseProgram(0);
	}

}

// Called when something went wrong while compiling a shader,
	// updates the shader output log, then proceeds to eliminate
	// the shader to avoid any memory leaks
static void TerminateShaderProc(const GLuint shader, const std::string err)
{
	GLint maxLength = 0;
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

	// The maxLength includes the NULL character
	std::vector<GLchar> infoLog(maxLength);
	glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);

	// We don't need the program anymore.
	glDeleteShader(shader);

	TR_CORE_ERROR("{0}", infoLog.data());
	TR_CORE_ASSERT(false, err);
}

// Compiles the source of a shader then returns the compilation
// result
static GLint CompileShaderSource(const GLuint shader, const std::string src)
{
	// Send the shader source code to GL
	// Note that std::string's .c_str is NULL character terminated.
	const GLchar* source = src.c_str();
	glShaderSource(shader, 1, &source, 0);

	glCompileShader(shader);

	GLint isCompiled = 0;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
	return isCompiled;
}