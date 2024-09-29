#pragma once
#include "config.h"
#include "uiUtil.h"
#include "Collision.h"
class Ui
{
public:
	Ui();
	~Ui();
	//չʾ��ʼ����
	void EventPorcess(const ExMessage& ms);
	//չʾ��Ϸ����
	void DisplayGameingUi();
	//չʾ��ʼ����
	void DisplayInitUi();
	//չʾ��������
	void DisplayEndUi() {};
	//���Ui״̬
	UiRunningType CheckStatus();
private:
	const int BUTTON_WIDTH = 192;	// ��ť���
	const int BUTTON_HEIGHT = 75;	//��ť�߶�
	const int WINDOW_HEIGHT = 720;
	const int WINDOW_WIDTH = 1280;

	IMAGE* img_menu;
	IMAGE* img_background;

	StartGameButton* btn_start_game;
	QuitGameButton* btn_quit_game;

	RECT region_btn_start_game, region_btn_quit_game;

	//��þ��
	PlayerList* p_playerlist = PlayerList::getinstance();
	Collision* p_collision = Collision::getinstance();
	EnemyList* p_enemylist = EnemyList::getinstance();


private:
	ExMessage msg;
	UiRunningType runningType;
};


