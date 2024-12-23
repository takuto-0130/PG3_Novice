#include "Bullet.h"
#include <Novice.h>

const int Bullet::shotInterval_ = 20;

void Bullet::Init(Vector2 pos) { 
	pos_ = pos;
	radius_ = 8.0f;
	speed_ = 4.0f;
	isAlive_ = true;
}

void Bullet::Update() {
	pos_.y -= speed_;
	if (pos_.y <= 0) {
		isAlive_ = false;
	}
}

void Bullet::Draw() { 
	Novice::DrawEllipse(int(pos_.x), int(pos_.y), int(radius_), int(radius_), 
		0.0f, WHITE, kFillModeSolid); 
}
