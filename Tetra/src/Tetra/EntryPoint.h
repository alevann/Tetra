#pragma once

#ifdef TR_PLATFORM_WINDOWS

/**
 * Moved inside the Tetra's Engine code, because we might need more
 * control on the app, especially in windows with all the win32 APIs and stuff.
 */

// Declare that there's a Tetra Application.
extern Tetra::Application* Tetra::CreateApplication();

int main(int argc, char** argv) 
{
	Tetra::Log::Init();
	TR_CORE_INFO("Initialized the logging system!");
	TR_CORE_TRACE("Supports variables: {0}", true);

	// Instance the Tetra Application
	auto app = Tetra::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif