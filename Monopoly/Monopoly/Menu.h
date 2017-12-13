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
	Coordinate *DataTokens;
	Texture *tex_image, *tex_helpInstrument, tex_Background, *tex_check, *tex_check1;
	Sprite *spr_image, *spr_helpInstrument, spr_Background, *spr_check, *spr_check1;

public:
	Menu();
	Menu(RenderWindow &);
	~Menu();
	void NewMenu(RenderWindow &);
	void GetDataTokens(int*, int*, int*, int*, double*, double*);
	void setImage();
	string toStr(int);
	void trade(RenderWindow &, Player*, Map&, int, int, int*, vector<Sprite>, Text*);
};

