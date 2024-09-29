#pragma once
#include "config.h"
#include "Animation.h"
//����
class Role
{
public:
	Role() = default;
	virtual ~Role() = default;

	virtual void Hurt(int damage)=0;
	virtual void Draw(int delta)=0;		//���˸�Ӣ�۵Ļ�����ʽ�ǲ�һ����
	virtual void Move()=0;
	virtual void ProcessEvent(const ExMessage& msg)=0;//������Ϣ�¼�


	virtual void ShowHealthBar(){
		int barWidth = 80;
		int barHeight = 10;

		int progressWidth = (mHp * barWidth) / maxHp;

		int greenLeftUpX = position.x;
		int greenLeftUpY = position.y;
		int greenRightDownX = position.x + progressWidth;
		int greenRightDownY = position.y + barHeight;
		greenRightDownX = greenRightDownX < WINDOW_WIDTH ? greenRightDownX : WINDOW_WIDTH;
		greenRightDownY = greenRightDownY < WINDOW_HEIGHT ? greenRightDownY : WINDOW_HEIGHT;
		int redLeftUpX = position.x + progressWidth;
		int redLeftUpY = position.y;
		int redRightDownX = position.x + barWidth;
		int redRightDownY = greenRightDownY;
		redRightDownX = redRightDownX < WINDOW_WIDTH ? redRightDownX : WINDOW_WIDTH;
		redRightDownY = redRightDownY < WINDOW_HEIGHT ? redRightDownY : WINDOW_HEIGHT;

		setfillcolor(GREEN);
		solidrectangle(greenLeftUpX, greenLeftUpY, greenRightDownX, greenRightDownY);
		setfillcolor(RED);
		solidrectangle(redLeftUpX, redLeftUpY, redRightDownX, redRightDownY);
	};

	//���λ����Ϣ
	virtual const POINT& GetPosition() const
	{
		return position;
	}
	//��鵱ǰ��ɫ�Ƿ���
	virtual bool CheckAlive() {
		if (mHp <= 0)return false;
		return true;
	}
	//�����ͼ��ص�û��Ҫʵ�ֶ�̬
	void PutimageAlpha(int x, int y, IMAGE* img)
	{
		int w = img->getwidth();
		int h = img->getheight();
		AlphaBlend(GetImageHDC(NULL), x, y, w, h,
			GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER,0,255,AC_SRC_ALPHA });
	}

public:
	int mHp,maxHp;
	int mMp;
	int mAt;
	int mDf;
	int speed;
	POINT position;
protected:
	IMAGE* img_shadow;
	Animation* anim_left;
	Animation* anim_right;
	bool facing_left = false;
	const int WINDOW_WIDTH = 1280;
	const int WINDOW_HEIGHT = 720;
};

