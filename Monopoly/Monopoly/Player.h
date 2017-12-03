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
	vector<int> positionMyFirm;
	//int positionMyFirm[MAXFIRM];
	//vector<int> firm;

public:
	Player();
	~Player();
	void setMoney(int);
	void setPosition(int);
	int getPosition();
	void buyFirm(int, Map&);
};

