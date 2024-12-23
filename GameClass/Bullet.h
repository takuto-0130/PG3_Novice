#pragma once
#include "../mathFunc.h"
class Bullet {
private:
	Vector2 pos_;
	float radius_;
	float speed_;
	bool isAlive_;

public:
	static const int shotInterval_;

public:
	void Init(Vector2 pos);

	void Update();

	void Draw();

	bool GetIsAlive() { return isAlive_; }

	void OnCollision() { isAlive_ = false; }

	const Vector2& GetPos() { return pos_; }

	const float& GetRadius() { return radius_; }

};
