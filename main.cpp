#include "config.h"

#pragma comment(lib,"MSIMG32.LIB")
#pragma comment(lib, "winmm.lib")

static int count = 0;
const int INTERVAL = 100;
PlayerList* PlayerList::instance = nullptr;
Collision* Collision::instance = nullptr;
EnemyList* EnemyList::instance = nullptr;
int main() {
	//添加音效到系统中
	bool running = true;
	Ui* p_ui = new Ui();
	ExMessage msg;

	bool is_move_up = false;
	bool is_move_down = false;
	bool is_move_left = false;
	bool is_move_right = false;
	PlayerList* p_playerlist = PlayerList::getinstance();
	Collision* p_collision = Collision::getinstance();
	EnemyList* p_enemylist = EnemyList::getinstance();

	p_playerlist->playerList.push_back(new Player());

	initgraph(1280, 720);
	BeginBatchDraw();
	while (running) {
		DWORD start_time = GetTickCount();
		//生成敌人
		count++;
		if (count % INTERVAL == 0)
			p_enemylist->TryGenerateEnemy(5);
		for (Player* iter : p_playerlist->playerList) {
			if (iter->CheckAlive() == false) {
				static TCHAR text[128];
				_stprintf_s(text, _T("最终得分:"));
				MessageBox(GetHWnd(), text, _T("游戏结束"), MB_OK);
				running = false;
				break;
			}
		}
		//接受消息并处理
		while (peekmessage(&msg))
		{
			p_ui->EventPorcess(msg);
		}

		cleardevice();
		switch (p_ui->CheckStatus())
		{
		case UiRunningType::BEGING:
			p_ui->DisplayInitUi();
			break;
		case UiRunningType::RUNNING:
			p_ui->DisplayGameingUi();
			break;
		default:
			running = false;
			break;
		}

		//批量延时处理
		FlushBatchDraw();
		//延时帧率处理
		DWORD end_time = GetTickCount();
		DWORD delta_time = end_time - start_time;
		if (delta_time < 1000 / 144)
		{
			Sleep(1000 / 144 - delta_time);
		}
	}
	EndBatchDraw();

	return 0;
}
