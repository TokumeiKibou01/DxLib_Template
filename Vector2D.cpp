#include "Vector2D.h"
#include <cmath>

Vector2D::Vector2D(float x_, float y_)
	:x(x_), y(y_) {
}

Vector2D Vector2D::Add(const Vector2D& v_) {
	Vector2D tmp(x + v_.x, y + v_.y);
	return tmp;
}

Vector2D Vector2D::Subtract(const Vector2D& v_) {
	Vector2D tmp(x - v_.x, y - v_.y);
	return tmp;
}

Vector2D Vector2D::ScalarMul(float k) {
	Vector2D tmp(k * x, k * y);
	return tmp;
}

//‹——£
float Vector2D::Distance(const Vector2D& _v) {
	float dist2 = (_v.x - x) * (_v.x - x) + (_v.y - y) * (_v.y - y);
	return sqrt(dist2);
}