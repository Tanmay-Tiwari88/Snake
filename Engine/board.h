#pragma once
#include "location.h"
#include"Graphics.h"
class board
{
private:
	static constexpr int dimenssion = 10;
	int  Hieght = 30;
	int  Width = 30;
	Graphics& gfx;
public:
	board(Graphics& gfx);
	void drawcell(location& l, Color c);
	int GetHieght();
	int GetWidth();
	void drawboard();
	bool insideboard(location& l);


};