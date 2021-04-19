#include <Tetra.h>

#include "imgui/imgui.h"

class DebugLayer : public Tetra::Layer
{
public:
	DebugLayer()
		: Layer("Debug") {}
	
	void OnUpdate() override 
	{
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Hallo");
		ImGui::Text("Hello world!");
		ImGui::End();
	}

	void OnEvent(Tetra::Event& event) override
	{
		Tetra::KeyPressedEvent& e = (Tetra::KeyPressedEvent&)event;
	}
};

class Sandbox : public Tetra::Application 
{
public:
	Sandbox()
	{
		PushLayer(new DebugLayer());
	}

	~Sandbox() 
	{

	}
};

Tetra::Application* Tetra::CreateApplication()
{
	return new Sandbox();
}