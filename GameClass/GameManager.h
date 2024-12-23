#pragma once

#include <memory>
#include "Scene/IScene.h"
#include "Scene/TitleScene.h"
#include "Scene/GameScene.h"
#include "Scene/ClearScene.h"
#include "InputManager.h"

class GameManager {
private:
	std::unique_ptr<IScene> sceneArr_[3];
	InputManager* input = nullptr;

	int currentSceneNo_;
	int prevSceneNo_;

public:
	GameManager();
	~GameManager();

	int Run();
};
