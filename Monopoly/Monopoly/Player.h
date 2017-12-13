#pragma once
#include<vector>
#include"Dice.h"
#include"Map.h"
#include<algorithm>

using namespace std;

class Player : public Dice {
private:
	bool start;
	long money;
	int position;
	int isJailCard;
	vector<int> positionMyFirm;

public:
	Player();
	~Player();
	void setMoney(int);
	void setPosition(int);
	int getPosition();
	void buyFirm(int, Map&);
	long getMoneyPlayer();
	void appMoney(int);
	void getCommunityChest();
	void getChance();
	void getOutOfJail();
	bool getStart();
	void setStart(bool);
	int getSize();
	void setPositionMyFirm(int *);
	void sortVector();
	void Change(vector<int>, vector<int>, int *, int, int);
};

