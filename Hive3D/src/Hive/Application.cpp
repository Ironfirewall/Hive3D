#include "Application.h"

#include "Hive/Events/ApplicationEvent.h"
#include "Hive/Log.h"

namespace Hive {

	Application::Application()
	{

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
		while (true);
	}
}
