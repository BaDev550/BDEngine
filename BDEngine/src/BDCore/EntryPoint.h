#pragma once

#ifdef BD_PLATFORM_WINDOWS

extern BDE_ApplicationCore::Application* BDE_ApplicationCore::CreateApplication();

int main(int argc, char** argv) 
{
	BDE_ApplicationCore::Log::Init();
	BDE_CORE_WARN("Initialized Log!");
	int a = 5;
	BDE_INFO("The test variable is={0}", a);

	auto app = BDE_ApplicationCore::CreateApplication();
	app->Run();
	delete app;
}

#endif

