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
	Coordinate SqMap[SIZE];
	vector<DescriptionOfRectangles> mapi;
	CoordGo go[FOUR][SIZE];
	multimap<int, int> NumCorporation;
	//int NumCorporation[8];

public:
	Map();
	~Map();
	friend ifstream& operator >>(ifstream &, Map &);
	void setPosition(int*, int*, int, int*, int&);
	void setStartPosition(int*, int*, int);
	void setBuyerFirm();
	bool isBuy(int);
	void GetMap(int, long&);
	void goToJail(int*, int*, int);
	void getNumCorporation();
};

