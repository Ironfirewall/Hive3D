#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Hive {
	class HAPI Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}

