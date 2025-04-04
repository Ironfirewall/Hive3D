#pragma once

#ifdef HV_PLATFORM_WINDOWS

extern Hive::Application* Hive::CreateApplication();

int main(int argc, char** argv) {
	//Sandbox* sandbox = new Sandbox();
	//printf("Starting up the engine!\n");

	Hive::Log::Init();
	HV_CORE_WARN("Initialized Core Logger!");
	HV_INFO("Initialized Client Logger!");
	HV_CORE_INFO("Starting up the engine!");

	auto app = Hive::CreateApplication();
	app->Run();
	delete app;
}

#endif