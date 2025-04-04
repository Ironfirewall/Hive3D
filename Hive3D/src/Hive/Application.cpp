#include "HivePreCompiledHeader.h"

#include "Application.h"

#include "Hive/Events/ApplicationEvent.h"
#include "Hive/Events/KeyEvent.h"
#include "Hive/Events/MouseEvent.h"

#include <GLFW/glfw3.h>

namespace Hive {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{

	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		HV_CORE_TRACE("{0}", e);
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

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}
