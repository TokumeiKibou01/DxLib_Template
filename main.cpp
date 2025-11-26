#include <DxLib.h>
#include <iostream>
#include "main.h"
#include "GameUtility.h"

//プロトタイプ宣言
int initLibrary();
void UpdateGame();
void DrawGame();
void DrawDebug();

//名前空間の使用
using namespace std;
using namespace GameBase;

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
        DrawDebug();

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
    ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE_16X16);
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
    switch (manager.GetStatus()) {
    case GameStatus::WAITING: {
        break;
    }
    case GameStatus::RUNNING: {
        break;
    }
    case GameStatus::ENDING: {
        break;
    }
    }
    manager.AddTime(1);
}

//ゲーム画面を書く処理
void DrawGame() {
    switch (manager.GetStatus()) {
    case GameStatus::WAITING: {
        break;
    }
    case GameStatus::RUNNING: {
        break;
    }
    case GameStatus::ENDING: {
        break;
    }
    default:
        break;
    }
}

//デバックを描画する処理
void DrawDebug() {
    if (GameBase::DEBAUG_MODE) {
        string leftUp_side = "時間: " + to_string(manager.GetTime());
        GameUtility::DrawTextA(DrawType::LEFT, 10, 10, 15, Color::WHITE, Color::BLACK, leftUp_side);

        string rightUp_side = "";
        string leftDown_side = "";
        string rightDown_side = "";
    }
}
