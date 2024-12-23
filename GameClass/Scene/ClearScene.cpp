#include "ClearScene.h"

void ClearScene::Init() { input = InputManager::GetInstance(); }

void ClearScene::Update() {
	if (input->GetPreKeys(DIK_SPACE) == 0 && input->GetKeys(DIK_SPACE)) {
		sceneNo_ = TITLE;
	}
}

void ClearScene::Draw() { Novice::ScreenPrintf(600, 300, "CLEAR NEXT PUSH SPACE"); }
