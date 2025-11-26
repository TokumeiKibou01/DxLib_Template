#include <DxLib.h>
#include "GameUtility.h"

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
