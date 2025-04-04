#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace Hive {
	class HAPI Application
	{
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	};

	Application* CreateApplication();
}

