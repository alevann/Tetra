#pragma once

#include "Tetra/Renderer/VertexArray.h"

namespace Tetra {

	class OpenGLVertexArray : public VertexArray
	{
	public:
		OpenGLVertexArray(uint32_t size);
		virtual ~OpenGLVertexArray() override;

		virtual void Bind() const override;
		virtual void Unbind() const override;

	private:
		uint32_t m_RendererID;
	};

}

