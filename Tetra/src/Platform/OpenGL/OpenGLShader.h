#pragma once

#include "Tetra/Renderer/Shader.h"

namespace Tetra {

	// A shader is the algorithm that calculates what color a certain
	// pixel on the screen should be.
	// There's two kinds of shaders (AFAIK), vertex shaders which determine
	// where on the screen a vertex is; fragment shaders which actually
	// calculate the color of the pixel.

	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc);
		virtual ~OpenGLShader();

		virtual void Bind() const override;
		virtual void Unbind() const override;

	private:
		unsigned int m_RendererID;
	};
}