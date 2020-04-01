#include "board.h"


board::board(Graphics & gfx)
	:
	gfx(gfx )
{
}

void board::drawcell(location & l,Color c)
{
	gfx.DrawRectDim(dimenssion * l.x, dimenssion * l.y, dimenssion, dimenssion, c); 
	
}

int board::GetHieght()
{
	return Hieght;
}

int board::GetWidth()
{
	return Width;
}

void board::drawboard()
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < Width*dimenssion; j++)
			gfx.PutPixel(j, i, 255, 0, 0);
	for (int i = Hieght*dimenssion; i < Hieght * dimenssion + 5; i++)
		for (int j = 0; j <=Width*dimenssion; j++)
			gfx.PutPixel(j, i, 255, 0, 0);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < Hieght*dimenssion; j++)
			gfx.PutPixel(i, j, 255, 0, 0);
	for (int i = Width * dimenssion; i < Width * dimenssion + 5; i++)
		for (int j = 0; j <=Hieght*dimenssion; j++)
			gfx.PutPixel(i, j, 255, 0, 0);

}

bool board::insideboard(location & l)
{
	if (l.x < 0 || l.x >= Hieght || l.y < 0 || l.y >= Width)
		return false;
	return true;
}



