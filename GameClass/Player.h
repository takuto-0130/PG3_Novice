#pragma once
#include "../mathFunc.h"
#include "InputManager.h"
#include "Bullet.h"
#include <optional>
#include <memory>
#include <list>

enum class State {
	Move,
	Shot
};

class Player {
private:
	Vector2 pos_;
	float radius_;
	float speed_;
	int shotInterval_;

	std::list<std::shared_ptr<Bullet>> bullets_;

	State state_ = State::Move;
	std::optional<State> stateRequest_ = std::nullopt;

	InputManager* input = nullptr;

public:
	void Init();

	void Update();

	void Draw();

	std::list<std::shared_ptr<Bullet>> GetBullets() { return bullets_; }

private:
	void InitMove();
	void Move();

	void InitShot();
	void Shot();

	void AddBullet();
};
