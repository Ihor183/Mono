#include "Map.h"
#include<fstream>

Map::Map() {
}


Map::~Map() { }

ifstream& operator >> (ifstream &ifs, Map &obj)
{
	for (int i = 0; i < SIZE; i++) { 
		obj.rent = new int[6];
		if (i != 0 && i != 2 && i != 4 && i != 5 && i != 7 && i != 10 &&
			i != 12 && i != 15 && i != 17 && i != 20 && i != 22 && i != 25 &&
			i != 28 && i != 30 && i != 33 && i != 35 && i != 36 && i != 38) { 
			ifs >> obj.price; 
			for (int j = 0; j < 6; j++) 
				ifs >> obj.rent[j]; 
			ifs >> obj.housePrice >> obj.hotelPrice >> obj.mortgageValue; 
			obj.money = 0; 
			obj.buy = false; 
		}
		else if (i == 0) {
			obj.money = 200; 
			obj.price = 0; 
			for (int j = 0; j < 6; j++) obj.rent[j] = 0; 
			obj.housePrice = 0; 
			obj.hotelPrice = 0; 
			obj.mortgageValue = 0; 
		}
		else if (i == 2 || i == 7 || i == 10 || i == 17 || i == 20 || i == 22 || i == 30 || i == 33 || i == 36) { 
			obj.money = 0; 
			obj.price = 0; 
			for (int j = 0; j < 6; j++) obj.rent[j] = 0; 
			obj.housePrice = 0; 
			obj.hotelPrice = 0; 
			obj.mortgageValue = 0;
		}
		else if (i == 4 || i == 38) {
			if (i == 4) obj.money = -200; 
			else       obj.money = -100; 
			obj.price = 0; 
			for (int j = 0; j < 6; j++) obj.rent[j] = 0; 
			obj.housePrice = 0; 
			obj.hotelPrice = 0;
			obj.mortgageValue = 0;}

		else if (i == 5 || i == 15 || i == 25 || i == 35) { 
			obj.price = 200; 
			double k = 12.5; 
			for (int j = 0; j < 6; j++) { 
				if (j < 4) obj.rent[j] = k *= 2; 
				else obj.rent[j] = 0; 
			} 
			obj.housePrice = 0;
			obj.hotelPrice = 0; 
			obj.money = 0; 
			obj.mortgageValue = 100; 
		}
		obj.mapi.push_back(obj);
	}

	for (int i = 0; i < FOUR; i++)
		for (int j = 0; j < SIZE; j++) {
			ifs >> obj.go[i][j].x;
			ifs >> obj.go[i][j].y;
		}
		

	return ifs;
}

void Map::setPosition(int* a, int* b, int c, int *d, int &point) {
	for (int i = 0; i < SIZE; i++) {
		if (i == *d) {
			if (point < 40) { ++i;
				a[0] = go[c][i].x;
				b[0] = go[c][i].y;
				*d = i;
				break;
			}
			else if (i < 39) {
					++i;
					a[0] = go[c][i].x;
					b[0] = go[c][i].y;
					*d = i;
					break;
				}
			else {
				i = 0;
				point %= 40;
				a[0] = go[c][i].x;
				b[0] = go[c][i].y;
				*d = i;
			}
		}
	}
}

void Map::setStartPosition(int* a, int* b, int c) {
	a[0] = go[c][0].x;
	b[0] = go[c][0].y;
}

void Map::setBuyerFirm() {

}

bool Map::isBuy(int pos) {
	return mapi[pos].buy;
}

void Map::GetMap(int pos, long &money) {
	mapi[pos].buy = true;
	money -= mapi[pos].price;
}

void Map::goToJail(int* a, int* b, int c) {
	a[0] = go[c][10].x;
	b[0] = go[c][10].y;
}

void Map::getNumCorporation() {

}