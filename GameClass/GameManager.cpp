#include "GameManager.h"
#include <Novice.h>

GameManager::GameManager() { 
	input = InputManager::GetInstance();
	input->Init();
	sceneArr_[Scene::TITLE] = std::make_unique<TitleScene>();
	sceneArr_[Scene::TITLE]->Init();
	sceneArr_[Scene::STAGE] = std::make_unique<GameScene>();
	sceneArr_[Scene::STAGE]->Init();
	sceneArr_[Scene::CLEAR] = std::make_unique<ClearScene>();
	sceneArr_[Scene::CLEAR]->Init();
	currentSceneNo_ = 0;
	prevSceneNo_ = currentSceneNo_;
}

GameManager::~GameManager() {}

int GameManager::Run() { 
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();
		input->Update();

		prevSceneNo_ = currentSceneNo_;
		currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();

		if (prevSceneNo_ != currentSceneNo_) {
			sceneArr_[currentSceneNo_]->Init();
		}

		/// ↓更新処理ここから

		sceneArr_[currentSceneNo_]->Update();

		/// ↓描画処理ここから

		sceneArr_[currentSceneNo_]->Draw();

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (input->GetPreKeys(DIK_ESCAPE) == 0 && input->GetKeys(DIK_ESCAPE) != 0) {
			break;
		}
	}
	return 0; 

}
