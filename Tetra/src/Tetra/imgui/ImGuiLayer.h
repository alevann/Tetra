#pragma once

#include "Tetra/Layer.h"
#include <Tetra\Events\ApplicationEvent.h>
#include <Tetra\Events\MouseEvent.h>
#include <Tetra\Events\KeyEvent.h>

namespace Tetra {

	class TETRA_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate() override;
		virtual void OnImGuiRender() override;
		
		// Starts a new frame
		void Begin();
		void End();

	private:
		float m_Time = 0.0f;

		static std::string s_CopiedText;
	};
}