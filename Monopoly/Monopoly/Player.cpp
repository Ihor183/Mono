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

void Player::buyFirm(int pos, Map &map) {
	//map[pos].buy = true;
	/*map[pos].buy = true;
	money -= map[pos].price;
	positionMyFirm.push_back(pos);*/

}