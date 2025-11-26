#pragma once

//ゲームの状態
enum GameStatus {
	WAITING, //待機画面
	RUNNING, //実行画面
	ENDING //終了画面
};

//ゲームを管理するクラス
class GameManager {
private:
	int time = 0; //ゲーム時間
	GameStatus status = GameStatus::WAITING; //ゲームの状態
public:
	GameManager(); //コンストラクタ
	~GameManager(); //デストラクタ

	int GetTime();
	void SetTime(int time_);
	void AddTime(int time_);
	void SubtractTime(int time_);
	GameStatus GetStatus();
	void SetStatus(GameStatus status_);
	void InitGame();
protected:
};

