#pragma once
#include "board.h"
#include "location.h"
#include"fruit.h"

class snake {
private:
	class segment
	{
	private:
		location l;
		Color c;
	public:
		void inithead(location& l);
		void initsegment();
		void follow(segment &segnext);
		void movebydelta(location delta);
		bool comp(segment seg1, segment seg2);
		void drawseg(board& b);
		location getheadl();
		
		
	};
private:
	static constexpr int segments = 100;
	segment segs[segments];
	int nsegs = 1;
	static constexpr Color headcolor = Colors::Green;
	static constexpr Color bodycolor = Colors::Yellow;

public:
	snake(location& loc);
	void drawsnake(board &b);
	void grow();
	void moveby(location& delta);
	location gethead();
	bool snakedeath();
	
	


};
