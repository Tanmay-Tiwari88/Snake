#include "snake.h"

snake::snake(location& loc)
{
	segs[0].inithead(loc);
}


void snake::drawsnake(board & b)
{
	for (int i = 0; i < nsegs; i++)
		segs[i].drawseg(b);

	
}

void snake::grow()
{
	if (nsegs <= segments)
	{
		segs[nsegs++].initsegment();
	}
}

void snake::moveby(location& delta)
{
	for (int i = nsegs - 1; i > 0; i--)
		segs[i].follow(segs[i - 1]);
	segs[0].movebydelta(delta);
}

location snake::gethead()
{
	return segs[0].getheadl();
}


void snake::segment::inithead(location & l)
{
	this->l = l;
	c = headcolor;

}

void snake::segment::initsegment()
{
	c = bodycolor;
}

void snake::segment::follow(segment & segnext)
{
	l = segnext.l;
}

void snake::segment::movebydelta(location delta)
{
	l.add(delta);

}

bool snake::segment::comp(segment seg1, segment seg2)
{
	if(seg1.l.x==seg2.l.x && seg1.l.y == seg2.l.y)
		return true;
	return false;
}

void snake::segment::drawseg(board & b)
{
	b.drawcell(l, c);
}

location snake::segment::getheadl()
{
	return l;
}

bool snake::snakedeath()
{
	for(int i=1; i < nsegs ; i++)
		if(segs[0].comp(segs[0],segs[i]))
			return true;
	return false;
}
