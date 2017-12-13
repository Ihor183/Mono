#include "Chance.h"
Chance::Chance(){ }
Chance::~Chance(){}
void Chance::setChance() { for (int i = 0; i < 8; i++) isntCheck.push_back(i); }
int Chance::getChance(int &pos, int &money) {
	srand(time(NULL));
	bool flag = false;
	int k = 0;
	if (isCheck.size() == 8) { isCheck.clear(); setChance();}
	while (!flag) {
		numChance = rand() % 8;
		for (it = isntCheck.begin(); it != isntCheck.end(); it++) {
		if (*it == numChance) {
			isCheck.push_back(*it);
			it = isntCheck.erase(it);
			if (it == isntCheck.end()) { k = 1; break; }
			flag = true;
			break;
		}}
		if (k == 1) flag = true;
		if (isntCheck.empty()) flag = true;
	}
	if (numChance == 0) pos = 11;
	if (numChance == 1) pos = 39;
	if (numChance == 2) pos = 24;
	if (numChance == 3) money = 150;
	if (numChance == 4) pos = 40;
	if (numChance == 5) money = -150;
	if (numChance == 6) pos = 5;
	if (numChance == 7) money = 100;
	return numChance;
}
