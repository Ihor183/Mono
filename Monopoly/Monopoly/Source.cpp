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

string toStr(int var)
{
	std::stringstream tmp; tmp << var; return tmp.str();
}

int main() {
	RenderWindow App;
	App.create(VideoMode::getDesktopMode(), "Monopoly");
	int left = 300, top = 0, menuNum = 0;

	Font fnt_Arial;
	fnt_Arial.loadFromFile("fonts/arial.ttf");
	Text text("", fnt_Arial, 20);
	text.setStyle(Text::Bold);
	

	Texture txt_map, tex_tokens, tex_background, tex_Token[4], tex_Dice[6], tex_Button[5], tex_Rect[28],
		tex_Chance[8], tex_Comm[8];
	txt_map.loadFromFile("images/map.png");
	tex_tokens.loadFromFile("images/tokens.tga");
	tex_background.loadFromFile("images/back.png");
	for (int i = 0; i < 28; i++)  tex_Rect[i].loadFromFile("images/white.png");
	for (int i = 0; i < 5; i++)  tex_Button[i].loadFromFile("images/button" + toStr(i + 1) + ".png");
	for (int i = 0; i < 4; i++)   tex_Token[i].loadFromFile("images/tokens.tga");
	for (int i = 0; i < 6; i++)   tex_Dice[i].loadFromFile("images/de" + toStr(i + 1) + ".png");
	for (int i = 0; i < 8; i++) { 
		tex_Chance[i].loadFromFile("images/" + toStr(i + 1) + ".png"); 
		tex_Comm[i].loadFromFile("images/c" + toStr(i + 1) + ".png");
	}

	Sprite spr_backgr, spr_map, spr_Dice[6], spr_Button[5], spr_Rect[28], spr_Chance[8], spr_Comm[8];
	vector<Sprite> spr_Token(4);
	spr_backgr.setTexture(tex_background);
	spr_map.setTexture(txt_map);
	spr_backgr.setPosition(0, 0);
    spr_map.setScale(Vector2f(0.45f, 0.45f));
	spr_map.setPosition(385, 6);
	for (int i = 0; i < 8; i++) {
		spr_Chance[i].setTexture(tex_Chance[i]);
		spr_Chance[i].setPosition(455, 259);
		spr_Comm[i].setTexture(tex_Comm[i]);
		spr_Comm[i].setPosition(455, 259);
	}
	for (int i = 0; i < 28; i++) {
		spr_Rect[i].setTexture(tex_Rect[i]);
		if ((i >= 0 && i < 6) || (i > 13 && i < 22)) {
			spr_Rect[i].setTextureRect(IntRect(1, 1, 41, 10));
		}
		else {
			spr_Rect[i].setTextureRect(IntRect(1, 1, 10, 41));
		}
	}
		
	for (int i = 0; i < 28; i++) {
		switch(i) {
		case 0: spr_Rect[i].setPosition(925, 695); break;
		case 1: spr_Rect[i].setPosition(814, 695); break;
		case 2: spr_Rect[i].setPosition(703, 695); break;
		case 3: spr_Rect[i].setPosition(645, 695); break;
		case 4: spr_Rect[i].setPosition(537, 695); break;
		case 5: spr_Rect[i].setPosition(480, 695); break;
		case 6: spr_Rect[i].setPosition(370, 545); break;
		case 7: spr_Rect[i].setPosition(370, 488); break;
		case 8: spr_Rect[i].setPosition(370, 431); break;
		case 9: spr_Rect[i].setPosition(370, 377); break;
		case 10: spr_Rect[i].setPosition(370, 319); break;
		case 11: spr_Rect[i].setPosition(370, 264); break;
		case 12: spr_Rect[i].setPosition(370, 156); break;
		case 13: spr_Rect[i].setPosition(370, 99); break;
		case 14: spr_Rect[i].setPosition(480, 0); break;
		case 15: spr_Rect[i].setPosition(594, 0); break;
		case 16: spr_Rect[i].setPosition(648, 0); break;
		case 17: spr_Rect[i].setPosition(703, 0); break;
		case 18: spr_Rect[i].setPosition(760, 0); break;
		case 19: spr_Rect[i].setPosition(814, 0); break;
		case 20: spr_Rect[i].setPosition(870, 0); break;
		case 21: spr_Rect[i].setPosition(925, 0); break;
		case 22: spr_Rect[i].setPosition(1065, 99); break;
		case 23: spr_Rect[i].setPosition(1065, 156); break;
		case 24: spr_Rect[i].setPosition(1065, 264); break;
		case 25: spr_Rect[i].setPosition(1065, 319); break;
		case 26: spr_Rect[i].setPosition(1065, 431); break;
		case 27: spr_Rect[i].setPosition(1065, 545); break;
		}
	}
	for (int i = 0; i < spr_Token.size(); i++)  spr_Token[i].setTexture(tex_Token[i]);
	for (int i = 0; i < 6; i++)    spr_Dice[i].setTexture(tex_Dice[i]); 
	for (int i = 0; i < 5; i++) { spr_Button[i].setTexture(tex_Button[i]); spr_Button[i].setPosition(left, top += 60); }
	

	ifstream ifs;
	Map map;
	ifs.open("Coordinat Map.txt", ios::in);
	if (!ifs)
		return -1;

	ifs >> map;
	ifs.close();
    Menu menu(App);
	menu.setImage();
	//menu.t(App);

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

	int point[2], nextPosition, pos, posForBuy, *count, *PlayerInJail;
	int Firm[] = { 1, 3, 5, 6, 8, 9, 11, 12, 13, 14, 15, 16, 18, 19, 21, 23, 24, 25, 26, 27, 28, 29, 31, 32, 34, 35, 37, 39};
	PlayerInJail = new int[spr_Token.size()];
	count = new int[spr_Token.size()];
	for (int i = 0; i < spr_Token.size(); i++) count[i] = 0;
	Dice dice;
	bool fl = false, isRoolDice = false, go = false, buy = false;

	for (int i = 0; i < 4; i++) { a[i] = 0; b[i] = 0; }
	for (int i = 0; i < spr_Token.size(); i++) { count[i] = 0; PlayerInJail[i] = 0; }

	int Size = spr_Token.size();

	//player[0].setPosition(28);
	//player[1].setPosition(28);
	

	while (App.isOpen())
	{
		Event event;
		while (App.pollEvent(event))
		{
			if (event.type == Event::Closed)
				App.close();
		}
		menuNum = 0;
		posForBuy = player[Numplayer].getPosition();
		spr_Button[0].setColor(Color::White);
		spr_Button[1].setColor(Color::White);
		spr_Button[2].setColor(Color::White);
		spr_Button[3].setColor(Color::White);
		spr_Rect[0].setColor(Color::White);

		if (Numplayer == spr_Token.size())
			Numplayer = 0;

		App.clear();
		App.draw(spr_backgr);
		App.draw(spr_map);

		if (posForBuy == 0 && player[Numplayer].getStart() == true) {
			player[Numplayer].appMoney(200);
			player[Numplayer].setStart(false);
		}
			
		if (IntRect(300, 60, 58, 58).contains(Mouse::getPosition(App))) { 
			spr_Button[0].setColor(Color::Blue); 
			menuNum = 1; 
		}
		if (IntRect(300, 120, 58, 58).contains(Mouse::getPosition(App))) { 
			spr_Button[1].setColor(Color::Blue);
			menuNum = 2;
		}
		if (IntRect(300, 180, 58, 58).contains(Mouse::getPosition(App))) {
			spr_Button[2].setColor(Color::Blue); 
			menuNum = 3;
		}
		if (IntRect(300, 240, 58, 58).contains(Mouse::getPosition(App))) {
			spr_Button[3].setColor(Color::Blue);
			menuNum = 4;
		}
			if (Mouse::isButtonPressed(Mouse::Left) || menuNum == 3 || menuNum == 2 || menuNum == 1) {
				if (menuNum == 1 && isRoolDice == false && go == false) {
					player[Numplayer].ThrowDice(point);
					fl = true;
					isRoolDice = true;
					player[Numplayer].setStart(true);

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
					if (PlayerInJail[Numplayer] == 0) {
						pos = player[Numplayer].getPosition();
						nextPosition = (pos + (point[0] + point[1]));
						go = true;
					}
					else {
						if (point[0] == point[1]) {
							pos = 10;
							nextPosition = (pos + (point[0] + point[1]));
							PlayerInJail[Numplayer] = 0;
					    	go = true;
						}
						else ++count[Numplayer];

						if (count[Numplayer] == 3) {
							player[Numplayer].getOutOfJail();
							PlayerInJail[Numplayer] = 0;
							pos = 10;
							nextPosition = (pos + (point[0] + point[1]));
							go = true;
						}
					}
					
						sleep(*new Time(microseconds(100)));
				}
				if (menuNum == 2 && isRoolDice == true && go == false) {
					++Numplayer;
					pos = player[Numplayer].getPosition();
					isRoolDice = false;
				}
				if (menuNum == 3 && go == false) {
					int pos = player[Numplayer].getPosition();
					for (int i = 0; i < 28; i++) if (pos == Firm[i]) { buy = true; break; }
					if (map.isBuy(pos) == false && buy) {
						player[Numplayer].buyFirm(pos, map);
						int RectB;
						for (int i = 0; i < 28; i++) {
							if (pos == Firm[i])
								RectB = i;
						}
						switch (Numplayer) {
						case 0: spr_Rect[RectB].setColor(Color::Blue); break;
						case 1: spr_Rect[RectB].setColor(Color::Green); break;
						case 2: spr_Rect[RectB].setColor(Color::Color(241, 156, 187)); break;
						case 3: spr_Rect[RectB].setColor(Color::Red); break;
						}
						buy = false;
					}
				}
				if (menuNum == 4) {
					menu.trade(App, player, map, Size, Numplayer, Firm, spr_Token, money);
					int size, Cast = 0;
					for (int i = 0; i < spr_Token.size(); i++) {
						size = player[i].getSize();

						int *arr = new int[size];
						player[i].setPositionMyFirm(arr);
						for (int j = 0; j < size; j++) {
							for (int k = 0; k < 28; k++) {
								if (arr[j] == Firm[k]) {
									arr[j] = k;
									break;
								}
							}
							switch (i) {
							case 0: spr_Rect[arr[j]].setColor(Color::Blue); break;
							case 1: spr_Rect[arr[j]].setColor(Color::Green); break;
							case 2: spr_Rect[arr[j]].setColor(Color::Color(241, 156, 187)); break;
							case 3: spr_Rect[arr[j]].setColor(Color::Red); break;
							}
						}
					}
					/*for (int i = 0; i < 28; i++) {
						if (pos == Firm[i])
							RectB = i;
					}

					for (int i = 0; i < spr_Token.size(); i++) {
						switch (Numplayer) {
						case 0: spr_Rect[RectB].setColor(Color::Blue); break;
						case 1: spr_Rect[RectB].setColor(Color::Green); break;
						case 2: spr_Rect[RectB].setColor(Color::Color(241, 156, 187)); break;
						case 3: spr_Rect[RectB].setColor(Color::Red); break;
						}
					}*/
				}

			}

			if (go == false) {
				if ((pos == 2 || pos == 17 || pos == 33) && player[Numplayer].getStart()) { 
					player[Numplayer].getCommunityChest(); 
					player[Numplayer].setStart(false);
				}
				if (pos == 4 && player[Numplayer].getStart()) {
					player[Numplayer].appMoney(-200);
					player[Numplayer].setStart(false);
				}
				if ((pos == 7 || pos == 22 || pos == 36) && player[Numplayer].getStart()) {
					player[Numplayer].getChance();
					player[Numplayer].setStart(false);
				}
				if (pos == 10 || pos == 20) continue;
				if (pos == 30) {
					pos = player[Numplayer].getPosition();
					map.goToJail(a, b, Numplayer);
					player[Numplayer].setPosition(pos);
					spr_Token[Numplayer].setPosition(a[0], b[0]);
					PlayerInJail[Numplayer] = 1;
				}
				if (pos == 38 && player[Numplayer].getStart()) {
					player[Numplayer].appMoney(-100);
					player[Numplayer].setStart(false);
				}
			}
		
		if (fl == true) {
			spr_Dice[point[0] - 1].setPosition(600, 300);
			App.draw(spr_Dice[point[0] - 1]);
			spr_Dice[point[0] - 1].setPosition(700, 300);
			App.draw(spr_Dice[point[1] - 1]);
		}

		if (go == true) {
			if (pos == nextPosition) go = false;
			else {
				map.setPosition(a, b, Numplayer, &pos, nextPosition);
				player[Numplayer].setPosition(pos);
				spr_Token[Numplayer].setPosition(a[0], b[0]);
			}
			sleep(*new Time(milliseconds(200)));
		}

		
		for (int i = 0; i < 5; i++) App.draw(spr_Button[i]);
		

		for (int i = 0; i < spr_Token.size(); i++) App.draw(spr_Token[i]);
		for (int i = 0; i < spr_Token.size(); i++) App.draw(spr_PlayerZone[i]);
		for (int i = 0; i < spr_Token.size(); i++) App.draw(spr_TokenInPlayerZone[i]);
		for (int i = 0; i < spr_Token.size(); i++) {
			PlayerMoney = player[i].getMoneyPlayer();
			money[i].setString(toStr(PlayerMoney) + '$');
			App.draw(money[i]);
		}
		for (int i = 0; i < 28; i++) App.draw(spr_Rect[i]); 
		App.display();
		sleep(*new Time(milliseconds(100)));
	}

	return 0;
}

