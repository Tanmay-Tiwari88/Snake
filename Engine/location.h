#pragma once
class location
{
public:
	int x, y;
	void add(location const& delta)
	{
		x = x + delta.x;
		y = y + delta.y;
		
	}
	

};
