#include "Player.h"

Player::Player() {
	money = 2000;
	position = 0;
	start = false;
	isJailCard = false;

	NumCorporation.insert(pair<int, int>(1, 1));
	NumCorporation.insert(pair<int, int>(1, 3));
	NumCorporation.insert(pair<int, int>(2, 6));
	NumCorporation.insert(pair<int, int>(2, 8));
	NumCorporation.insert(pair<int, int>(2, 9));
	NumCorporation.insert(pair<int, int>(3, 11));
	NumCorporation.insert(pair<int, int>(3, 13));
	NumCorporation.insert(pair<int, int>(3, 14));
	NumCorporation.insert(pair<int, int>(4, 16));
	NumCorporation.insert(pair<int, int>(4, 18));
	NumCorporation.insert(pair<int, int>(4, 19));
	NumCorporation.insert(pair<int, int>(5, 21));
	NumCorporation.insert(pair<int, int>(5, 23));
	NumCorporation.insert(pair<int, int>(5, 24));
	NumCorporation.insert(pair<int, int>(6, 26));
	NumCorporation.insert(pair<int, int>(6, 27));
	NumCorporation.insert(pair<int, int>(6, 29));
	NumCorporation.insert(pair<int, int>(7, 31));
	NumCorporation.insert(pair<int, int>(7, 32));
	NumCorporation.insert(pair<int, int>(7, 34));
	NumCorporation.insert(pair<int, int>(8, 37));
	NumCorporation.insert(pair<int, int>(8, 39));
}

Player::~Player() { }
void Player::setMoney(int money) { this->money = money;  }
void Player::setPosition(int position) { this->position = position; }
int Player::getPosition() { return position; }
void Player::buyFirm(int pos, Map &obj) {
	obj.GetMap(pos, money);    
	positionMyFirm.push_back(pos);
}
long Player::getMoneyPlayer() { return money; }
void Player::appMoney(int money) { this->money += money; }
void Player::getOutOfJail() { money -= 50; }
bool Player::getStart() { return start; }
void Player::setStart(bool start) { this->start = start; }
int Player::getSize() { return positionMyFirm.size(); }
void Player::setPositionMyFirm(int *arr) {for (int i = 0; i < positionMyFirm.size(); i++) arr[i] = positionMyFirm[i];}
void Player::sortVector() { sort(positionMyFirm.begin(), positionMyFirm.end()); }
void Player::Change(vector<int> one, vector<int> two, int* Firm, int money, int subtractmoney) {
	vector<int>::iterator it;
	this->money += money;
	this->money -= subtractmoney;
	int *arr = new int[one.size()];
	for (int i = 0; i < one.size(); i++) {
		for (int j = 0; j < 28; j++) {
			if (one[i] == j) {
				arr[i] = Firm[j];
			}
		}
	}
	for (int i = 0; i < one.size(); i++) {
		for (it = positionMyFirm.begin(); it != positionMyFirm.end(); it++) {
			if (*it == arr[i]) it = positionMyFirm.erase(it);
			if (it == positionMyFirm.end()) break;
		}
	}
	delete[]arr;
	arr = new int[two.size()];

	for (int i = 0; i < two.size(); i++) {
		for (int j = 0; j < 28; j++) {
			if (two[i] == j) {
				arr[i] = Firm[j];
			}
		}
	}
	for (int i = 0; i < two.size(); i++) {
		positionMyFirm.push_back(arr[i]);
	}
}
void Player::Rent(Player *player, int pos, Map &map, int CurrentPlayer, int numPlayer) {
	int pl = 4, mon = 0;
	bool Corp;
	for (int i = 0; i < numPlayer; i++) {
		for (int j = 0; j < player[i].positionMyFirm.size(); j++) {
			if (player[i].positionMyFirm[j] == pos) {
				pl = i;
				break;
			}
		}
		if (pl != 4)
			break;
	}
	if (pl != CurrentPlayer) {
		Corp = player[pl].isCorporation(pos, pl);
		if (Corp && pl != CurrentPlayer) {
			mon = map.getInfo(pos, 1);
			player[CurrentPlayer].money -= mon;
			player[pl].money += mon;
		}
		else {
			mon = map.getInfo(pos, 0);
			player[CurrentPlayer].money -= mon;
			player[pl].money += mon;
		}
	}
}
bool Player::isCorporation(int pos, int num) {
		NumMyCorporation.clear();
		int count = 0, m = 0, l = 0;
		for (iNumCorporation = NumCorporation.begin(); iNumCorporation != NumCorporation.end(); iNumCorporation++) {
			l = 0;
			if (m != (*iNumCorporation).first) m = 0;
			for (int j = 0; j < positionMyFirm.size(); j++) {
				if ((*iNumCorporation).second == positionMyFirm[j] && m == 0) {
					m = (*iNumCorporation).first;
					++count;
					break;
				}
				else if ((*iNumCorporation).second == positionMyFirm[j]) {
					if (m == (*iNumCorporation).first) {
						++count;
						if ((*iNumCorporation).second == 3) {
							NumMyCorporation.push_back((*iNumCorporation).first);
							break;
						}
						else if ((*iNumCorporation).second == 39) {
							NumMyCorporation.push_back((*iNumCorporation).first);
							break;
						}
						++iNumCorporation;
						if ((*iNumCorporation).first == m) {
							for (int k = 0; k < positionMyFirm.size(); k++) {
								if ((*iNumCorporation).second == positionMyFirm[k]) {
									NumMyCorporation.push_back((*iNumCorporation).first);
									cout << "Corporation" << endl;
									l = 1;
									break;
								}
							}
							if (l == 1)
								break;
						}
	
					}
					else m = 0;
				}
			}
		}
		for (iNumCorporation = NumCorporation.begin(); iNumCorporation != NumCorporation.end(); iNumCorporation++) {
			for(it = NumMyCorporation.begin(); it != NumMyCorporation.end(); it++)
			if ((*iNumCorporation).first == *it)
				if((*iNumCorporation).second == pos)
				return true;
		}
		return false;
}
