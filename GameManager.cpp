#include "GameManager.h"

GameManager::GameManager(){
}

GameManager::~GameManager() {
}

int GameManager::GetTime() {
	return this->time;
}

void GameManager::SetTime(int time_) {
	this->time = time_;
}

void GameManager::AddTime(int time_) {
	this->time += time_;
}

void GameManager::SubtractTime(int time_) {
	this->time -= time_;
}

GameStatus GameManager::GetStatus() {
	return this->status;
}

void GameManager::SetStatus(GameStatus status_) {
	this->status = status_;
}

void GameManager::InitGame() {
	this->time = 0;
	this->status = GameStatus::WAITING;
}


