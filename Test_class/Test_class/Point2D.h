#ifndef POINT2D_H
#define POINT2D_H

class Point2D{

private:
	double m_x;
	double m_y;

public:

	// User defined constructor
	Point2D();

	// Getter methods
	double GetX()const;
	double GetY()const;

	// Setter methods
	void SetX(double x);
	void SetY(double y);

	// Define the destructor
	~Point2D();
};




#endif  // POINT2D_H