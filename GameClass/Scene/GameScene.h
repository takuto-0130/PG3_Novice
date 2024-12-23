#pragma once
#include "IScene.h"
#include "../Player.h"
#include "../Enemy.h"
#include <memory>
class GameScene : public IScene {
public:
	void Init() override;
	void Update() override;
	void Draw() override;

private:
	void ReturnTitle();

	void Collision();

private:
	std::unique_ptr<Player> player_ = nullptr;
	std::unique_ptr<Enemy> enemy_ = nullptr;
};
