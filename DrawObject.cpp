#include "DrawObject.h"
#include "GameUtility.h"
#include "main.h"

DrawObject::DrawObject()
	: postion(Vector2D(0, 0)),
	velocity(Vector2D(1, 1)),
	width(100),
	height(100),
	color(Color::BLACK),
	customData(0) {
}

DrawObject::DrawObject(Vector2D postion_, Vector2D velocity_, int width_, int height_, unsigned int color_, int customData_)
	: postion(postion_), velocity(velocity_), width(width_), height(height_), color(color_), customData(customData_){
}

DrawObject::~DrawObject() {
}

Vector2D DrawObject::GetPostion() {
	return postion;
}

void DrawObject::SetPostion(Vector2D postion) {
	this->postion = postion;
}

Vector2D DrawObject::GetVelocity() {
	return velocity;
}

void DrawObject::SetVelocity(Vector2D velocity_) {
	this->velocity = velocity_;
}

int DrawObject::GetWidth() {
	return width;
}

int DrawObject::GetHeight() {
	return height;
}

void DrawObject::SetSize(int w, int h) {
	this->width = w;
	this->height = h;
}

unsigned int DrawObject::GetColor() {
	return color;
}

int DrawObject::GetCustomData() {
	return customData;
}

void DrawObject::SetCustomData(int customData_) {
	this->customData = customData_;
}
