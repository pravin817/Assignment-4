#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "stdafx.h"
#include "Point2D.h"

class Triangle{

private:
	// Coordinates of the point
	Point2D p1;
	Point2D p2;
	Point2D p3;

	// Sides of the triangle
	double m_s1;
	double m_s2;
	double m_s3;

public:

	// Constructor
	Triangle(Point2D, Point2D, Point2D);

	// Setter Methods
	// For the points
	void SetV1(Point2D pt);
	void SetV2(Point2D pt);
	void SetV3(Point2D pt);

	// For the sides
	void SetS1(double s);
	void SetS2(double s);
	void SetS3(double s);
	
	// Getter methods
	// For the points
	Point2D GetV1()const;
	Point2D GetV2()const;
	Point2D GetV3()const;

	// for the sides
	double GetS1()const;
	double GetS2()const;
	double GetS3()const;

	// Destructor
	~Triangle();
};




#endif // TRIANGLE_H