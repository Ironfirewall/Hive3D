#include "HivePreCompiledHeader.h"

#include "Application.h"

#include "Hive/Events/ApplicationEvent.h"
#include "Hive/Log.h"

#include <GLFW/glfw3.h>

namespace Hive {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		//MouseButtonEve
		if (e.IsInCategory(EventCategoryApplication)) {
			HV_CORE_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput)) {
			HV_CORE_TRACE(e);
		}
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}
