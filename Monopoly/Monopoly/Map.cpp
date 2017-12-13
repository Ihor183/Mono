#include "Map.h"
#include<fstream>

Map::Map() {}
Map::~Map() { }
ifstream& operator >> (ifstream &ifs, Map &obj)
{
	for (int i = 0; i < SIZE; i++) {
		obj.rent = new int[2];
		ifs >> obj.price >> obj.rent[0] >> obj.rent[1];
		obj.buy = false;
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
		if (point < 40 && *d < point) { ++i;
			a[0] = go[c][i].x;
			b[0] = go[c][i].y;
			*d = i;
			break;}
		else if (i < 39) {
			++i;
			a[0] = go[c][i].x;
			b[0] = go[c][i].y;
			*d = i;
			break;}
		else {
			i = 0;
			point %= 40;
			a[0] = go[c][i].x;
			b[0] = go[c][i].y;
			*d = i;}
}}}
void Map::setStartPosition(int* a, int* b, int c) {
	a[0] = go[c][0].x;
	b[0] = go[c][0].y;
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
int Map::getInfo(int pos, int num) {
	return mapi[pos].rent[num];
}