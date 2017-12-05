#include<SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<map>
#include"Menu.h"
#include"Map.h"
#include"Dice.h"
#include"Player.h"
#include<vector>

using namespace sf;
using namespace std;

std::string toStr(int var)
{
	std::stringstream tmp; tmp << var; return tmp.str();
}

int main() {
	RenderWindow App;
	App.create(VideoMode::getDesktopMode(), "Monopoly");
	int pos = 600, left = 300, top = 0, menuNum = 0;

	Font fnt_Arial;
	fnt_Arial.loadFromFile("fonts/arial.ttf");
	Text text("", fnt_Arial, 20);
	text.setStyle(Text::Bold);
	

	Texture txt_map, tex_tokens, tex_background, tex_Token[4], tex_Dice[6], tex_Button[10];
	txt_map.loadFromFile("images/map.png");
	tex_tokens.loadFromFile("images/tokens.tga");
	tex_background.loadFromFile("images/back.png");
	for (int i = 0; i < 10; i++)  tex_Button[i].loadFromFile("images/button" + toStr(i + 1) + ".png");
	for (int i = 0; i < 4; i++)   tex_Token[i].loadFromFile("images/tokens.tga");
	for (int i = 0; i < 6; i++)   tex_Dice[i].loadFromFile("images/de" + toStr(i + 1) + ".png");


	Sprite spr_backgr, spr_map, spr_Dice[6], spr_Button[10];
	vector<Sprite> spr_Token(4);
	spr_backgr.setTexture(tex_background);
	spr_map.setTexture(txt_map);
	spr_backgr.setPosition(0, 0);
    spr_map.setScale(Vector2f(0.45f, 0.45f));
	spr_map.setPosition(385, 6);

	for (int i = 0; i < spr_Token.size(); i++)  spr_Token[i].setTexture(tex_Token[i]);
	for (int i = 0; i < 6; i++)    spr_Dice[i].setTexture(tex_Dice[i]); 
	for (int i = 0; i < 10; i++) { spr_Button[i].setTexture(tex_Button[i]); spr_Button[i].setPosition(left, top += 60); }
	

	ifstream ifs;
	Map map;
	ifs.open("Coordinat Map.txt", ios::in);
	if (!ifs)
		return -1;

	ifs >> map;
	ifs.close();
    Menu menu(App);

	int a[4], b[4], c[4], d[4], g[4], h[4], control[] = { -1, -1 }, j = 0;
	double e[4], f[4];

	menu.GetDataTokens(a, b, c, d, e, f);

	for (int i = 0; i < 4; i++) { if (a[i] == 0) { control[j] = i; j++; }}

	if (control[0] != -1) spr_Token.erase(spr_Token.begin() + control[0]);
	if (control[1] != -1) spr_Token.erase(spr_Token.begin() + (control[1] - 1));
	
	for (int i = 0, k = 0; i < 4; i++) { 
		if ((control[0] == -1 || control[0] != i) && (control[1] == -1 || control[1] != i)) { 
			spr_Token[k].setTextureRect(IntRect(a[i], b[i], c[i], d[i]));
			map.setStartPosition(g, h, k); 
			spr_Token[k].setPosition(g[0], h[0]); 
			spr_Token[k].setScale(e[i] / 3, f[i] / 3); k++; 
		} else 
			continue; 
	}

	int Numplayer = 0;
	long PlayerMoney;
	Player *player = new Player[spr_Token.size()];

	Text *money = new Text[spr_Token.size()];

	for (int i = 0; i < spr_Token.size(); i++) {
		money[i].setFont(fnt_Arial);
		money[i].setCharacterSize(20);
		money[i].setStyle(Text::Bold);
		money[i].setFillColor(Color::Black);
	}

	for (int i = 0; i < spr_Token.size(); i++) {
		PlayerMoney = player[i].getMoneyPlayer();
		money[i].setString(toStr(PlayerMoney) + '$');
		switch (i) {
		case 0: money[i].setPosition(30, 70); break;
		case 1: money[i].setPosition(1280, 70); break;
		case 2: money[i].setPosition(30, 722); break;
		case 3: money[i].setPosition(1280, 722); break;
		}
	}

	Texture *tex_PlayerZone, *tex_TokenInPlayerZone;
	tex_PlayerZone = new Texture[spr_Token.size()];
	tex_TokenInPlayerZone = new Texture[spr_Token.size()];
	for (int i = 0; i < spr_Token.size(); i++) {
		tex_PlayerZone[i].loadFromFile("images/color.png");
		tex_TokenInPlayerZone[i].loadFromFile("images/tokens.tga");
	}
	Sprite *spr_PlayerZone, *spr_TokenInPlayerZone;
	spr_PlayerZone = new Sprite[spr_Token.size()];
	spr_TokenInPlayerZone = new Sprite[spr_Token.size()];
	for (int i = 0; i < spr_Token.size(); i++) {
		spr_PlayerZone[i].setTexture(tex_PlayerZone[i]);
		spr_TokenInPlayerZone[i].setTexture(tex_TokenInPlayerZone[i]);
		switch (i) {
		case 0: 
			spr_PlayerZone[i].setTextureRect(IntRect(55, 104, 58, 58)); 
			spr_PlayerZone[i].setScale(Vector2f(2.f, 2.f)); 
			spr_PlayerZone[i].setPosition(0, 0);
			for (int j = 0; j < 4; j++) {
				if (a[j] == 0) 
					continue;
				else {
					spr_TokenInPlayerZone[i].setTextureRect(IntRect(a[j], b[j], c[j], d[j]));
					spr_TokenInPlayerZone[i].setScale(Vector2f(e[j], f[j]));
					a[j] = 0;
					break;
				}
			}
			spr_TokenInPlayerZone[i].setPosition(30, 0);
			break;
		case 1: 
			spr_PlayerZone[i].setTextureRect(IntRect(130, 104, 58, 58)); 
			spr_PlayerZone[i].setScale(Vector2f(2.f, 2.f));
			spr_PlayerZone[i].setPosition(1250, 0);
			for (int j = 0; j < 4; j++) {
				if (a[j] == 0)
					continue;
				else {
					spr_TokenInPlayerZone[i].setTextureRect(IntRect(a[j], b[j], c[j], d[j]));
					spr_TokenInPlayerZone[i].setScale(Vector2f(e[j], f[j]));
					a[j] = 0;
					break;
				}
			}
			spr_TokenInPlayerZone[i].setPosition(1280, 0);
			break;
		case 2: 
			spr_PlayerZone[i].setTextureRect(IntRect(205, 104, 58, 58)); 
			spr_PlayerZone[i].setScale(Vector2f(2.f, 2.f)); 
			spr_PlayerZone[i].setPosition(0, 652);
			for (int j = 0; j < 4; j++) {
				if (a[j] == 0)
					continue;
				else {
					spr_TokenInPlayerZone[i].setTextureRect(IntRect(a[j], b[j], c[j], d[j]));
					spr_TokenInPlayerZone[i].setScale(Vector2f(e[j], f[j]));
					a[j] = 0;
					break;
				}
			}
			spr_TokenInPlayerZone[i].setPosition(30, 652);
			break;
		case 3: 
			spr_PlayerZone[i].setTextureRect(IntRect(281, 104, 58, 58)); 
			spr_PlayerZone[i].setScale(Vector2f(2.f, 2.f)); 
			spr_PlayerZone[i].setPosition(1250, 652);
			for (int j = 0; j < 4; j++) {
				if (a[j] == 0)
					continue;
				else {
					spr_TokenInPlayerZone[i].setTextureRect(IntRect(a[j], b[j], c[j], d[j]));
					spr_TokenInPlayerZone[i].setScale(Vector2f(e[j], f[j]));
					a[j] = 0;
					break;
				}
			}
			spr_TokenInPlayerZone[i].setPosition(1280, 652);
			break;
		}
	}

	int point[2];
	Dice dice;
	bool fl = false, isRoolDice = false;

	for (int i = 0; i < 4; i++) { a[i] = 0; b[i] = 0; }

	while (App.isOpen())
	{
		Event event;
		while (App.pollEvent(event))
		{
			if (event.type == Event::Closed)
				App.close();
		}
		menuNum = 0;
		spr_Button[0].setColor(Color::White);
		spr_Button[1].setColor(Color::White);
		spr_Button[2].setColor(Color::White);

		if (Numplayer == spr_Token.size())
			Numplayer = 0;

		App.clear();
		App.draw(spr_backgr);
		App.draw(spr_map);

		//for (int i = 0; i < spr_Token.size(); i++) {
			
		if (IntRect(300, 60, 58, 58).contains(Mouse::getPosition(App))) { 
			spr_Button[0].setColor(Color::Blue); 
			menuNum = 1; 
		}
		if (IntRect(300, 120, 58, 58).contains(Mouse::getPosition(App))) { 
			spr_Button[1].setColor(Color::Blue); ;
			menuNum = 2;
		}
		if (IntRect(300, 180, 58, 58).contains(Mouse::getPosition(App))) {
			spr_Button[2].setColor(Color::Blue); ;
			menuNum = 3;
		}
			if (Mouse::isButtonPressed(Mouse::Left) || menuNum == 3) {
				if (menuNum == 1 && isRoolDice == false) {
					player[Numplayer].ThrowDice(point);
					fl = true;
					isRoolDice = true;

					if (point[0] != point[1]) {
						spr_Dice[point[0] - 1].setPosition(600, 300);
						spr_Dice[point[1] - 1].setPosition(700, 300);
						App.draw(spr_Dice[point[0] - 1]);
						App.draw(spr_Dice[point[1] - 1]);
					}
					else {
						spr_Dice[point[0] - 1].setPosition(600, 300);
						App.draw(spr_Dice[point[0] - 1]);
						spr_Dice[point[0] - 1].setPosition(700, 300);
						App.draw(spr_Dice[point[1] - 1]);
					}
						int pos = player[Numplayer].getPosition();
					    map.setPosition(a, b, Numplayer, &pos, point);
						player[Numplayer].setPosition(pos);
						spr_Token[Numplayer].setPosition(a[0], b[0]);
						sleep(*new Time(microseconds(100)));
				}
				if (menuNum == 2 && isRoolDice == true) {
					Numplayer++;
					isRoolDice = false;
				}
				if (menuNum == 3) {
					int pos = player[Numplayer].getPosition();
					if (map.isBuy(pos) == false) {
						player[Numplayer].buyFirm(pos, map);
					}
					//player[Numplayer].buy();
				}
			}
		//}
		
		if (fl == true) {
			spr_Dice[point[0] - 1].setPosition(600, 300);
			App.draw(spr_Dice[point[0] - 1]);
			spr_Dice[point[0] - 1].setPosition(700, 300);
			App.draw(spr_Dice[point[1] - 1]);
		}
		
		for (int i = 0; i < 10; i++) App.draw(spr_Button[i]);

		for (int i = 0; i < spr_Token.size(); i++) App.draw(spr_Token[i]);
		for (int i = 0; i < spr_Token.size(); i++) App.draw(spr_PlayerZone[i]);
		for (int i = 0; i < spr_Token.size(); i++) App.draw(spr_TokenInPlayerZone[i]);
		for (int i = 0; i < spr_Token.size(); i++) {
			PlayerMoney = player[i].getMoneyPlayer();
			money[i].setString(toStr(PlayerMoney) + '$');
			App.draw(money[i]);
		}

		App.display();
		sleep(*new Time(milliseconds(100)));
	}

	return 0;
}

