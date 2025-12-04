#include <DxLib.h>
#include <iostream>
#include "GameScreen.h"

//プロトタイプ宣言
int initLibrary();

//名前空間の使用
using namespace std;

//メイン関数
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    int init_result = initLibrary();
    if (init_result != 0) {
        string message = string("エラーが発生しました。ソフトを終了します。");
        MessageBox(NULL, message.c_str(), NULL, MB_OK | MB_ICONERROR);
        return -1;
    }

    while (true) {
        ClearDrawScreen();

        ScreenFlip();
        WaitTimer(1000 / Screen::FPS);
        if (ProcessMessage() == -1) {
            break;
        }
    }
    DxLib_End();
    return 0;
}

//ライブラリの初期化
int initLibrary() {
    ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE_16X16);
    ChangeWindowMode(true);
    SetGraphMode(Screen::WIDTH, Screen::HEIGHT, Screen::COLORBIT);
    if (DxLib_Init() == -1) {
        return -1;
    }

    SetBackgroundColor(Screen::BACK_COLOR[0], Screen::BACK_COLOR[1], Screen::BACK_COLOR[2]);
    SetDrawScreen(DX_SCREEN_BACK);

    return 0;
}