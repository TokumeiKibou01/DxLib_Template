#pragma once
#include <DxLib.h>
#include <iostream>
#include "Postion.h"
#include "Vector3D.h"
#include "GameUtility.h"
#include <vector>

using namespace std;

class DrawBase {
protected:
private:
	string name;
	Postion postion;
	Vector3D vector;
	float width, height;
	std::vector<DrawBase*> drawVector;
public:
	DrawBase(string name_, int width_, int height_, Postion postion_, Vector3D vector_);
	~DrawBase();

	string GetName() const { return name;  };
	void SetName(string name_) { name = name_; };
	Postion GetPostion() const { return postion; };
	void SetPostion(const Postion& postion_) { postion = postion_; };
	Vector3D GetVector() const { return vector; };
	void SetVector(const Vector3D& vector_) { vector = vector_; };
	float GetWidth() const { return width; }
	void SetWidth(float width_) { width = width_;  };
	float GetHeight() const { return height; }
	void SetHeight(float height_) { height = height_; };

	virtual void Update();
	virtual void Draw();
};

