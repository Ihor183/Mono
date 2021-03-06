#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include"Coordinate.h"
#include"DescriptionOfRectangles.h"
#include"CoordGo.h"

const int SIZE = 40;
const int FOUR = 4;

using namespace std;

class Map : public DescriptionOfRectangles{
protected:
	vector<DescriptionOfRectangles> mapi;
	CoordGo go[FOUR][SIZE];
public:
	Map();
	~Map();
	friend ifstream& operator >>(ifstream &, Map &);
	void setPosition(int*, int*, int, int*, int&);
	void setStartPosition(int*, int*, int);
	bool isBuy(int);
	void GetMap(int, long&);
	void goToJail(int*, int*, int);
	int getInfo(int, int);
};

