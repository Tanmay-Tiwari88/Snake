/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	Board(gfx),
	rng(std::random_device()()),
	fx(0, 10),
	fy(0, 10),
	fr(frlc),
	sn(start)
{

}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{	

	if (!gameover)
	{
		snakeinput();
		snakemovecount++;
		if (snakemovecount >= snakemove)
		{
			eatfruit();
			snakemovecount = 0;
			location hl = sn.gethead();
			hl.add(delta);
			if (!Board.insideboard(hl))
				gameover = true;
			if (sn.snakedeath())
				gameover = true;
			if (wnd.kbd.KeyIsPressed(VK_SHIFT))
				sn.grow();

			sn.moveby(delta);
			
		}
	}
	
	
	
	
}

void Game::snakeinput()
{
	if (wnd.kbd.KeyIsPressed(VK_UP))
		 delta = { 0,-1 };
	
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
		delta = { 0,1 };
	
	
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		 delta = { 1,0 };
		
	
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
		 delta = { -1,0 };
	

	
	
}

void Game::eatfruit()
{
	location sl = sn.gethead();
	location frx = fr.getfrloc();
	if (sl.x==frx.x && sl.y==frx.y)
	{
		frlc = { fx(rng),fy(rng) };
		fr.shiftfruit(frlc);
		sn.grow();
		snakemove--;
	}

}

void Game::ComposeFrame()
{
	if (!gameover)
	{
		sn.drawsnake(Board);
		fr.Drawfruit(Board);
		
	}
	else
		s.DrawGameOver(125, 125, gfx);
	Board.drawboard();
	
}
