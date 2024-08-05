#ifndef POINT3D_H
#define POINT3D_H

class Point3D
{
private:
	double m_x;
	double m_y;
	double m_z;

public:

	// User defined default constructor
	Point3D();

	// Paramerised constructor
	Point3D(double x, double y, double z);

	// Setter Methods
	void SetX(double x);
	void SetY(double y);
	void SetZ(double z);

	// Getter Methods
	double GetX()const;
	double GetY()const;
	double GetZ()const;

	// Destructor
	~Point3D();
};

#endif  // POINT3D_H