#pragma once
#include <string>
#include <DxLib.h>

enum DrawType {
	LEFT,
	CENTER,
	RIGHT
};

namespace Color {
	const int RED = GetColor(255, 0, 0);
	const int BLUE = GetColor(0, 0, 255);
	const int GREEN = GetColor(0, 255, 0);
	const int BLACK = GetColor(0, 0, 0);
	const int WHITE = GetColor(255, 255, 255);
}

namespace Input {
	void KeyStateUpdate();
	bool IsKeyUP(int keyCode);
	bool IsKeyDown(int keyCode);
	int IsKeepKeyDown(int keyCode);
}

class GameUtility {
public:
	static void DrawText(DrawType type, int x, int y, int size, unsigned int text_color, unsigned int edge_color, std::string text);
};

