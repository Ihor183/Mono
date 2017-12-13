#pragma once
class Dice {
private:
	int *points;
public:
	Dice();
	~Dice();
	void ThrowDice(int*);
};

