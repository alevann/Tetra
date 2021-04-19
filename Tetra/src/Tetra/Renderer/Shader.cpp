#include "trpch.h"
#include "Shader.h"

#include "Platform/OpenGL/OpenGLShader.h"

#include "Tetra/Renderer/Renderer.h"

#include <glad/glad.h>

namespace Tetra {

	Tetra::Shader* Shader::Create(const std::string vertexSrc, const std::string fragmentSrc)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::None: TR_CORE_ASSERT(false, "RenderAPI::None is not supported"); return nullptr;
			case RendererAPI::OpenGL: return new OpenGLShader(vertexSrc, fragmentSrc);
		}

		return nullptr;
	}

}