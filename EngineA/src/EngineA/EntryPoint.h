#pragma once

#ifdef EA_PLATFORM_WINDOWS

extern EngineA::Application* EngineA::CreateApplication();
	
int main(int argc, char** argv)
{
	EngineA::Log::Init();
	EA_CORE_WARN("Initialized Log!");
	int a = 123;
	EA_INFO("Info Var={0}", a);

	auto app = EngineA::CreateApplication();
	app->Run();
	delete app;
}

#endif