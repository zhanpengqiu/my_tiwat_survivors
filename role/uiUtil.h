#pragma once
#include "config.h"
class Button

{
public:
	Button(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed);
	~Button();
	void ProcessEvent(const ExMessage& msg);
	void Draw();
	virtual bool OnClick();
private:
	enum class Status
	{
		Idle = 0,
		Hovered,
		Pushed,
	};
private:
	RECT region;	// 位置和大小
	IMAGE* img_idle;
	IMAGE* img_hovered;
	IMAGE* img_pushed;
	Status status = Status::Idle;

private:
	bool CheckCursorHit(int x, int y);
};

class StartGameButton :public Button {
public:
	StartGameButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed)
		: Button(rect, path_img_idle, path_img_hovered, path_img_pushed) {	}
	~StartGameButton() = default;
};

class QuitGameButton :public Button {
public:
	QuitGameButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed)
		: Button(rect, path_img_idle, path_img_hovered, path_img_pushed) {}
	~QuitGameButton() = default;
};


