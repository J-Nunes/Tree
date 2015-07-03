#ifndef __Rectangle_H__
#define __Rectangle_H__


template<class TYPE>
class Rectangle
{
public:

	TYPE			x;
	TYPE			y;
	TYPE			w;
	TYPE			h;

public:
	// Constructors
	Rectangle(const TYPE& ox, const TYPE& oy, const TYPE& ow, const TYPE& oh)
	{
		x = ox;
		y = oy;
		w = ow;
		h = oh;
	}

	Rectangle(const Rectangle& r)
	{
		x = r.x;
		y = r.y;
		w = r.w;
		h = r.h;
	}

	// Destructor
	~Rectangle()
	{
	}

	TYPE getArea()const
	{
		return w * h;
	}
	
	bool intersects(const Rectangle& rect)const
	{
		return (rect.x < x + w &&
				rect.x + rect.w > x &&
				rect.y < y + h &&
				rect.h + rect.y > y);
	}
};
#endif