#pragma once

#ifdef EA_PLATFORM_WINDOWS

extern EngineA::Application* EngineA::CreateApplication();
	
int main(int argc, char** argv)
{
	auto app = EngineA::CreateApplication();
	app->Run();
	delete app;
}

#endif