#include "trpch.h"
#include "VertexArray.h"

#include "Renderer.h"

#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Tetra {

	Tetra::VertexArray* VertexArray::Create(uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::None: TR_CORE_ASSERT(false, "RendererAPI::None is not supported"); return nullptr;
			case RendererAPI::OpenGL: return new OpenGLVertexArray(size);
		}

		return nullptr;
	}
}