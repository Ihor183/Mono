#include "Menu.h"

Menu::Menu() { }

Menu::~Menu() { }

string Menu :: toStr(int var) { stringstream tmp; tmp << var; return tmp.str(); }

Menu::Menu(RenderWindow& window) {
	Font fnt_Arial;
	fnt_Arial.loadFromFile("fonts/arial.ttf");
	Text text[3];
	string NewGame = "New Game";
	string Options = "Options";
	string Exit = "Exit";

	for (int i = 0; i < 3; i++) {
		text[i].setFont(fnt_Arial);
		text[i].setCharacterSize(30);
		text[i].setStyle(Text::Bold);
		text[i].setFillColor(Color::Black);
	}

	text[0].setString(NewGame);
	text[0].setPosition(80, 300);
	text[1].setString(Options);
	text[1].setPosition(80, 360);
	text[2].setString(Exit);
	text[2].setPosition(80, 420);

	Texture menuBackground;
	menuBackground.loadFromFile("images/intro.tga");

	Sprite menuBg(menuBackground);
	menuBg.setPosition(0, 0);
	menuBg.setScale(Vector2f(1.7f, 1.225f));

	bool isMenu = 1;
	int menuNum = 0;

	while (window.isOpen() && isMenu)
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		for (int i = 0; i < 3; i++) 
			text[i].setFillColor(Color::Black);

		menuNum = 0;

		window.clear();
		if (IntRect(80, 300, 300, 50).contains(Mouse::getPosition(window))) { text[0].setFillColor(Color::White); menuNum = 1; }
		if (IntRect(80, 360, 300, 50).contains(Mouse::getPosition(window))) { text[1].setFillColor(Color::Green); menuNum = 2; }
		if (IntRect(80, 420, 300, 50).contains(Mouse::getPosition(window))) { text[2].setFillColor(Color::Blue); menuNum = 3; }
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) {
				NewMenu(window);
				isMenu = false;
			}
			if (menuNum == 2) { /*window.draw(menu2);*/ window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
			if (menuNum == 3) { window.close(); isMenu = false; }
		}
		window.draw(menuBg);
		for (int i = 0; i < 3; i++)
			window.draw(text[i]);
		window.display();

	}
}

