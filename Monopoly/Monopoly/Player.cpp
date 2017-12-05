#include "Player.h"

Player::Player() {
	money = 2000;
	position = 0;
	start = false;
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