#include "ExampleScene.h"
#include "CAScene.h"
#include "GOLScene.h"
#include <memory>
#include <SDL.h>

int main(int, char**)
{
	//___SCENE TYPES___
	//std::unique_ptr<ExampleScene> scene = std::make_unique<ExampleScene>();
	//std::unique_ptr<CAScene> scene = std::make_unique<CAScene>();
	std::unique_ptr<GOLScene> scene = std::make_unique<GOLScene>();

	scene->Initialize();
	while (!scene->IsQuit())
	{
		scene->Update();
		scene->Draw();
	}

	return 0;
}