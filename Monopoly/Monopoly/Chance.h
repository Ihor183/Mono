#pragma once
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<vector>

using namespace std;

class Chance {
private:
	int numChance;
	vector<int> isntCheck;
	vector<int> isCheck;
	vector<int>::iterator it;
public:
	Chance();
	~Chance();
	void setChance();
	int getChance(int&, int&);
};

