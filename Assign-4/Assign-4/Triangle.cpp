
#include "StdAfx.h"
#include "Triangle.h"

#include <iostream>

// Constructor
Triangle :: Triangle(Point2D pt1, Point2D pt2, Point2D pt3,double s1, double s2, double s3){
	p1 = pt1;
	p2 = pt2;
	p3 = pt3;

	// Sides of the triangle
	m_s1 = s1;
	m_s2 = s2;
	m_s3 = s3;
}

// Setter methods
void Triangle::SetV1(Point2D pt){
	p1 = pt;
}

void Triangle::SetV2(Point2D pt){
	p2 = pt;
}

void Triangle::SetV3(Point2D pt){
	p3 = pt;
}


// For the sides of the triangle
void Triangle::SetS1(double s){
	m_s1 = s;
}

void Triangle::SetS2(double s){
	m_s2 = s;
}

void Triangle::SetS3(double s){
	m_s3 = s;
}

// Getter Methods
Point2D Triangle::GetV1()const{
	return p1;
}

Point2D Triangle::GetV2()const{
	return p2;
}

Point2D Triangle::GetV3()const{
	return p3;
}

// Get the sides of the triangle
double Triangle::GetS1()const{
	return m_s1;
}

double Triangle::GetS2()const{
	return m_s2;
}

double Triangle::GetS3()const{
	return m_s3;
}

// Function for the getting the centroid of the triangle
Point2D Triangle::GetCentroidOfTriangle()const{
	Point2D centroid;

	double centroidX = (p1.GetX() + p2.GetX() + p3.GetX())/3.0;
	double centroidY = (p1.GetY() + p2.GetY() + p3.GetY())/3.0;

	// Set the coordinates of the centroid in the form of the point
	centroid.SetX(centroidX);
	centroid.SetY(centroidY);

	return centroid;
}

// Function for the getting the Incircle center of the Triangle
Point2D Triangle::GetIncenterOfTriangle()const{
	Point2D Incenter;
	// Incenter of the triangle by using the three vertices and the three 
	// side of the triangle ,Formula 
	// [ (a*x1 + b*x2 + c*x3)/(a+b+c), (a*y1 + b*y2 + c*y3)/(a+b+c)]

	double numeratorX = GetS1() * p1.GetX() + GetS2() * p2.GetX() + GetS3() * p3.GetX();
	double numeratorY = GetS1() * p1.GetY() + GetS2() * p2.GetY() + GetS3() * p3.GetY();

	double denominator = GetS1() + GetS2() + GetS3();

	double Ix = numeratorX / denominator;
	double Iy = numeratorY / denominator;

	Incenter.SetX(Ix);
	Incenter.SetY(Iy);

	return Incenter;
}

// Function for the getting the circumeCenter of the triangle
Point2D Triangle::GetCircumCenterOfTriangle()const{
	Point2D circumCenter;

	// The formula goes here 

	double numeratorX = (( pow(p1.GetX(),2) + pow(p1.GetY(),2)) * (p2.GetY()-p3.GetY()) + 
		( pow(p2.GetX(),2) + pow(p2.GetY(),2)) * (p3.GetY()-p1.GetY()) + 
		( pow(p3.GetX(),2) + pow(p3.GetY(),2)) * (p1.GetY()-p2.GetY()));

	double numeratorY = (( pow(p1.GetX(),2) + pow(p1.GetY(),2)) * (p3.GetX()-p2.GetX()) +
		( pow(p2.GetX(),2) + pow(p2.GetY(),2)) * (p1.GetX()-p3.GetX()) + 
		( pow(p3.GetX(),2) + pow(p3.GetY(),2)) * (p2.GetX()-p1.GetX()));

	double denominator = 2*((p1.GetX()-p2.GetX()) * (p2.GetY()-p3.GetY()) - (p2.GetX()-p3.GetX()) * (p1.GetY()-p2.GetY()));

	// Handle the exception if the denominator is zero (0)
	if (denominator == 0) {
		circumCenter.SetX(2001);
		circumCenter.SetY(2001);
		return circumCenter; // Avoid further calculations
	}

	double circumcenterX = numeratorX / denominator;
	double circumcenterY = numeratorY / denominator;

	circumCenter.SetX(circumcenterX);
	circumCenter.SetY(circumcenterY);

	return circumCenter;
}

// Function for the finding the area of the triangle 
double Triangle::AreaOfTriangle()const{
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

// Destructor
Triangle::~Triangle(){
	//std::cout<<"The destructor of the triangle class is called "<<std::endl;
}