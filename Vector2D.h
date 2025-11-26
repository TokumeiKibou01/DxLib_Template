#pragma once

class Vector2D {
public:
	float x, y;
	Vector2D(float x_ = 0, float y_ = 0);
	Vector2D Add(const Vector2D& v_);
	Vector2D Subtract(const Vector2D& v_);
	Vector2D ScalarMul(float k); 
	float Distance(const Vector2D& v_);
};

