#pragma once

#include "Core.h"

#include "Window.h"
#include "Tetra/LayerStack.h"
#include "Tetra/Events/Event.h"
#include "Tetra/Events/ApplicationEvent.h"

#include "Tetra/imgui/ImGuiLayer.h"

#include "Tetra/Renderer/Shader.h"
#include "Tetra/Renderer/Buffer.h"
#include "Tetra/Renderer/VertexArray.h"

namespace Tetra {

	class TETRA_API Application
	{
	public:
		Application();
		virtual ~Application();

		// The main loop of the app, currently consists of three steps:
		// Clear: This step is pretty simple, it just clears the screen
		// OnUpdate:
		//		This step is actually composed of two steps, first the window
		//		is updated, then each layer is updated.
		void Run();
		void OnEvent(Event& event);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		std::unique_ptr<Shader> m_Shader;
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;
		std::unique_ptr<VertexArray> m_VertexArray;

	private:
		static Application* s_Instance;
	};

	// To be defined in the client.
	Application* CreateApplication();

}

