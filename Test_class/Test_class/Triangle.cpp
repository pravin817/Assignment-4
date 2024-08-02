// Precomipled header files
#include "stdafx.h"
// Correspondng header files
#include "Triangle.h"
#include "Point2D.h"

// standard Header files
#include <iostream>


// Define the function defined in the Triangle class

// Defination of the constuctor

Triangle::Triangle(Point2D pt1, Point2D pt2, Point2D pt3){
	p1 = pt1;
	p2 = pt2;
	p3 = pt3;
}

// Getter Methods

Point2D Triangle ::GetV1()const{
	return p1;
}

Point2D Triangle ::GetV2()const{
	return p2;
}

Point2D Triangle ::GetV3()const{
	return p3;
}

// For the sides of the tringle
double Triangle::GetS2()const{
	return m_s1;
}

double Triangle::GetS1()const{
	return m_s2;
}

double Triangle::GetS3()const{
	return m_s3;
}

// Setter Methods
void Triangle::SetV1(Point2D pt){
	p1 = pt;
}

void Triangle::SetV2(Point2D pt){
	p2 = pt;
}

void Triangle::SetV3(Point2D pt){
	p3 = pt;
}

void Triangle::SetS1(double s){
	m_s1 = s;
}

void Triangle::SetS2(double s){
	m_s2 = s;
}

void Triangle::SetS3(double s){
	m_s3 = s;
}







// Destructor for the triangle class
Triangle::~Triangle(){
	std::cout<<"The destructor for the triangle class is called"<<std::endl;
}