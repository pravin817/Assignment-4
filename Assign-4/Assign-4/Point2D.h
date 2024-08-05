#ifndef POINT2D_H
#define POINT2D_H

class Point2D
{
private:
	double m_x;
	double m_y;

public:

	// User defined default constructor
	Point2D();

	Point2D(double x, double y);

	// Setter Methods
	void SetX(double x);
	void SetY(double y);

	// Getter methods
	double GetX()const;
	double GetY()const;

	// Destructor
	~Point2D();
};

#endif // POINT2D_H