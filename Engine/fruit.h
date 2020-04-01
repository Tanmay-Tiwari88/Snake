#pragma once
#include"Graphics.h"
#include "location.h"
#include"board.h"
class fruit
{
private:
	location l;
	static constexpr Color fruitcolor = Colors::Red;
public:
	fruit(location &l);
	void shiftfruit(location &l);
	void Drawfruit(board&  b);
	location getfrloc();
	
};

