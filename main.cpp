#include <DxLib.h>
#include <iostream>
#include "main.h"

//プロトタイプ宣言
int initLibrary();
void UpdateGame();
void DrawGame();

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

        //処理
        UpdateGame();
        DrawGame();

        ScreenFlip();
        WaitTimer(1000 / Window::FPS);
        if (ProcessMessage() == -1) {
            break;
        }
    }
    DxLib_End();
    return 0;
}

//ライブラリの初期化
int initLibrary() {
    SetWindowText(Window::DEFAULT_TITLE);
    SetGraphMode(Window::WIDTH, Window::HEIGHT, Window::COLORBIT);
    ChangeWindowMode(true);
    if (DxLib_Init() == -1) {
        return -1;
    }

    SetBackgroundColor(Window::BACKGROUND_COLOR[0], Window::BACKGROUND_COLOR[1], Window::BACKGROUND_COLOR[2]);
    SetDrawScreen(DX_SCREEN_BACK);

    return 0;
}

//ゲームの処理を更新する処理
void UpdateGame() {
}

//ゲーム画面を書く処理
void DrawGame() {
}
