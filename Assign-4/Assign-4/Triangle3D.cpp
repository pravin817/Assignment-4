#include "stdafx.h"

#include "Point3D.h"
#include "Triangle3D.h"

#include<iostream>

// Defination of the constructor
Triangle3D::Triangle3D(Point3D p1, Point3D p2, Point3D p3)
{
	m_p1 = p1;
	m_p2 = p2;
	m_p3 = p3;
}

// constructor that takes the 3 Vertices and 3 sides of the triangle
Triangle3D::Triangle3D(Point3D p1, Point3D p2, Point3D p3, double s1, double s2, double s3)
{
	m_p1 = p1;
	m_p2 = p2;
	m_p3 = p3;
	m_s1 = s1;
	m_s2 = s2;
	m_s3 = s3;
}

// Setter Methods
void Triangle3D::SetV1(Point3D p1)
{
	m_p1 = p1;
}

void Triangle3D::SetV2(Point3D p2)
{
	m_p2 = p2;
}

void Triangle3D::SetV3(Point3D p3)
{
	m_p3 = p3;
}

// sides of the triangle
void Triangle3D::SetS1(double s1)
{
	m_s1 = s1;
}

void Triangle3D::SetS2(double s2)
{
	m_s2 = s2;
}

void Triangle3D::SetS3(double s3)
{
	m_s3 = s3;
}

// Getter Methods
Point3D Triangle3D::GetV1()const
{
	return m_p1;
}

Point3D Triangle3D::GetV2()const
{
	return m_p2;
}

Point3D Triangle3D::GetV3()const
{
	return m_p3;
}

double Triangle3D::GetS1()const
{
	return m_s1;
}

double Triangle3D::GetS2()const
{
	return m_s2;
}

double Triangle3D::GetS3()const
{
	return m_s3;
}


// Function for the getting the centroid of the triangle
Point3D Triangle3D::GetCentroidOfTriangle()const{
	Point3D centroid;

	double centroidX = (m_p1.GetX() + m_p2.GetX() + m_p3.GetX())/3.0;
	double centroidY = (m_p1.GetY() + m_p2.GetY() + m_p3.GetY())/3.0;
	double centroidZ = (m_p1.GetZ() + m_p2.GetZ() + m_p3.GetZ())/3.0;

	// Set the coordinates of the centroid in the form of the point
	centroid.SetX(centroidX);
	centroid.SetY(centroidY);
	centroid.SetZ(centroidZ);

	return centroid;
}

// Function for the getting the Incircle center of the Triangle
Point3D Triangle3D::GetIncenterOfTriangle()const{
	Point3D Incenter;
	// Incenter of the triangle by using the three vertices and the three 
	// side of the triangle ,Formula 
	// [ (a*x1 + b*x2 + c*x3)/(a+b+c), (a*y1 + b*y2 + c*y3)/(a+b+c)]

	double numeratorX = GetS1() * m_p1.GetX() + GetS2() * m_p2.GetX() + GetS3() * m_p3.GetX();
	double numeratorY = GetS1() * m_p1.GetY() + GetS2() * m_p2.GetY() + GetS3() * m_p3.GetY();
	double numeratorZ = GetS1() * m_p1.GetZ() + GetS2() * m_p2.GetZ() + GetS3() * m_p3.GetZ();

	double denominator = GetS1() + GetS2() + GetS3();

	double Ix = numeratorX / denominator;
	double Iy = numeratorY / denominator;
	double Iz = numeratorZ / denominator;

	Incenter.SetX(Ix);
	Incenter.SetY(Iy);
	Incenter.SetY(Iz);

	return Incenter;
}

// Function for the getting the circumeCenter of the triangle
Point3D Triangle3D::GetCircumCenterOfTriangle()const{
	Point3D circumCenter;

	// The formula goes here 

	double numeratorX = (
							( pow(m_p1.GetX(),2) 
							+ pow(m_p1.GetY(),2) 
							+ pow(m_p1.GetZ(),2)) * (m_p2.GetY()-m_p3.GetY()) 
							+ ( pow(m_p2.GetX(),2) 
							+ pow(m_p2.GetY(),2) 
							+ pow(m_p2.GetZ(),2)) * (m_p3.GetY()-m_p1.GetY()) 
							+ ( pow(m_p3.GetX(),2) 
							+ pow(m_p3.GetY(),2) 
							+ pow(m_p3.GetZ(),2)) * (m_p1.GetY()-m_p2.GetY())
						);

	double numeratorY = (
							( pow(m_p1.GetX(),2) 
							+ pow(m_p1.GetY(),2) 
							+ pow(m_p1.GetZ(),2)) * (m_p2.GetZ()-m_p3.GetZ()) 
							+ ( pow(m_p2.GetX(),2) 
							+ pow(m_p2.GetY(),2) 
							+ pow(m_p2.GetZ(),2)) * (m_p3.GetZ()-m_p1.GetZ()) 
							+ ( pow(m_p3.GetX(),2) 
							+ pow(m_p3.GetY(),2) 
							+ pow(m_p3.GetZ(),2)) * (m_p1.GetZ()-m_p2.GetZ()) 
						);

	double numeratorZ = (
							( pow(m_p1.GetX(),2) 
							+ pow(m_p1.GetY(),2) 
							+ pow(m_p1.GetZ(),2)) * (m_p2.GetX() - m_p3.GetX()) 
							+ ( pow(m_p2.GetX(),2) 
							+ pow(m_p2.GetY(),2) 
							+ pow(m_p3.GetZ(),2)) * (m_p3.GetX()- m_p1.GetX())
							+ ( pow(m_p3.GetX(),2) 
							+ pow(m_p3.GetY() ,2) 
							+ pow(m_p3.GetZ(),2)) * (m_p1.GetX() - m_p2.GetX()) 
						);

	double denominator = 2*((m_p1.GetX()-m_p2.GetX()) 
							* (m_p2.GetY()-m_p3.GetY()) 
							- (m_p2.GetX()-m_p3.GetX()) 
							* (m_p1.GetY()-m_p2.GetY()));

	// Handle the exception if the denominator is zero (0)
	if (denominator == 0) {
		circumCenter.SetX(2001);
		circumCenter.SetY(2001);
		circumCenter.SetZ(2001);
		return circumCenter; // Avoid further calculations
	}

	double circumcenterX = numeratorX / denominator;
	double circumcenterY = numeratorY / denominator;
	double circumcenterZ = numeratorZ / denominator;

	circumCenter.SetX(circumcenterX);
	circumCenter.SetY(circumcenterY);
	circumCenter.SetZ(circumcenterZ);

	return circumCenter;
}

// Function for the finding the area of the triangle 
double Triangle3D::AreaOfTriangle()const{
	double area = 0;

	double a = m_s1;
	double b = m_s2;
	double c = m_s3;

	// Area of the triangle by using the Heros formula
	double s = (a+b+c)/2.0;

	double term = s*(s-a)*(s-b)*(s-c);

	area = sqrt(term);

	return area;
}

// Defination of the destructor
Triangle3D::~Triangle3D()
{
	//std::cout<<"The Triangle3D destructor called"<<std::endl;
}