void Menu :: NewMenu(RenderWindow& window) {
	Texture tex_Plcol[8], tex_Token[4], menuBackground;
	menuBackground.loadFromFile("images/back1.png");
	for (int i = 0; i < 8; i++) {
		if (i < 4) {
			tex_Token[i].loadFromFile("images/tokens.tga");
			tex_Plcol[i].loadFromFile("images/color.png");
		}
		if (i > 3) tex_Plcol[i].loadFromFile("images/Back3.png");
	}

	Sprite spr_Plcol[8], spr_Token[4]/*, menu2(menuTexture4)*/, menuBg(menuBackground);
	//menu2.setPosition(80, 360);
	menuBg.setPosition(0, 0);
	for (int i = 0; i < 8; i++) {
		if (i < 4) {
			spr_Plcol[i].setTexture(tex_Plcol[i]);
			spr_Token[i].setTexture(tex_Token[i]);
		}else spr_Plcol[i].setTexture(tex_Plcol[i]);
	}

	for (int i = 0; i < 8; i++) {
		if (i == 0) { 
			spr_Plcol[i].setTextureRect(IntRect(55, 104, 58, 58));
			spr_Plcol[i].setPosition(80, 100);
		}

		if (i == 1) {
			spr_Plcol[i].setTextureRect(IntRect(130, 104, 58, 58));
			spr_Plcol[i].setPosition(1228, 100);
		}

		if (i == 2) {
			spr_Plcol[i].setTextureRect(IntRect(205, 104, 58, 58));
			spr_Plcol[i].setPosition(80, 200);
		}

		if (i == 3) {
			spr_Plcol[i].setTextureRect(IntRect(281, 104, 58, 58));
			spr_Plcol[i].setPosition(1228, 200);
		}

		if (i > 3) { spr_Plcol[i].setTextureRect(IntRect(0, 0, 120, 58));

			if (i == 4) spr_Plcol[i].setPosition(138, 100);
			if (i == 5) spr_Plcol[i].setPosition(1108, 100);
			if (i == 6) spr_Plcol[i].setPosition(138, 200);
			if (i == 7) spr_Plcol[i].setPosition(1108, 200);
		}
	}
	int a[4], b[4], c[4], d[4];
	double e[4], f[4];

	for (int i = 0; i < 4; i++){
		a[i] = 0, b[i] = 0, c[i] = 1, d[i] = 1, e[i] = 0.0, f[i] = 0.0;
	}

	for (int i = 0; i < 4; i++) {
		spr_Token[i].setTextureRect(IntRect(a[i], b[i], c[i], d[i]));
		if (i == 0) spr_Token[i].setPosition(80, 100);
		if (i == 1) spr_Token[i].setPosition(1228, 100);
		if (i == 2) spr_Token[i].setPosition(80, 200);
		if (i == 3) spr_Token[i].setPosition(1228, 200);
	}

	Tokens tokens;
	ifstream ifs;
	ifs.open("Tokens.txt", ios::in);
	if (!ifs)
		return;

	ifs >> tokens;
	ifs.close();

	bool isMenu = 1;
	int menuNum = 0, i = 0;

	string Select = "Select";
	string NotSelect = "Not Selecting";
	string Play = "Play";
	string Back = "Back";

	Font fnt_Arial;
	fnt_Arial.loadFromFile("fonts/arial.ttf");
	Text text[6];
	for (int i = 0; i < 6; i++) {
		if (i > 3) {
			text[i].setFont(fnt_Arial);
			text[i].setCharacterSize(30);
			text[i].setStyle(Text::Bold);

			if (i == 4) {
				text[i].setString(Play);
				text[i].setPosition(600, 300);
			}
			if (i == 5) {
				text[i].setString(Back);
				text[i].setPosition(600, 360);
			}

			continue;
		}
		text[i].setFont(fnt_Arial);
		text[i].setCharacterSize(14);
		text[i].setStyle(Text::Bold);
		text[i].setString(NotSelect);
	}

	text[0].setPosition(150, 120);
	text[1].setPosition(1110, 120);
	text[2].setPosition(150, 220);
	text[3].setPosition(1110, 220);

	int isSelect[4] = { 0, 0, 0, 0 };

	while (window.isOpen() && isMenu)
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
        menuNum = 0;
		window.clear();

		for (int i = 0; i < 6; i++) 
			text[i].setFillColor(Color::Black);

		if (IntRect(138, 100, 120, 58).contains(Mouse::getPosition(window))) {
			text[0].setFillColor(Color::White);
			if (Mouse::isButtonPressed(Mouse::Left)) {
				if (isSelect[0] == 0) {
					isSelect[0] = 1;
					text[0].setString(Select);
				}
				else {
					isSelect[0] = 0;
					text[0].setString(NotSelect);

					a[0] = 0, b[0] = 0, c[0] = 1, d[0] = 1, e[0] = 0.0, f[0] = 0.0;
					spr_Token[0].setTextureRect(IntRect(a[0], b[0], c[0], d[0]));
					spr_Token[0].setPosition(80, 100);
				}
			}
			sleep(*new Time(milliseconds(150)));
		}

		if (IntRect(1108, 100, 120, 58).contains(Mouse::getPosition(window))) {
			text[1].setFillColor(Color::White);
			if (Mouse::isButtonPressed(Mouse::Left)) {
				if (isSelect[1] == 0) {
					isSelect[1] = 1;
					text[1].setString(Select);
				}
				else {
					isSelect[1] = 0;
					text[1].setString(NotSelect);

					a[1] = 0, b[1] = 0, c[1] = 1, d[1] = 1, e[1] = 0.0, f[1] = 0.0;
					spr_Token[1].setTextureRect(IntRect(a[1], b[1], c[1], d[1]));
					spr_Token[1].setPosition(1228, 100);
				}
			}
			sleep(*new Time(milliseconds(150)));
		}

		if (IntRect(138, 200, 120, 58).contains(Mouse::getPosition(window))) {
			text[2].setFillColor(Color::White);
			if (Mouse::isButtonPressed(Mouse::Left)) {
				if (isSelect[2] == 0) {
					isSelect[2] = 1;
					text[2].setString(Select);
				}
				else {
					isSelect[2] = 0;
					text[2].setString(NotSelect);

					a[2] = 0, b[2] = 0, c[2] = 1, d[2] = 1, e[2] = 0.0, f[2] = 0.0;
					spr_Token[2].setTextureRect(IntRect(a[2], b[2], c[2], d[2]));
					spr_Token[2].setPosition(80, 200);
				}
			}
			sleep(*new Time(milliseconds(150)));
		}

		if (IntRect(1108, 200, 120, 58).contains(Mouse::getPosition(window))) {
			text[3].setFillColor(Color::White);
			if (Mouse::isButtonPressed(Mouse::Left)) {
				if (isSelect[3] == 0) {
					isSelect[3] = 1;
					text[3].setString(Select);
				}
				else {
					isSelect[3] = 0;
					text[3].setString(NotSelect);

					a[3] = 0, b[3] = 0, c[3] = 1, d[3] = 1, e[3] = 0.0, f[3] = 0.0;
					spr_Token[3].setTextureRect(IntRect(a[3], b[3], c[3], d[3]));
					spr_Token[3].setPosition(1228, 200);
				}
			}
			sleep(*new Time(milliseconds(150)));
		}

		if (IntRect(80, 100, 58, 58).contains(Mouse::getPosition(window)))   menuNum = 1;
		if (IntRect(1228, 100, 58, 58).contains(Mouse::getPosition(window))) menuNum = 2;
		if (IntRect(80, 200, 58, 58).contains(Mouse::getPosition(window)))   menuNum = 3;
		if (IntRect(1228, 200, 58, 58).contains(Mouse::getPosition(window))) menuNum = 4;
		
		if (IntRect(600, 300, 300, 50).contains(Mouse::getPosition(window))) { 
			text[4].setFillColor(Color::White);
			int count = 0, countT = 0;
			for (int i = 0; i < 4; i++) {
				if (isSelect[i] == 1) count++;
				if (a[i] != 0)        countT++;
			}
			if(count >= 2 && countT >= 2) menuNum = 5;
		}
		
		if (IntRect(600, 360, 300, 50).contains(Mouse::getPosition(window))) { text[5].setFillColor(Color::White); menuNum = 6; }
        if (Mouse::isButtonPressed(Mouse::Left)) {
			
			if (menuNum == 1 && isSelect[0] == 1) {
				tokens.getToken(&a[0], &b[0], &c[0], &d[0], &e[0], &f[0]);
				spr_Token[0].setTextureRect(IntRect(a[0], b[0], c[0], d[0]));
				spr_Token[0].setScale(Vector2f(e[0], f[0]));
				spr_Token[0].setPosition(80, 100);
				sleep(*new Time(milliseconds(200)));
			}

			if (menuNum == 2 && isSelect[1] == 1) {
				tokens.getToken(&a[1], &b[1], &c[1], &d[1], &e[1], &f[1]);
				spr_Token[1].setTextureRect(IntRect(a[1], b[1], c[1], d[1]));
				spr_Token[1].setScale(Vector2f(e[1], f[1]));
				spr_Token[1].setPosition(1228, 100);
				sleep(*new Time(milliseconds(200)));
			}

			if (menuNum == 3 && isSelect[2] == 1) {
				tokens.getToken(&a[2], &b[2], &c[2], &d[2], &e[2], &f[2]);
				spr_Token[2].setTextureRect(IntRect(a[2], b[2], c[2], d[2]));
				spr_Token[2].setScale(Vector2f(e[2], f[2]));
				spr_Token[2].setPosition(80, 200);
				sleep(*new Time(milliseconds(200)));
			}

			if (menuNum == 4 && isSelect[3] == 1) {
				tokens.getToken(&a[3], &b[3], &c[3], &d[3], &e[3], &f[3]);
				spr_Token[3].setTextureRect(IntRect(a[3], b[3], c[3], d[3]));
				spr_Token[3].setScale(Vector2f(e[3], f[3]));
				spr_Token[3].setPosition(1228, 200);
				sleep(*new Time(milliseconds(200)));
			}

			if (menuNum == 5) { 
				for (int i = 0; i < 4; i++) {
					DataTokens[i].x = a[i];
					DataTokens[i].y = b[i];
					DataTokens[i].Wight = c[i];
					DataTokens[i].Height = d[i];
					DataTokens[i].vec2f1 = e[i];
					DataTokens[i].vec2f2 = f[i];
				}
				 isMenu = false; 
				}

			if (menuNum == 6) window.close(); 
			
		}

		window.draw(menuBg);

		for (int i = 0; i < 8; i++) window.draw(spr_Plcol[i]);
        for (int i = 0; i < 4; i++) window.draw(spr_Token[i]);
		for (int i = 0; i < 6; i++) window.draw(text[i]);

		window.display();
	}
}

