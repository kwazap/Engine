#include "eapch.h"
#include "Application.h"

#include "EngineA/Events/ApplicationEvent.h"
#include "EngineA/Log.h"

namespace EngineA {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (m_Runing)
		{
			m_Window->OnUpdate();
		}
	}

}