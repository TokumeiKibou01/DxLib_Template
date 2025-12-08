#pragma once
#include <iostream>
#include <vector>
#include "DrawBase.h"

using namespace std;

class SceneBase {
protected:
	vector<DrawBase*> drawVector;
private:
	string name;
public:
	SceneBase(string name_);
	~SceneBase();
	string GetName() const;
	virtual void Draw();
	virtual void Update();
	virtual void init();
};

