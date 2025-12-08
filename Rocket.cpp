#include <DxLib.h>
#include "Rocket.h"
#include "globals.h"
#include "Input.h"

int size = 30;

namespace {
	const int gravity = 0.1;
}

Rocket::Rocket()
 : BaseChara(){
}

Rocket::Rocket(const Vector2D& pos, const Vector2D& vel, unsigned int color)
 : BaseChara(pos, vel, color, SHAPE::TRIANGLE){
}

Rocket::~Rocket()
{
}

void Rocket::Update() {
	int mx = 0, my = 0;
	GetMousePoint(&mx, &my); //マウスの座標をとる
	if (0 < mx && mx > WIN_WIDTH) return; //画面外だったら実行しない

	if (Input::IsKeyDown(KEY_INPUT_SPACE)) {
		vel_.y = -10; //ベクトルYを-10にする（上に向かうように）
		pos_.x = mx; //ロケット場所をマウスのXにする
		isJumping = true;  //ジャンプフラグをtrueに
	}

	if (isJumping) { //ジャンプしていたら上に向かう処理
		pos_.y = pos_.y + (vel_.y); //例：1280+(-10) →　1280+(-9.9) → 1280+(-9.8) ...
		vel_.y = vel_.y - gravity; 
	}

	if (pos_.y < 0+size || pos_.y > WIN_HEIGHT-size) { //画面外に出たら
		pos_.x = WIN_WIDTH / 2; //幅の半分に
		pos_.y = GROUND_HEIGTH; //地面に
		vel_.y = 0; //ベクトルを0に（進まないように）
		isJumping = false;  //ジャンプが終了したので、falseに
	}
}

void Rocket::Draw()
{
	const Vector2D& pos = GetPos();
	DrawTriangle(pos.x, pos.y-size, pos.x-size, pos.y, pos.x+size, pos.y, GetCharaColor(), true);
}

void Rocket::LaunchRocket() {

}

