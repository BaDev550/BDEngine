#include <BADEVEngineCAH.h>

class Sandbox : public BDE_ApplicationCore::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

BDE_ApplicationCore::Application* BDE_ApplicationCore::CreateApplication() {
	return new Sandbox();
}