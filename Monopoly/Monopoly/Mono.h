#pragma once

#include<SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<list>
#include<sstream>
#include<map>
#include"Menu.h"
#include"Map.h"
#include"Dice.h"
#include"Player.h"
#include<vector>

using namespace sf;
using namespace std;

const int ZERO = 0;
const int ONE = 1;
const int TWO = 2;
const int FIVE = 5;
const int SIX = 6;
const int EIGHT = 8;
const int TWEIGHT = 28;

class Mono
{
private:
	int left, top, menuNum, Size, nextPosition, pos, posForBuy, j, Numplayer;
	int *point, *count, *PlayerInJail, *a, *b, *c, *d, *g, *h, *control;
	double *e, *f;
	long PlayerMoney;
	bool fl, isRoolDice, go, buy;
	Font fnt_Arial;
	RenderWindow App;
	Text text, *money;
	Texture txt_map, tex_tokens, tex_background, *tex_PlayerZone, *tex_TokenInPlayerZone;
	Texture *tex_Token, *tex_Dice, *tex_Button, *tex_Rect, *tex_Chance, *tex_Comm;
	Sprite spr_backgr, spr_map, *spr_Dice, *spr_Button, *spr_Rect;
	Sprite *spr_Chance, *spr_Comm, *spr_PlayerZone, *spr_TokenInPlayerZone;
	ifstream ifs;
	Map map;
	Player *player;
	Dice dice;
	


public:
	Mono();
	~Mono();
	void start();
	string toStr(int);
};

