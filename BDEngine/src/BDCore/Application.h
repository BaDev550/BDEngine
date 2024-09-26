#pragma once

#include "Core.h"

namespace BDE_ApplicationCore {

	class BDE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client
	Application* CreateApplication();

}


