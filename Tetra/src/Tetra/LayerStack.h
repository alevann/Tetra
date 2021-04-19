#pragma once

#include "Tetra/Core.h"

#include "Layer.h"
#include "Tetra/Events/Event.h"


namespace Tetra {

	// The layer stack is essentially a wrapper for the m_Layers vector.

	// Events on the layer stack will be iterated over reversely, because while
	// something like a gizmo's or the UI needs to be drawn last to be on top 
	// of everything, it also needs to be the first layer to receive the events.

	// When popping a layer, it is not deleted, that might cause a memory leak
	// if not handled properly. To make sure a layer is deleted, re-add it to the 
	// stack before the application closes or manually deallocate the memory.


	class TETRA_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		// Pushes the given layer at the begging of the list
		// Drawn first -- Receives events last
		void PushLayer(Layer* layer);
		// Pushes the given layer at the end of the list
		// Drawn last -- Receives events first
		void PushOverlay(Layer* layer);
		// Removes the given layer from the layer stack
		void PopLayer(Layer* layer);
		// Removes the given layer from the layer stack
		void PopOverlay(Layer* layer);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }

	private:
		std::vector<Layer*> m_Layers;
		unsigned int m_LayerInsertIndex = 0;
	};

}


