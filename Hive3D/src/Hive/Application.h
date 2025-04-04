#pragma once

#include "Core.h"

#include "Events/Event.h"
#include "Hive/Events/ApplicationEvent.h"
#include "Hive/LayerStack.h"
#include "Window.h"

namespace Hive {
	class HAPI Application
	{
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

		bool OnWindowClose(WindowCloseEvent& e);

	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	};

	Application* CreateApplication();
}

