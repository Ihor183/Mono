#include "Player.h"

Player::Player() {
	money = 2000;
	position = 0;
	start = false;
	isJailCard = false;
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
void Player::getCommunityChest() {

}

void Player::getChance() {

}

void Player::getOutOfJail() { money -= 50; }
bool Player::getStart() { return start; }
void Player::setStart(bool start) { this->start = start; }
int Player::getSize() { return positionMyFirm.size(); }
void Player::setPositionMyFirm(int *arr) {
	for (int i = 0; i < positionMyFirm.size(); i++) {
		arr[i] = positionMyFirm[i];
	}
}
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
	