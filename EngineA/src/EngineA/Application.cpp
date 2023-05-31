#include "Application.h"

#include "EngineA/Events/ApplicationEvent.h"
#include "EngineA/Log.h"

namespace EngineA {

	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1200, 700);
		EA_TRACE(e);

		while (true);
	}

}