#pragma once
#include "../InputManager.h"

enum Scene {TITLE, STAGE, CLEAR};
class IScene {
protected:
	static int sceneNo_;
	InputManager* input = nullptr;

public:
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	virtual ~IScene();

	int GetSceneNo();
};
