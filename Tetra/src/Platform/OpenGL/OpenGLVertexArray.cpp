#include "trpch.h"
#include "OpenGLVertexArray.h"

#include <glad/glad.h>

namespace Tetra {

	OpenGLVertexArray::OpenGLVertexArray(uint32_t size)
	{
		glGenVertexArrays(size, &m_RendererID);
	}

	OpenGLVertexArray::~OpenGLVertexArray() {}

	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(m_RendererID);
	}

	void OpenGLVertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}
}