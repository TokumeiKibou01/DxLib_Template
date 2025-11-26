#pragma once
#include "Vector2D.h"

class DrawObject {
private:
	Vector2D postion;
	Vector2D velocity;
	int width, height;
	unsigned int color;
	int customData;
public:
	DrawObject();
	DrawObject(Vector2D postion_, Vector2D velocity_, int width_, int height_, unsigned int color_, int customData_);
	~DrawObject();

	Vector2D GetPostion();
	void SetPostion(Vector2D postion_);
	Vector2D GetVelocity();
	void SetVelocity(Vector2D velocity_);
	int GetWidth();
	int GetHeight();
	void SetSize(int w, int h);
	unsigned int GetColor();
	int GetCustomData();
	void SetCustomData(int customData_);
};

