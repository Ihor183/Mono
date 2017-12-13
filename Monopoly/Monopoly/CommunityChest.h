#pragma once
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<vector>

using namespace std;

class CommunityChest {
private:
	int numComm;
	vector<int> isntComm;
	vector<int> isComm;
	vector<int>::iterator it;
	
public:
	CommunityChest();
	~CommunityChest();
	void setComm();
	int getComm(int&);
};