void Menu::GetDataTokens(int* a, int* b, int* c, int* d, double* e, double* f) {
	for (int i = 0; i < 4; i++) {
		a[i] = DataTokens[i].x;
		b[i] = DataTokens[i].y;
		c[i] = DataTokens[i].Wight;
		d[i] = DataTokens[i].Height;
		e[i] = DataTokens[i].vec2f1;
		f[i] = DataTokens[i].vec2f2;
	}
}

void Menu::setImage() {
	tex_Background.loadFromFile("images/backForTrade.png");
	for (int i = 0; i < 18; i++) { tex_check[i].loadFromFile("images/check.png"); tex_check1[i].loadFromFile("images/check.png"); }
	for (int i = 0; i < 28; i++) tex_image[i].loadFromFile("images/Firm" + toStr(i + 1) + ".png");
	for (int i = 0; i < 6; i++)
	{
		if(i == 0 || i == 1)
		tex_helpInstrument[i].loadFromFile("images/i1.png");
		if (i == 2)
			tex_helpInstrument[i].loadFromFile("images/i2.png");
		if (i == 3)
			tex_helpInstrument[i].loadFromFile("images/i3.png");
		if (i == 4 || i == 5)
			tex_helpInstrument[i].loadFromFile("images/i4.png");
	}


	spr_Background.setTexture(tex_Background);
	spr_Background.setPosition(0, 0);
	spr_Background.setScale(Vector2f(2.f, 2.f));
	for (int i = 0; i < 18; i++) { 
		spr_check[i].setTexture(tex_check[i]); spr_check[i].setScale(Vector2f(0.1f, 0.1f));
		spr_check1[i].setTexture(tex_check1[i]); spr_check1[i].setScale(Vector2f(0.1f, 0.1f));
	}
	for (int i = 0; i < 28; i++) { spr_image[i].setTexture(tex_image[i]); spr_image[i].setScale(Vector2f(0.31f, 0.4f)); }
	for (int i = 0; i < 6; i++) spr_helpInstrument[i].setTexture(tex_helpInstrument[i]);
}

