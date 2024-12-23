#pragma once
#include "../mathFunc.h"
class Enemy {
private:
	Vector2 pos_;
	float radius_;
	bool isAlive_;

public:
	void Init();

	void Update();

	void Draw();

	bool GetIsAlive() { return isAlive_; }

	void OnCollision() { isAlive_ = false; }

	const Vector2& GetPos() { return pos_; }

	const float& GetRadius() { return radius_; }

};
