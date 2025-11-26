#include <DxLib.h>
#include "GameUtility.h"

using namespace Input;

namespace Input {
    //キーボード取得関連
    const int KEY_MAX = 255;
    char keyBuff[KEY_MAX];		//キーバッファ (現フレーム)
    char keyBuffOld[KEY_MAX];	//1つ前のキーバッファ(前フレーム) 
    char key_down[KEY_MAX];		//押された瞬間 
    char key_up[KEY_MAX];		//離された瞬間 
    char Key_Keep[KEY_MAX];		//押しっぱなし
}

void GameUtility::DrawText(DrawType type, int x, int y, int size, unsigned int text_color, unsigned int edge_color, std::string text) {
    SetFontSize(size);
    int strWidth = GetDrawStringWidth(text.c_str(), strlen(text.c_str()));
    if (type == DrawType::LEFT) {
        //
    }
    else if (type == DrawType::RIGHT) {
        x -= strWidth;
    }
    else if (type == DrawType::CENTER) {
        x -= strWidth / 2;
        y -= size / 2;
    }


    DrawString(x, y, text.c_str(), text_color, edge_color);
}

void Input::KeyStateUpdate() {
    memcpy_s(keyBuffOld, sizeof(char) * KEY_MAX, keyBuff, sizeof(char) * KEY_MAX);

    GetHitKeyStateAll(keyBuff);//全てのキーの状態を取得 

    for (int i = 0; i < KEY_MAX; i++) {
        if (keyBuff[i] && keyBuffOld[i]) Key_Keep[i]++;
        int key_xor = keyBuff[i] ^ keyBuffOld[i];	//前フレームと現フレームのxor
        if (key_xor) Key_Keep[i] = 0;
        key_down[i] = key_xor & keyBuff[i];		//押された瞬間 = (現フレームとkey_xorのAND) 
        key_up[i] = key_xor & keyBuffOld[i];	//離された瞬間 = (前フレームとkey_xorのAND) 
    }
}

bool Input::IsKeyUP(int keyCode) {
    return(key_up[keyCode]);
}

bool Input::IsKeyDown(int keyCode) {
    return(key_down[keyCode]);
}

int Input::IsKeepKeyDown(int keyCode) {
    return(Key_Keep[keyCode]);
}
