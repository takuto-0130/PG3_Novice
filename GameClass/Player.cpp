#include "Player.h"
#include <Novice.h>

void Player::Init() {
	pos_ = {640, 500};
	radius_ = 16.0f;
	speed_ = 4.0f;
	input = InputManager::GetInstance();
}

void Player::Update() { 
	//切り替え時の初期化
	if (stateRequest_) {
		state_ = stateRequest_.value();
		switch (state_) { 
		case State::Move:
		default:
			InitMove();
			break;
		case State::Shot:
			InitShot();
			break;
		}
		stateRequest_ = std::nullopt;
	}

	//更新
	switch (state_) {
	case State::Move:
	default:
		Move();
		break;
	case State::Shot:
		Shot();
		break;
	}
	for (std::shared_ptr<Bullet> bullet : bullets_) {
		bullet->Update();
	}

	bullets_.remove_if([](std::shared_ptr<Bullet> bullet) { 
		return bullet->GetIsAlive() == false;
		});
}

void Player::Draw() { 
	for (std::shared_ptr<Bullet> bullet : bullets_) {
		bullet->Draw();
	}
	Novice::DrawEllipse(int(pos_.x), int(pos_.y), 
		int(radius_), int(radius_), 0.0f, GREEN, kFillModeSolid); }

void Player::InitMove() {}

void Player::Move() { 
	if (input->GetKeys(DIK_W)) {
		pos_.y -= speed_;
	}
	if (input->GetKeys(DIK_A)) {
		pos_.x -= speed_;
	}
	if (input->GetKeys(DIK_S)) {
		pos_.y += speed_;
	}
	if (input->GetKeys(DIK_D)) {
		pos_.x += speed_;
	}
	if (input->GetPreKeys(DIK_SPACE) == 0 && input->GetKeys(DIK_SPACE)) {
		stateRequest_ = State::Shot;
	}
}

void Player::InitShot() { shotInterval_ = 0; }

void Player::Shot() {

	if (input->GetKeys(DIK_SPACE)) {
		if (shotInterval_ == 0) {
			AddBullet();
		}
		++shotInterval_;
		if (shotInterval_ == Bullet::shotInterval_) {
			shotInterval_ = 0;
		}
	} 
	else {
		stateRequest_ = State::Move;
	}

}

void Player::AddBullet() { 
	std::shared_ptr<Bullet> bullet = std::make_shared<Bullet>();
	bullet->Init(pos_);
	bullets_.push_back(bullet);
	bullet.reset();
}
