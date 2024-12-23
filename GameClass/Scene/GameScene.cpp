#include "GameScene.h"
#include "operatorOverload.h"

void GameScene::Init() { 
	input = InputManager::GetInstance();

	player_ = std::make_unique<Player>();
	player_->Init();

	enemy_ = std::make_unique<Enemy>();
	enemy_->Init();
}

void GameScene::Update() {
	ReturnTitle();
	player_->Update();
	enemy_->Update();
	Collision();
}

void GameScene::Draw() { 
	if(enemy_->GetIsAlive()) {
		Novice::ScreenPrintf(600, 300, "GAME");
	} 
	else {
		Novice::ScreenPrintf(600, 300, "NEXT PUSH SPACE");
	}
	enemy_->Draw();
	player_->Draw();
}

void GameScene::ReturnTitle() {
	if (!enemy_->GetIsAlive() && input->GetPreKeys(DIK_SPACE) == 0 && input->GetKeys(DIK_SPACE)) {
		sceneNo_ = CLEAR;
	}
}

void GameScene::Collision() { 
	for (std::shared_ptr<Bullet> bullet : player_->GetBullets()) {
		if (Length(bullet->GetPos() - enemy_->GetPos()) <= 
			bullet->GetRadius() + enemy_->GetRadius()) {
			bullet->OnCollision();
			enemy_->OnCollision();
		}
	}
}
