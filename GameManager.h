#pragma once
#include "SceneManager.h"

namespace Screen {
	const int WIDTH = 1280;
	const int HEIGHT = 720;
	const int COLORBIT = 32;
	const int FPS = 60;
	const int BACK_COLOR[3] = {0, 0, 0};
}

inline SceneManager& GetSceneManager() {
	static SceneManager sceneManager;
	return sceneManager;
}