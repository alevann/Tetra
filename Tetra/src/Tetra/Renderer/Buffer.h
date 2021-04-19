#pragma once

namespace Tetra {

	// An abstraction of a vertex buffer, the purpose of the abstraction
	// is to offer an interface to each supported RenderAPI, without the
	// need to actually implement code that depends on any one in particular.

	// A vertex buffer, (also called VBO or vertex buffer object) is a 
	// rendering resource which holds vertex data, it can be connected 
	// by primitive indices which allow to render geometric primitives 
	// such as triangles.
	// They offer ways to upload vertex data to the graphic card, for
	// non immediate rendering; this method of uploading data is substantially 
	// faster compared to immediate rendering, because the data is stored 
	// in the graphic card's memory rather than the system memory, and 
	// so it can be rendered directly by the latter.

	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() {}

		// Binding a VBO, is basically, telling the computer "Hey, from now on,
		// until further notice, I'm working with this object."
		virtual void Bind() const = 0;
		// While unbinding a VBO, (as of right now) we just bind said VBO to 0
		// why that happens, I don't know.
		virtual void Unbind() const = 0;
		
		// Instances the correct type of vertex buffer, based on the type of API
		// that is currently in use.
		// For example it will return a DirectX vertex buffer on window, and a
		// Vulcan vertex buffer while on a Unix system.
		static VertexBuffer* Create(float* vertices, uint32_t size);
	};

	// An abstraction of an index buffer, the purpose of the abstraction
	// is to offer an interface to each supported RenderAPI, without the
	// need to actually implement code that depends on any one in particular.

	// An index buffer is basically, an array of pointers INTO the VBO.
	// This allows to re-order the vertex data, and re-use existing data
	// for multiple vertices.
	// You can only have a single index buffer, it's not possible to use
	// different indices for each vertex attribute.

	class IndexBuffer
	{
	public:
		virtual ~IndexBuffer() {}

		// When binding an index buffer, we effectively activate it telling the
		// computer, the order in which we want to draw things.
		virtual void Bind() const = 0;
		// While unbinding an index buffer, (as of right now) we just bind said 
		// index buffer to 0 why that happens, I don't know.
		virtual void Unbind() const = 0;

		// Returns the "length" (or amount of indices) contained in the object.
		virtual uint32_t GetCount() const = 0;

		// Instances the correct type of index buffer, based on the type of API
		// that is currently in use.
		// For example it will return a DirectX index buffer on window, and a
		// Vulcan index buffer while on a Unix system.
		static IndexBuffer* Create(uint32_t* indices, uint32_t size);
	};
}