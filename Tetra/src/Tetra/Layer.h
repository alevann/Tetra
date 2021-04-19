#pragma once

#include "Tetra/Core.h"
#include "Tetra/Events/Event.h"

namespace Tetra {

	// A layer is collection of stuff, the layer itself determines when the items inside
	// of the collection are updated, if they receive certain events, if the events
	// will propagate further or not, etc...
	// This means that a layer is kinda like a photoshop layer, but not limited to the graphics
	// side of things.

	// TODO: implement m_Disabled here, or keep track of disabled layers in the Layer Stack

	class TETRA_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		// Called when a layer is pushed onto the layer stack
		virtual void OnAttach() {}
		// Called when a layer is removed from the layer stack
		virtual void OnDetach() {}
		// Called every frame to update all members of the layer
		virtual void OnUpdate() {}
		// Dunno when it's called
		virtual void OnImGuiRender() {}
		// Called when an event happens to notify all members of the layer
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;
	};

}

