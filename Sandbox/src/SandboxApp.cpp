#include "EngineA.h"


class Sandbox : public EngineA::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

EngineA::Application* EngineA::CreateApplication()
{
	return new Sandbox();
}