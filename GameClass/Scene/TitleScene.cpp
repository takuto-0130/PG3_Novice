#include "TitleScene.h"

void TitleScene::Init() { input = InputManager::GetInstance(); }

void TitleScene::Update() {
	if (input->GetPreKeys(DIK_SPACE) == 0 && input->GetKeys(DIK_SPACE)) {
		sceneNo_ = STAGE;
	}
}

void TitleScene::Draw() { Novice::ScreenPrintf(600, 300, "TITLE NEXT PUSH SPACE"); }
