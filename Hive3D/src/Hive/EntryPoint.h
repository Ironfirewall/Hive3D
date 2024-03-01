#pragma once

#ifdef HV_PLATFORM_WINDOWS

extern Hive::Application* Hive::CreateApplication();

int main(int argc, char** argv) {
	//Sandbox* sandbox = new Sandbox();
	printf("Starting up the engine!");
	auto app = Hive::CreateApplication();
	app->Run();
	delete app;
}

#endif