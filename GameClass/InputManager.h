#pragma once
#include <Novice.h>

class InputManager {
public:
	static InputManager* GetInstance() {
		static InputManager instance; // 静的ローカル変数（寿命がプログラム全体に渡る）
		return &instance;
	}

private:
	InputManager() = default;
	~InputManager(){};
	InputManager(InputManager&) = default;
	InputManager& operator=(InputManager&) = default;

private:
	// キー入力結果を受け取る箱
	char keys_[256] = {0};
	char preKeys_[256] = {0};

public:
	void Init();

	void Update();

	bool GetKeys(int keys) { return keys_[keys] != 0 ? true : false; }
	bool GetPreKeys(int preKeys) { return preKeys_[preKeys] != 0 ? true : false; }
};
