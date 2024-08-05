#ifndef TRIANGLE3D_H
#define TRIANGLE3D_H

#include "Point3D.h"

class Triangle3D
{
private:
	Point3D m_p1;
	Point3D m_p2;
	Point3D m_p3;

	// sides of the triangle
	double m_s1;
	double m_s2;
	double m_s3;

public:

	// Triangle 3D constructor called
	Triangle3D(Point3D p1, Point3D p2, Point3D p3);

	// 3D Triangle that takes the vertices as well as sides of the triangle
	Triangle3D(Point3D p1, Point3D p2, Point3D p3, double s1, double s2, double s3);
	
	// Setter Methods
	void SetV1(Point3D pt);
	void SetV2(Point3D pt);
	void SetV3(Point3D pt);

	void SetS1(double s);
	void SetS2(double s);
	void SetS3(double s);

	// Getter methods
	Point3D GetV1()const;
	Point3D GetV2()const;
	Point3D GetV3()const;

	double GetS1()const;
	double GetS2()const;
	double GetS3()const;

	// 1. Function for finding the Centroid of the triangle
	Point3D GetCentroidOfTriangle()const;

	// 2. Function for the finding the Incirlecenter of the triangle
	Point3D GetIncenterOfTriangle()const;

	// 3. Function for the finding the CircumeCenter of the triangle
	Point3D GetCircumCenterOfTriangle()const;

	// 4. Function for the finding the area of the triangle 
	double AreaOfTriangle()const;

	// Triangle 3D Destructor called
	~Triangle3D();
};

#endif  // TRIANGLE3D_H