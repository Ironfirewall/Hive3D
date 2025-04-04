#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Hive/Events/ApplicationEvent.h"
#include "Window.h"

namespace Hive {
	class HAPI Application
	{
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		bool OnWindowClose(WindowCloseEvent& e);

	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	};

	Application* CreateApplication();
}

