#include "fruit.h"


fruit::fruit(location& l)
{
	this->l = l;
}

void fruit::shiftfruit(location & l)
{
	this->l = l;
}

void fruit::Drawfruit(board&  b)
{
	b.drawcell(l, fruitcolor);
}

location fruit::getfrloc()
{
	return l;
}
