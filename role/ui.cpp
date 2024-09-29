#include "config.h"
#include "ui.h"
Ui::Ui() {
	//增加音乐
	mciSendString(_T("open Resource/mus/bgm.mp3 alias bgm"), NULL, 0, NULL);	// 告诉系统将背景音乐添加到程序中,并把这个音乐取名为bgm

	//初始化Ui的状态
	runningType = UiRunningType::BEGING;

	img_menu = new IMAGE();
	img_background = new IMAGE();

	//初始化开始菜单界面的背景
	loadimage(img_menu, _T("Resource/img/menu.png"));
	//初始化游戏背景
	loadimage(img_background, _T("Resource/img/background.png"));
	//初始化Button
	region_btn_start_game.left = (WINDOW_WIDTH - BUTTON_WIDTH) / 2;
	region_btn_start_game.right = region_btn_start_game.left + BUTTON_WIDTH;
	region_btn_start_game.top = 430;
	region_btn_start_game.bottom = region_btn_start_game.top + BUTTON_HEIGHT;

	region_btn_quit_game.left = (WINDOW_WIDTH - BUTTON_WIDTH) / 2;
	region_btn_quit_game.right = region_btn_quit_game.left + BUTTON_WIDTH;
	region_btn_quit_game.top = 550;
	region_btn_quit_game.bottom = region_btn_quit_game.top + BUTTON_HEIGHT;

	btn_start_game = new StartGameButton(region_btn_start_game,
		_T("Resource/img/ui_start_idle.png"), _T("Resource/img/ui_start_hovered.png"), _T("Resource/img/ui_start_pushed.png"));
	btn_quit_game = new QuitGameButton(region_btn_quit_game,
		_T("Resource/img/ui_quit_idle.png"), _T("Resource/img/ui_quit_hovered.png"), _T("Resource/img/ui_quit_pushed.png"));
}
Ui::~Ui() {
	delete img_menu;
	delete img_background;
	delete btn_start_game;
	delete btn_quit_game;
}
void Ui::EventPorcess(const ExMessage& msg) {
	this->msg = msg;
	switch (runningType)
	{
	case BEGING:
		btn_start_game->ProcessEvent(this->msg);
		btn_quit_game->ProcessEvent(this->msg);
		if (btn_start_game->OnClick()) {
			runningType = RUNNING;
			mciSendString(_T("play bgm repeat from 0"), NULL, 0, NULL);
		}
		if (btn_quit_game->OnClick()) {
			runningType = QUITTING;
		}
		break;
	case RUNNING:
		for (Player* iter : p_playerlist->playerList) {
			iter->ProcessEvent(this->msg);
		}

		// 检测敌人和子弹的碰撞
		p_collision->CheckWeaponCollision();

		// 检测敌人和玩家的碰撞
		p_collision->CheckPlayerCollision();

		// 移除生命值归零的敌人
		p_enemylist->UpdateEnemyStatus();
		break;
	case QUITTING:
		break;
	default:
		break;
	}
}
void Ui::DisplayInitUi() {
	putimage(0, 0, img_menu);
	btn_start_game->Draw();
	btn_quit_game->Draw();
}

void Ui::DisplayGameingUi() {
	putimage(0, 0, img_background);
	for (Player* iter : p_playerlist->playerList) {
		iter->Move();
	}
	for (Enemy* enemy : p_enemylist->enemylist)
		enemy->Move();
	for (Player* iter : p_playerlist->playerList) {
		iter->Draw(1000 / 144);
	}
	for (Enemy* enemy : p_enemylist->enemylist)
		enemy->Draw(1000 / 144);
}
UiRunningType Ui::CheckStatus() {
	return runningType;
}
