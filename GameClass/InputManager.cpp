#include "InputManager.h"

void InputManager::Init() {
	keys_[256] = {0};
	preKeys_[256] = {0};
}

void InputManager::Update() {
	// キー入力を受け取る
	memcpy(preKeys_, keys_, 256);
	Novice::GetHitKeyStateAll(keys_);
}
