#include "StdAfx.h"
#include "Point2D.h"
#include <iostream>

// User defined constructor
Point2D::Point2D()
{
	//std::cout<<"The point constructor called"<<std::endl;
}

Point2D::Point2D(double x, double y)
{
	m_x = x;
	m_y = y;
}

// The setter methods
void Point2D::SetX(double x)
{
	m_x = x;
}

void Point2D::SetY(double x)
{
	m_y = x;
}

// Getter method
double Point2D::GetX()const{
	return m_x;
}

double Point2D::GetY()const
{
	return m_y;
}

// The destructor called
Point2D::~Point2D(){
	//std::cout<<"The point destructor called"<<std::endl;
}