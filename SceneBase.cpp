#include "SceneBase.h"
#include "TitleScene.h"
#include "GameManager.h"

SceneBase::SceneBase(string name_) {
    this->name = name_;
}

SceneBase::~SceneBase() {
}

string SceneBase::GetName() const {
    return this->name;
}

void SceneBase::Draw() {
    //‰½‚à‚µ‚È‚¢
}

void SceneBase::Update() {
    //‰½‚à‚µ‚È‚¢
}

void SceneBase::init() {
    //‰½‚à‚µ‚È‚¢
}