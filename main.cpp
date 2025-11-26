#include <DxLib.h>
#include <iostream>
#include "main.h"
#include "GameUtility.h"
#include "DrawObject.h"
#include "GameManager.h"

//プロトタイプ宣言
int initLibrary();
void initGame();
void UpdateGame();
void DrawGame();
void DrawDebug();

//名前空間の使用
using namespace std;

namespace {
    GameManager manager;
    bool DEBAUG_MODE = true;
    std::vector<DrawObject> test_objVec;
}

//メイン関数
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    int init_result = initLibrary();
    if (init_result != 0) {
        string message = string("エラーが発生しました。ソフトを終了します。");
        MessageBox(NULL, message.c_str(), NULL, MB_OK | MB_ICONERROR);
        return -1;
    }

    initGame();

    while (true) {
        ClearDrawScreen();
        Input::KeyStateUpdate();

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

void initGame() {
    manager.InitGame();
    test_objVec.push_back(DrawObject());
}

//ゲームの処理を更新する処理
void UpdateGame() {
    switch (manager.GetStatus()) {
    case GameStatus::WAITING: {
        GameUtility::DrawTextA(DrawType::CENTER, Window::WIDTH / 2, Window::HEIGHT / 2, 30, Color::WHITE, Color::BLACK, "ゲームを開始するにはspaceを押してください");
        if (Input::IsKeyDown(KEY_INPUT_SPACE)) {
            manager.SetStatus(GameStatus::RUNNING);
            manager.SetTime(0);
        }
        break;
    }
    case GameStatus::RUNNING: {
        if (Input::IsKeyDown(KEY_INPUT_SPACE)) {
            manager.SetStatus(GameStatus::ENDING);
            manager.SetTime(0);
        }
        break;
    }
    case GameStatus::ENDING: {
        if (Input::IsKeyDown(KEY_INPUT_SPACE)) {
            manager.SetStatus(GameStatus::WAITING);
            manager.SetTime(0);
        }
        break;
    }
    }
    manager.AddTime(1);
}

//ゲーム画面を書く処理
void DrawGame() {
    switch (manager.GetStatus()) {
    case GameStatus::WAITING: {
        for (auto test_obj : test_objVec) {
            const Vector2D& pos = test_obj.GetPostion();
            DrawBox(
                pos.x - (test_obj.GetWidth() / 2), pos.y - (test_obj.GetHeight() / 2),
                pos.x + (test_obj.GetWidth() / 2), pos.y + (test_obj.GetHeight() / 2),
                test_obj.GetColor(),
                true
            );
        }
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
    if (DEBAUG_MODE) {
        string leftUp_side = 
            "時間: " + to_string(manager.GetTime()) + "\n" +
            + "現在の状態： " + to_string(manager.GetStatus()) + "\n";
        GameUtility::DrawTextA(DrawType::LEFT, 10, 10, 15, Color::WHITE, Color::BLACK, leftUp_side);

        string rightUp_side = "";
        string leftDown_side = "";
        string rightDown_side = "";
    }
}
