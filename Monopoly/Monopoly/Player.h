#pragma once
#include<vector>
#include<map>
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
	vector<int> NumMyCorporation;
	vector<int>::iterator it;
	multimap<int, int> NumCorporation;
	multimap<int, int>::iterator iNumCorporation;
	

public:
	Player();
	~Player();
	void setMoney(int);
	void setPosition(int);
	int getPosition();
	void buyFirm(int, Map&);
	long getMoneyPlayer();
	void appMoney(int);
	void getOutOfJail();
	bool getStart();
	void setStart(bool);
	int getSize();
	void setPositionMyFirm(int *);
	void sortVector();
	void Change(vector<int>, vector<int>, int *, int, int);
	void Rent(Player *, int, Map&, int, int);
	bool isCorporation(int, int);
};

