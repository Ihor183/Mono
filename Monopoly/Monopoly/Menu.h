#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>
#include "Tokens.h"
#include"Player.h"
#include<map>
#include<sstream>
#include"Map.h"

using namespace sf;
using namespace std;

class Menu {
private:
	Coordinate DataTokens[4];
	Texture tex_image[28], tex_helpInstrument[6], tex_Background, tex_check[18], tex_check1[18];
	Sprite spr_image[28], spr_helpInstrument[6], spr_Background, spr_check[18], spr_check1[18];

public:
	Menu();
	Menu(RenderWindow &);
	~Menu();
	void NewMenu(RenderWindow &);
	void GetDataTokens(int*, int*, int*, int*, double*, double*);
	void setImage();
	string toStr(int);
	void trade(RenderWindow &, Player*, Map&, int, int, int*, vector<Sprite>, Text*);
	void t(RenderWindow &);
};

