
#include "Hive.h"

class ExampleLayer : public Hive::Layer
{
public:
	ExampleLayer() : Layer("Example")
	{
	}

	void OnUpdate() override
	{
		HV_INFO("ExampleLayer::Update");
	}

	void OnEvent(Hive::Event& event) override
	{
		HV_TRACE("{0}", event);
	}
};

class Sandbox : public Hive::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Hive::Application* Hive::CreateApplication()
{
	return new Sandbox();
}