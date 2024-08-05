#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point2D.h"

class Triangle
{
private:
	Point2D p1;
	Point2D p2;
	Point2D p3;

	// Sides of the triangle
	double m_s1;
	double m_s2;
	double m_s3;

public:

	// Constructor for the creating the triangle 
	Triangle(Point2D p1, Point2D p2, Point2D p3, double s1, double s2, double s3);

	// Setter Methods 
	void SetV1(Point2D pt);
	void SetV2(Point2D pt);
	void SetV3(Point2D pt);

	void SetS1(double s);
	void SetS2(double s);
	void SetS3(double s);

	// Getter methods
	Point2D GetV1()const;
	Point2D GetV2()const;
	Point2D GetV3()const;

	double GetS1()const;
	double GetS2()const;
	double GetS3()const;

	// 1. Function for finding the Centroid of the triangle
	Point2D GetCentroidOfTriangle()const; 

	// 2. Function for the finding the Incirlecenter of the triangle
	Point2D GetIncenterOfTriangle()const;

	// 3. Function for the finding the CircumeCenter of the triangle
	Point2D GetCircumCenterOfTriangle()const;

	// 4. Function for the finding the area of the triangle 
	double AreaOfTriangle()const;

	// Destructor
	~Triangle();
};

#endif // TRIANGLE_H
