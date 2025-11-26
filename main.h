#pragma once
#include "GameManager.h"

namespace Window {
    const char* DEFAULT_TITLE = "Game";
    const int FPS = 60;
    const int WIDTH = 1280;
    const int HEIGHT = 720;
    const int COLORBIT = 32;
    const int BACKGROUND_COLOR[3] = { 255, 255, 255 };
}

namespace GameBase {
    GameManager manager;
    bool DEBAUG_MODE = true;
}