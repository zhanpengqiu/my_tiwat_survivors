#pragma once
#include "config.h"
#include "uiUtil.h"
#include "Collision.h"
class Ui
{
public:
	Ui();
	~Ui();
	//展示开始界面
	void EventPorcess(const ExMessage& ms);
	//展示游戏画面
	void DisplayGameingUi();
	//展示初始界面
	void DisplayInitUi();
	//展示结束界面
	void DisplayEndUi() {};
	//检查Ui状态
	UiRunningType CheckStatus();
private:
	const int BUTTON_WIDTH = 192;	// 按钮宽度
	const int BUTTON_HEIGHT = 75;	//按钮高度
	const int WINDOW_HEIGHT = 720;
	const int WINDOW_WIDTH = 1280;

	IMAGE* img_menu;
	IMAGE* img_background;

	StartGameButton* btn_start_game;
	QuitGameButton* btn_quit_game;

	RECT region_btn_start_game, region_btn_quit_game;

	//获得句柄
	PlayerList* p_playerlist = PlayerList::getinstance();
	Collision* p_collision = Collision::getinstance();
	EnemyList* p_enemylist = EnemyList::getinstance();


private:
	ExMessage msg;
	UiRunningType runningType;
};


