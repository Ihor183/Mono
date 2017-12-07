#pragma once
#include<vector>
#include"Dice.h"
#include"Map.h"

//const int MAXFIRM = 28;

using namespace std;

class Player : public Dice/*, public Map*/ {
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
	
};

