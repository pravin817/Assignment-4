// Include the precompiled header files

#include "stdafx.h"

// Include the corresponding header files
#include "Point2D.h"


// Include the standard header files
#include <iostream>

// Defination of the all functionalities

// User defined default constructor
Point2D::Point2D(){
	std::cout<<"The user defined constructor is called"<<std::endl;
}

// The setter methods
void Point2D::SetX(double x){
	m_x = x;
}

void Point2D::SetY(double y){
	m_y = y;
}

// The getter methods
double Point2D::GetX()const{
	return m_x;
}

double Point2D::GetY()const{
	return m_y;
}


// Destructor
Point2D::~Point2D(){
	std::cout<<"The destructor for the point is called"<<std::endl;
}