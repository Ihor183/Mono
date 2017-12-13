#include "CommunityChest.h"
CommunityChest::CommunityChest(){}
CommunityChest::~CommunityChest(){}
void CommunityChest::setComm() { for (int i = 0; i < 8; i++) isntComm.push_back(i);}
int CommunityChest::getComm(int &money) {
	srand(time(NULL));
	bool flag = false;
	int k = 0;
	if (isComm.size() == 8) {
		isComm.clear();
		setComm();}
	while (!flag) {
		numComm = rand() % 8;
		for (it = isntComm.begin(); it != isntComm.end(); it++) {
		if (*it == numComm) {
			isComm.push_back(*it);
			it = isntComm.erase(it);
			if (it == isntComm.end()) { k = 1; break; }
			flag = true;
			break;
		}}
		if (k == 1) flag = true;
		if (isntComm.empty()) flag = true;
	}
    if (numComm == 0) money = 50;
	if (numComm == 1) money = -100;
	if (numComm == 2) money = 25;
	if (numComm == 3) money = -50;
	if (numComm == 4) money = 200;
	if (numComm == 5) money = 20;
	if (numComm == 6) money = 45;
	if (numComm == 7) money = 100;
	return numComm;
}