void Menu::trade(RenderWindow &window, Player *player, Map &map, int Size, int CurrentPlayer, int* Firm, vector<Sprite> spr_token, Text *money) {
	bool isMenu = 1;
	int menuNum = 0, pos = 0, pos1 = 0;
	vector<int> numChecks;
	vector<int> numChecks1;
	vector<int> one;
	vector<int> two;
	vector<int>::iterator it;
	string mon, mon1;
	int moneyFirstPl = 0, moneySecondPl = 0;
	int x, y, count, count1, x2, y2, count2 = 0, count3 = 0;
	Font fnt_Arial;
	fnt_Arial.loadFromFile("fonts/arial.ttf");
	Text text[6];
	
	for (int i = 0; i < 6; i++) {
		text[i].setFont(fnt_Arial);
		text[i].setCharacterSize(20);
		text[i].setStyle(Text::Bold);
		text[i].setFillColor(Color::White);
		if (i == 0) {
			text[i].setPosition(610, 0);
			text[i].setString("This Player");
		}
		if (i == 1) {
			text[i].setPosition(615, 100);
			text[i].setString("Trade with");
		}
		if (i == 2) {
			text[i].setPosition(300, 540);
			text[i].setString("Click if all good");
		}
		if (i == 3) {
			text[i].setPosition(983, 540);
			text[i].setString("Cick if you agree");
		}
		if (i == 4) {
			text[i].setPosition(500, 700);
		}
		if (i == 5) {
			text[i].setPosition(866, 700);
		}
	}

	spr_helpInstrument[0].setPosition(315, 570);
	spr_helpInstrument[1].setPosition(998, 570);
	spr_helpInstrument[2].setPosition(1060, 570);
	spr_helpInstrument[3].setPosition(630, 530);
	spr_helpInstrument[4].setPosition(906, 570);
	spr_helpInstrument[5].setPosition(400, 570);

	int *arr, *arr1, size1 = -1, numPlayer = 0, pl = 0;
	bool isClick = false, isChecked[18], isChecked1[18], buy = false;
	int size = player[CurrentPlayer].getSize();
	arr = new int[size];

	for (int i = 0; i < 18; i++) { isChecked[i] = false; isChecked1[i] = false; }

	Vector2f obj = spr_token[CurrentPlayer].getScale();
	obj.x *= 4; obj.y *= 4;

	spr_token[CurrentPlayer].setPosition(630, 25);
	spr_token[CurrentPlayer].setScale(obj);
	

	int x1 = 630, y1 = 70;
	

	for (int i = 0; i < spr_token.size(); i++) {
		if (i != CurrentPlayer) {
			obj = spr_token[i].getScale();
			obj.x *= 4; obj.y *= 4;

			spr_token[i].setPosition(x1, y1 += 80);
			spr_token[i].setScale(obj);
		}
	}

	player[CurrentPlayer].sortVector();
	player[CurrentPlayer].setPositionMyFirm(arr);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 28; j++) {
			if (arr[i] == Firm[j]) {
				arr[i] = j;
			}
		}
	}

	while (window.isOpen() && isMenu)
	{
		x = -100; y = 0, count = -1;
		x2 = 650; y2 = 0, count1 = -1;
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		menuNum = 0;
		window.clear();

		spr_helpInstrument[0].setColor(Color::White);
		spr_helpInstrument[1].setColor(Color::White);
		spr_helpInstrument[2].setColor(Color::White);
		spr_helpInstrument[3].setColor(Color::White);
		spr_helpInstrument[4].setColor(Color::White);
		spr_helpInstrument[5].setColor(Color::White);

			for (int i = 0; i < spr_token.size(); i++)
				if (i != CurrentPlayer)
					spr_token[i].setColor(Color::White);
		
		
		if (spr_token.size() == 2 && buy == false) {
			if (IntRect(630, 150, 80, 80).contains(Mouse::getPosition(window))) {
				if (CurrentPlayer != 0) {
					spr_token[0].setColor(Color::Blue);
					numPlayer = 0;
					menuNum = 1;
				}
				else if (CurrentPlayer != 1) {
					spr_token[1].setColor(Color::Blue);
					numPlayer = 1;
					menuNum = 1;
				}
			}
		}

		if (spr_token.size() == 3 && buy == false) {
			if (IntRect(630, 150, 80, 80).contains(Mouse::getPosition(window))) {
				if (CurrentPlayer == 0) {
					spr_token[1].setColor(Color::Blue);
					numPlayer = 1;
					menuNum = 1;
				}
				else if (CurrentPlayer == 1) {
					spr_token[0].setColor(Color::Blue);
					numPlayer = 0;
					menuNum = 1;
				}
			}

			if (IntRect(630, 230, 80, 80).contains(Mouse::getPosition(window))) {
				if (CurrentPlayer == 0) {
					spr_token[2].setColor(Color::Blue);
					numPlayer = 2;
					menuNum = 2;
				}
				else if (CurrentPlayer == 1) {
					spr_token[2].setColor(Color::Blue);
					numPlayer = 2;
					menuNum = 2;
				}
				else if (CurrentPlayer == 2) {
					spr_token[1].setColor(Color::Blue);
					numPlayer = 1;
					menuNum = 2;
				}
			}
		}

		if (spr_token.size() == 4 && buy == false) {
			if (IntRect(630, 150, 80, 80).contains(Mouse::getPosition(window))) {
				if (CurrentPlayer == 0) {
					spr_token[1].setColor(Color::Blue);
					numPlayer = 1;
					menuNum = 1;
				}
				else if (CurrentPlayer == 1) {
					spr_token[0].setColor(Color::Blue);
					numPlayer = 0;
					menuNum = 1;
				}
			}

			if (IntRect(630, 230, 80, 80).contains(Mouse::getPosition(window))) {
				if (CurrentPlayer == 0) {
					spr_token[2].setColor(Color::Blue);
					numPlayer = 2;
					menuNum = 2;
				}
				else if (CurrentPlayer == 1) {
					spr_token[2].setColor(Color::Blue);
					numPlayer = 2;
					menuNum = 2;
				}
				else if (CurrentPlayer == 2) {
					spr_token[1].setColor(Color::Blue);
					numPlayer = 1;
					menuNum = 2;
				}
			}

			if (IntRect(630, 310, 80, 80).contains(Mouse::getPosition(window))) {
				if (CurrentPlayer == 0) {
					spr_token[3].setColor(Color::Blue);
					numPlayer = 3;
					menuNum = 3;
				}
				else if (CurrentPlayer == 1) {
					spr_token[3].setColor(Color::Blue);
					numPlayer = 3;
					menuNum = 3;
				}
				else if (CurrentPlayer == 2) {
					spr_token[3].setColor(Color::Blue);
					numPlayer = 3;
					menuNum = 3;
				}
				else if (CurrentPlayer == 3) {
					spr_token[2].setColor(Color::Blue);
					numPlayer = 2;
					menuNum = 3;
				}
			}
		}

		if (IntRect(315, 570, 58, 58).contains(Mouse::getPosition(window))) { 
			spr_helpInstrument[0].setColor(Color::Blue);
			menuNum = 4; 
		}
		if (IntRect(998, 570, 58, 58).contains(Mouse::getPosition(window))) {
			spr_helpInstrument[1].setColor(Color::Blue);
			menuNum = 5;
		}
		if (IntRect(1060, 570, 58, 58).contains(Mouse::getPosition(window))) {
			spr_helpInstrument[2].setColor(Color::Blue);
			menuNum = 6;
		}
		if (IntRect(630, 530, 65, 63).contains(Mouse::getPosition(window))) {
			spr_helpInstrument[3].setColor(Color::Blue);
			menuNum = 7;
		}
		if (IntRect(906, 570, 74, 33).contains(Mouse::getPosition(window))) {
			spr_helpInstrument[4].setColor(Color::Blue);
			menuNum = 8;
		}
		if (IntRect(400, 570, 74, 33).contains(Mouse::getPosition(window))) {
			spr_helpInstrument[5].setColor(Color::Blue);
			menuNum = 9;
		}
		if (Mouse::isButtonPressed(Mouse::Left)/* || menuNum == 1*/) {
			if (menuNum == 1 && buy == false) {
				pl = numPlayer;
				size1 = player[pl].getSize();
				arr1 = new int[size1];

				player[pl].sortVector();
				player[pl].setPositionMyFirm(arr1);

				for (int i = 0; i < size1; i++) {
					for (int j = 0; j < 28; j++) {
						if (arr1[i] == Firm[j]) {
							arr1[i] = j;
						}
					}
				}

				isClick = true;
			}

			if (menuNum == 2 && buy == false) {
				pl = numPlayer;
				size1 = player[pl].getSize();
				arr1 = new int[size1];

				player[pl].sortVector();
				player[pl].setPositionMyFirm(arr1);

				for (int i = 0; i < size1; i++) {
					for (int j = 0; j < 28; j++) {
						if (arr1[i] == Firm[j]) {
							arr1[i] = j;
						}
					}
				}

				isClick = true;
			}

			if (menuNum == 3 && buy == false) {
				pl = numPlayer;
				size1 = player[pl].getSize();
				arr1 = new int[size1];

				player[pl].sortVector();
				player[pl].setPositionMyFirm(arr1);

				for (int i = 0; i < size1; i++) {
					for (int j = 0; j < 28; j++) {
						if (arr1[i] == Firm[j]) {
							arr1[i] = j;
						}
					}
				}

				isClick = true;
			}

			if (menuNum == 4 && (!numChecks.empty() || moneyFirstPl != 0)) {
				for (int i = 0; i < numChecks.size(); i++) {
					one.push_back(arr[numChecks[i] - 1]);
				}
				for (int i = 0; i < numChecks1.size(); i++) {
					two.push_back(arr1[numChecks1[i] - 1]);
				}
				buy = true;
			}
			if (menuNum == 5 && (!numChecks.empty() || moneySecondPl != 0) && buy == true) {
				player[CurrentPlayer].Change(one, two, Firm, moneySecondPl, moneyFirstPl);
				player[pl].Change(two, one, Firm, moneyFirstPl, moneySecondPl);
				isMenu = false;
			}
			if (menuNum == 6 && buy == true) { buy = false; }
			if (menuNum == 7 && buy == true) { isMenu = false; }
			if (menuNum == 8 && buy == false) {
				bool flag = false;
				string sTemp;
				while (!flag) {
					if (Keyboard::isKeyPressed(Keyboard::Num0)) sTemp += '0';
					if (Keyboard::isKeyPressed(Keyboard::Num1)) sTemp += '1';
					if (Keyboard::isKeyPressed(Keyboard::Num2)) sTemp += '2';
					if (Keyboard::isKeyPressed(Keyboard::Num3)) sTemp += '3';
					if (Keyboard::isKeyPressed(Keyboard::Num4)) sTemp += '4';
					if (Keyboard::isKeyPressed(Keyboard::Num5)) sTemp += '5';
					if (Keyboard::isKeyPressed(Keyboard::Num6)) sTemp += '6';
					if (Keyboard::isKeyPressed(Keyboard::Num7)) sTemp += '7';
					if (Keyboard::isKeyPressed(Keyboard::Num8)) sTemp += '8';
					if (Keyboard::isKeyPressed(Keyboard::Num9)) sTemp += '9';
					if (Keyboard::isKeyPressed(Keyboard::Space)) flag = true;
					sleep(*new Time(milliseconds(100)));
				}

				mon1 = sTemp;
				istringstream ist(mon1);
				ist >> moneySecondPl;
				if (moneySecondPl > player[pl].getMoneyPlayer()) {
					moneySecondPl = 0;
				}

			}
			if (menuNum == 9 && buy == false) {
			bool flag = false;
			string sTemp;
			while (!flag) {
				if (Keyboard::isKeyPressed(Keyboard::Num0)) sTemp += '0';
				if (Keyboard::isKeyPressed(Keyboard::Num1)) sTemp += '1';
			    if (Keyboard::isKeyPressed(Keyboard::Num2)) sTemp += '2';
				if (Keyboard::isKeyPressed(Keyboard::Num3)) sTemp += '3';
				if (Keyboard::isKeyPressed(Keyboard::Num4)) sTemp += '4'; 
				if (Keyboard::isKeyPressed(Keyboard::Num5)) sTemp += '5';
				if (Keyboard::isKeyPressed(Keyboard::Num6)) sTemp += '6';
				if (Keyboard::isKeyPressed(Keyboard::Num7)) sTemp += '7';
				if (Keyboard::isKeyPressed(Keyboard::Num8)) sTemp += '8';
				if (Keyboard::isKeyPressed(Keyboard::Num9)) sTemp += '9';
				if (Keyboard::isKeyPressed(Keyboard::Space)) flag = true;
				sleep(*new Time(milliseconds(100)));
			}
					
			mon = sTemp;
			istringstream ist(mon);
			ist >> moneyFirstPl;
			if (moneyFirstPl > player[CurrentPlayer].getMoneyPlayer()) {
				moneyFirstPl = 0;
			}
					
			}
			
		}

		if (buy == false) {
			if (IntRect(0, 0, 100, 185).contains(Mouse::getPosition(window)) && size > 0) pos = 1;
			if (IntRect(100, 0, 100, 185).contains(Mouse::getPosition(window)) && size > 1) pos = 2;
			if (IntRect(200, 0, 100, 185).contains(Mouse::getPosition(window)) && size > 2) pos = 3;
			if (IntRect(300, 0, 100, 185).contains(Mouse::getPosition(window)) && size > 3) pos = 4;
			if (IntRect(400, 0, 100, 185).contains(Mouse::getPosition(window)) && size > 4) pos = 5;
			if (IntRect(500, 0, 100, 185).contains(Mouse::getPosition(window)) && size > 5) pos = 6;
			if (IntRect(0, 0, 100, 185).contains(Mouse::getPosition(window)) && size > 6) pos = 7;
			if (IntRect(100, 187, 100, 185).contains(Mouse::getPosition(window)) && size > 7) pos = 8;
			if (IntRect(200, 187, 100, 185).contains(Mouse::getPosition(window)) && size > 8) pos = 9;
			if (IntRect(300, 187, 100, 185).contains(Mouse::getPosition(window)) && size > 9) pos = 10;
			if (IntRect(400, 187, 100, 185).contains(Mouse::getPosition(window)) && size > 10) pos = 11;
			if (IntRect(500, 187, 100, 185).contains(Mouse::getPosition(window)) && size > 11) pos = 12;
			if (IntRect(0, 372, 100, 185).contains(Mouse::getPosition(window)) && size > 12) pos = 13;
			if (IntRect(100, 372, 100, 185).contains(Mouse::getPosition(window)) && size > 13) pos = 14;
			if (IntRect(200, 372, 100, 185).contains(Mouse::getPosition(window)) && size > 14) pos = 15;
			if (IntRect(300, 372, 100, 185).contains(Mouse::getPosition(window)) && size > 15) pos = 16;
			if (IntRect(400, 372, 100, 185).contains(Mouse::getPosition(window)) && size > 16) pos = 17;
			if (IntRect(500, 372, 100, 185).contains(Mouse::getPosition(window)) && size > 17) pos = 18;
			if (Mouse::isButtonPressed(Mouse::Left)) {
				if (pos == 1 && isChecked[0] == false) {
					spr_check[0].setPosition(0, 0);
					numChecks.push_back(pos);
					isChecked[0] = true;
				}
				else if (pos == 1) {
					for (it = numChecks.begin(); it != numChecks.end(); it++) {
						if (*it == pos) it = numChecks.erase(it);
						if (it == numChecks.end()) break;
					}
					isChecked[0] = false;
				}
				if (pos == 2 && isChecked[1] == false) { spr_check[1].setPosition(100, 0); numChecks.push_back(pos); isChecked[1] = true; }
				else if (pos == 2) {
					for (it = numChecks.begin(); it != numChecks.end(); it++) {
						if (*it == pos) it = numChecks.erase(it);
						if (it == numChecks.end()) break;
					}
					isChecked[1] = false;
				}
				if (pos == 3 && isChecked[2] == false) { spr_check[2].setPosition(200, 0); numChecks.push_back(pos); isChecked[2] = true; }
				else if (pos == 3) {
					for (it = numChecks.begin(); it != numChecks.end(); it++) {
						if (*it == pos) it = numChecks.erase(it);
						if (it == numChecks.end()) break;
					}
					isChecked[2] = false;
				}
				if (pos == 4 && isChecked[3] == false) { spr_check[3].setPosition(300, 0); numChecks.push_back(pos); isChecked[3] = true; }
				else if (pos == 4) {
					for (it = numChecks.begin(); it != numChecks.end(); it++) {
						if (*it == pos) it = numChecks.erase(it);
						if (it == numChecks.end()) break;
					}
					isChecked[3] = false;
				}
				if (pos == 5 && isChecked[4] == false) { spr_check[4].setPosition(400, 0); numChecks.push_back(pos); isChecked[4] = true; }
				else if (pos == 5) {
					for (it = numChecks.begin(); it != numChecks.end(); it++) {
						if (*it == pos) it = numChecks.erase(it);
						if (it == numChecks.end()) break;
					}
					isChecked[4] = false;
				}
				if (pos == 6 && isChecked[5] == false) { spr_check[5].setPosition(500, 0); numChecks.push_back(pos); isChecked[5] = true; }
				else if (pos == 6) {
					for (it = numChecks.begin(); it != numChecks.end(); it++) {
						if (*it == pos) it = numChecks.erase(it);
						if (it == numChecks.end()) break;
					}
					isChecked[5] = false;
				}
				if (pos == 7 && isChecked[6] == false) { spr_check[6].setPosition(0, 187); numChecks.push_back(pos); isChecked[6] = true; }
				else if (pos == 7) {
					for (it = numChecks.begin(); it != numChecks.end(); it++) {
						if (*it == pos) it = numChecks.erase(it);
						if (it == numChecks.end()) break;
					}
					isChecked[6] = false;
				}
				if (pos == 8 && isChecked[7] == false) { spr_check[7].setPosition(100, 187); numChecks.push_back(pos); isChecked[7] = true; }
				else if (pos == 8) {
					for (it = numChecks.begin(); it != numChecks.end(); it++) {
						if (*it == pos) it = numChecks.erase(it);
						if (it == numChecks.end()) break;
					}
					isChecked[7] = false;
				}
				if (pos == 9 && isChecked[8] == false) { spr_check[8].setPosition(200, 187); numChecks.push_back(pos); isChecked[8] = true; }
				else if (pos == 9) {
					for (it = numChecks.begin(); it != numChecks.end(); it++) {
						if (*it == pos) it = numChecks.erase(it);
						if (it == numChecks.end()) break;
					}
					isChecked[8] = false;
				}
				if (pos == 10 && isChecked[9] == false) { spr_check[9].setPosition(300, 187); numChecks.push_back(pos); isChecked[9] = true; }
				else if (pos == 10) {
					for (it = numChecks.begin(); it != numChecks.end(); it++) {
						if (*it == pos) it = numChecks.erase(it);
						if (it == numChecks.end()) break;
					}
					isChecked[9] = false;
				}
				if (pos == 11 && isChecked[10] == false) { spr_check[10].setPosition(400, 187); numChecks.push_back(pos); isChecked[10] = true; }
				else if (pos == 11) {
					for (it = numChecks.begin(); it != numChecks.end(); it++) {
						if (*it == pos) it = numChecks.erase(it);
						if (it == numChecks.end()) break;
					}
					isChecked[10] = false;
				}
				if (pos == 12 && isChecked[11] == false) { spr_check[11].setPosition(500, 187); numChecks.push_back(pos); isChecked[11] = true; }
				else if (pos == 12) {
					for (it = numChecks.begin(); it != numChecks.end(); it++) {
						if (*it == pos) it = numChecks.erase(it);
						if (it == numChecks.end()) break;
					}
					isChecked[11] = false;
				}
				if (pos == 13 && isChecked[12] == false) { spr_check[12].setPosition(0, 372); numChecks.push_back(pos); isChecked[12] = true; }
				else if (pos == 13) {
					for (it = numChecks.begin(); it != numChecks.end(); it++) {
						if (*it == pos) it = numChecks.erase(it);
						if (it == numChecks.end()) break;
					}
					isChecked[12] = false;
				}
				if (pos == 14 && isChecked[13] == false) { spr_check[13].setPosition(100, 372); numChecks.push_back(pos); isChecked[13] = true; }
				else if (pos == 14) {
					for (it = numChecks.begin(); it != numChecks.end(); it++) {
						if (*it == pos) it = numChecks.erase(it);
						if (it == numChecks.end()) break;
					}
					isChecked[13] = false;
				}
				if (pos == 15 && isChecked[14] == false) { spr_check[14].setPosition(200, 372); numChecks.push_back(pos); isChecked[14] = true; }
				else if (pos == 15) {
					for (it = numChecks.begin(); it != numChecks.end(); it++) {
						if (*it == pos) it = numChecks.erase(it);
						if (it == numChecks.end()) break;
					}
					isChecked[14] = false;
				}
				if (pos == 16 && isChecked[15] == false) { spr_check[15].setPosition(300, 372); numChecks.push_back(pos); isChecked[15] = true; }
				else if (pos == 16) {
					for (it = numChecks.begin(); it != numChecks.end(); it++) {
						if (*it == pos) it = numChecks.erase(it);
						if (it == numChecks.end()) break;
					}
					isChecked[15] = false;
				}
				if (pos == 17 && isChecked[16] == false) { spr_check[16].setPosition(400, 372); numChecks.push_back(pos); isChecked[16] = true; }
				else if (pos == 17) {
					for (it = numChecks.begin(); it != numChecks.end(); it++) {
						if (*it == pos) it = numChecks.erase(it);
						if (it == numChecks.end()) break;
					}
					isChecked[16] = false;
				}
				if (pos == 18 && isChecked[17] == false) { spr_check[17].setPosition(500, 372); numChecks.push_back(pos); isChecked[17] = true; }
				else if (pos == 18) {
					for (it = numChecks.begin(); it != numChecks.end(); it++) {
						if (*it == pos) it = numChecks.erase(it);
						if (it == numChecks.end()) break;
					}
					isChecked[17] = false;
				}

				sleep(*new Time(milliseconds(150)));
			}
		}

		if (buy == false) {
			if (IntRect(750, 0, 100, 185).contains(Mouse::getPosition(window)) && size1 > 0) pos1 = 1;
			if (IntRect(850, 0, 100, 185).contains(Mouse::getPosition(window)) && size1 > 1) pos1 = 2;
			if (IntRect(950, 0, 100, 185).contains(Mouse::getPosition(window)) && size1 > 2) pos1 = 3;
			if (IntRect(1050, 0, 100, 185).contains(Mouse::getPosition(window)) && size1 > 3) pos1 = 4;
			if (IntRect(1150, 0, 100, 185).contains(Mouse::getPosition(window)) && size1 > 4) pos1 = 5;
			if (IntRect(1250, 0, 100, 185).contains(Mouse::getPosition(window)) && size1 > 5) pos1 = 6;
			if (IntRect(750, 0, 100, 185).contains(Mouse::getPosition(window)) && size1 > 6) pos1 = 7;
			if (IntRect(850, 187, 100, 185).contains(Mouse::getPosition(window)) && size1 > 7) pos1 = 8;
			if (IntRect(950, 187, 100, 185).contains(Mouse::getPosition(window)) && size1 > 8) pos1 = 9;
			if (IntRect(1050, 187, 100, 185).contains(Mouse::getPosition(window)) && size1 > 9) pos1 = 10;
			if (IntRect(1150, 187, 100, 185).contains(Mouse::getPosition(window)) && size1 > 10) pos1 = 11;
			if (IntRect(1250, 187, 100, 185).contains(Mouse::getPosition(window)) && size1 > 11) pos1 = 12;
			if (IntRect(750, 372, 100, 185).contains(Mouse::getPosition(window)) && size1 > 12) pos1 = 13;
			if (IntRect(850, 372, 100, 185).contains(Mouse::getPosition(window)) && size1 > 13) pos1 = 14;
			if (IntRect(950, 372, 100, 185).contains(Mouse::getPosition(window)) && size1 > 14) pos1 = 15;
			if (IntRect(1050, 372, 100, 185).contains(Mouse::getPosition(window)) && size1 > 15) pos1 = 16;
			if (IntRect(1150, 372, 100, 185).contains(Mouse::getPosition(window)) && size1 > 16) pos1 = 17;
			if (IntRect(1250, 372, 100, 185).contains(Mouse::getPosition(window)) && size1 > 17) pos1 = 18;
			if (Mouse::isButtonPressed(Mouse::Left) && isClick == true) {
				if (pos1 == 1 && isChecked1[0] == false) {
					spr_check1[0].setPosition(750, 0);
					numChecks1.push_back(pos1);
					isChecked1[0] = true;
				}
				else if (pos1 == 1) {
					for (it = numChecks1.begin(); it != numChecks1.end(); it++) {
						if (*it == pos1) it = numChecks1.erase(it);
						if (it == numChecks1.end()) break;
					}
					isChecked1[0] = false;
				}
				if (pos1 == 2 && isChecked1[1] == false) {
					spr_check1[1].setPosition(850, 0);
					numChecks1.push_back(pos1);
					isChecked1[1] = true;
				}
				else if (pos1 == 2) {
					for (it = numChecks1.begin(); it != numChecks1.end(); it++) {
						if (*it == pos1) it = numChecks1.erase(it);
						if (it == numChecks1.end()) break;
					}
					isChecked1[1] = false;
				}
				if (pos1 == 3 && isChecked1[2] == false) { spr_check1[2].setPosition(950, 0); numChecks1.push_back(pos1); isChecked1[2] = true; }
				else if (pos1 == 21) {
					for (it = numChecks1.begin(); it != numChecks1.end(); it++) {
						if (*it == pos1) it = numChecks1.erase(it);
						if (it == numChecks1.end()) break;
					}
					isChecked[2] = false;
				}
				if (pos1 == 4 && isChecked1[3] == false) { spr_check1[3].setPosition(950, 0); numChecks1.push_back(pos1); isChecked1[3] = true; }
				else if (pos1 == 4) {
					for (it = numChecks1.begin(); it != numChecks1.end(); it++) {
						if (*it == pos1) it = numChecks1.erase(it);
						if (it == numChecks1.end()) break;
					}
					isChecked[3] = false;
				}
				if (pos1 == 5 && isChecked1[4] == false) { spr_check1[4].setPosition(950, 0); numChecks1.push_back(pos1); isChecked1[4] = true; }
				else if (pos1 == 5) {
					for (it = numChecks1.begin(); it != numChecks1.end(); it++) {
						if (*it == pos1) it = numChecks1.erase(it);
						if (it == numChecks1.end()) break;
					}
					isChecked[5] = false;
				}
				if (pos1 == 6 && isChecked1[5] == false) { spr_check1[5].setPosition(950, 0); numChecks1.push_back(pos1); isChecked1[5] = true; }
				else if (pos1 == 6) {
					for (it = numChecks1.begin(); it != numChecks1.end(); it++) {
						if (*it == pos1) it = numChecks1.erase(it);
						if (it == numChecks1.end()) break;
					}
					isChecked[5] = false;
				}
				if (pos1 == 7 && isChecked1[6] == false) { spr_check1[6].setPosition(950, 0); numChecks1.push_back(pos1); isChecked1[6] = true; }
				else if (pos1 == 7) {
					for (it = numChecks1.begin(); it != numChecks1.end(); it++) {
						if (*it == pos1) it = numChecks1.erase(it);
						if (it == numChecks1.end()) break;
					}
					isChecked[6] = false;
				}
				if (pos1 == 8 && isChecked1[7] == false) { spr_check1[7].setPosition(950, 0); numChecks1.push_back(pos1); isChecked1[7] = true; }
				else if (pos1 == 8) {
					for (it = numChecks1.begin(); it != numChecks1.end(); it++) {
						if (*it == pos1) it = numChecks1.erase(it);
						if (it == numChecks1.end()) break;
					}
					isChecked[7] = false;
				}
				if (pos1 == 9 && isChecked1[8] == false) { spr_check1[8].setPosition(950, 0); numChecks1.push_back(pos1); isChecked1[8] = true; }
				else if (pos1 == 9) {
					for (it = numChecks1.begin(); it != numChecks1.end(); it++) {
						if (*it == pos1) it = numChecks1.erase(it);
						if (it == numChecks1.end()) break;
					}
					isChecked[8] = false;
				}
				if (pos1 == 10 && isChecked1[9] == false) { spr_check1[9].setPosition(950, 0); numChecks1.push_back(pos1); isChecked1[9] = true; }
				else if (pos1 == 10) {
					for (it = numChecks1.begin(); it != numChecks1.end(); it++) {
						if (*it == pos1) it = numChecks1.erase(it);
						if (it == numChecks1.end()) break;
					}
					isChecked[9] = false;
				}
				if (pos1 == 11 && isChecked1[10] == false) { spr_check1[10].setPosition(950, 0); numChecks1.push_back(pos1); isChecked1[10] = true; }
				else if (pos1 == 11) {
					for (it = numChecks1.begin(); it != numChecks1.end(); it++) {
						if (*it == pos1) it = numChecks1.erase(it);
						if (it == numChecks1.end()) break;
					}
					isChecked[10] = false;
				}
				if (pos1 == 12 && isChecked1[11] == false) { spr_check1[11].setPosition(950, 0); numChecks1.push_back(pos1); isChecked1[11] = true; }
				else if (pos1 == 12) {
					for (it = numChecks1.begin(); it != numChecks1.end(); it++) {
						if (*it == pos1) it = numChecks1.erase(it);
						if (it == numChecks1.end()) break;
					}
					isChecked[11] = false;
				}
				if (pos1 == 13 && isChecked1[12] == false) { spr_check1[12].setPosition(950, 0); numChecks1.push_back(pos1); isChecked1[12] = true; }
				else if (pos1 == 13) {
					for (it = numChecks1.begin(); it != numChecks1.end(); it++) {
						if (*it == pos1) it = numChecks1.erase(it);
						if (it == numChecks1.end()) break;
					}
					isChecked[12] = false;
				}
				if (pos1 == 14 && isChecked1[13] == false) { spr_check1[13].setPosition(950, 0); numChecks1.push_back(pos1); isChecked1[13] = true; }
				else if (pos1 == 14) {
					for (it = numChecks1.begin(); it != numChecks1.end(); it++) {
						if (*it == pos1) it = numChecks1.erase(it);
						if (it == numChecks1.end()) break;
					}
					isChecked[13] = false;
				}
				if (pos1 == 15 && isChecked1[14] == false) { spr_check1[14].setPosition(950, 0); numChecks1.push_back(pos1); isChecked1[14] = true; }
				else if (pos1 == 15) {
					for (it = numChecks1.begin(); it != numChecks1.end(); it++) {
						if (*it == pos1) it = numChecks1.erase(it);
						if (it == numChecks1.end()) break;
					}
					isChecked[14] = false;
				}
				if (pos1 == 16 && isChecked1[15] == false) { spr_check1[15].setPosition(950, 0); numChecks1.push_back(pos1); isChecked1[15] = true; }
				else if (pos1 == 16) {
					for (it = numChecks1.begin(); it != numChecks1.end(); it++) {
						if (*it == pos1) it = numChecks1.erase(it);
						if (it == numChecks1.end()) break;
					}
					isChecked[15] = false;
				}
				if (pos1 == 17 && isChecked1[16] == false) { spr_check1[16].setPosition(950, 0); numChecks1.push_back(pos1); isChecked1[16] = true; }
				else if (pos1 == 17) {
					for (it = numChecks1.begin(); it != numChecks1.end(); it++) {
						if (*it == pos1) it = numChecks1.erase(it);
						if (it == numChecks1.end()) break;
					}
					isChecked[16] = false;
				}
				if (pos1 == 18 && isChecked1[17] == false) { spr_check1[17].setPosition(950, 0); numChecks1.push_back(pos1); isChecked1[17] = true; }
				else if (pos1 == 18) {
					for (it = numChecks1.begin(); it != numChecks1.end(); it++) {
						if (*it == pos1) it = numChecks1.erase(it);
						if (it == numChecks1.end()) break;
					}
					isChecked[17] = false;
				}
				sleep(*new Time(milliseconds(150)));
			}
		}

        window.draw(spr_Background);

		if (isClick == true) {
			for (int i = 0; i < size1; i++) {
				++count1;
				if (count1 % 6 == 0 && count1 != 0) {
					y2 += 187;
					x2 = 600;
				}
				spr_image[arr1[i]].setPosition(x2 += 100, y2);
				window.draw(spr_image[arr1[i]]);
			}
		}

		for (int i = 0; i < size; i++) {
			++count;
			if (count % 6 == 0 && count != 0) {
				y += 187;
				x = -100;
			}
			spr_image[arr[i]].setPosition(x += 100, y);
			window.draw(spr_image[arr[i]]);
		}
		
		text[4].setString(to_string(moneyFirstPl));
		text[5].setString(to_string(moneySecondPl));
		for (int i = 0; i < 6; i++) window.draw(text[i]);
		for(int i = 0; i < spr_token.size(); i++) window.draw(spr_token[i]);
		for (int i = 0; i < numChecks.size(); i++) {
			window.draw(spr_check[numChecks[i] - 1]);
		}

		for (int i = 0; i < numChecks1.size(); i++) {
			window.draw(spr_check1[numChecks1[i] - 1]);
		}
		/*for (int i = 0; i < size; i++) {
			spr_image[arr[i]].setPosition(x += 100, 0);
			window.draw(spr_image[arr[i]]);
		}*/

		for (int i = 0; i < 6; i++) {
			window.draw(spr_helpInstrument[i]);
		}

		window.display();
		sleep(*new Time(milliseconds(150)));
		//sleep(*new Time(milliseconds(1000)));
	}
}

void Menu::t(RenderWindow& window) {
	/*bool isMenu = 1;
	int menuNum = 0;
	float qw;

	while (window.isOpen() && isMenu)
	{
		qw = 0;
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		menuNum = 0;
		window.clear();
		window.draw(spr_Background);

		for (int i = 0; i < 28; i++) {
			qw++;
			spr_image[i].setPosition(qw, 0);
			window.draw(spr_image[i]);
			
		}

		window.display();
	}*/
}