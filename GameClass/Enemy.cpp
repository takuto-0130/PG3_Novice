#include "Enemy.h"
#include <Novice.h>

void Enemy::Init() {
	pos_ = {640, 100};
	radius_ = 32.0f;
	isAlive_ = true;
}

void Enemy::Update() {}

void Enemy::Draw() { 
	if(isAlive_) { 
		Novice::DrawEllipse(int(pos_.x), int(pos_.y), 
			int(radius_), int(radius_), 0.0f, RED, kFillModeSolid);
	} else {
		Novice::DrawEllipse(int(pos_.x), int(pos_.y), 
			int(radius_), int(radius_), 0.0f, BLACK, kFillModeSolid);
	}
}
