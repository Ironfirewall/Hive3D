#pragma once

#include "Core.h"

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

