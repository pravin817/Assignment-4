#include "StdAfx.h"
#include "Point3D.h"
#include <iostream>


Point3D::Point3D()
{
	//std::cout<<"The user defined default constructor is called"<<std::endl;
}

// Constructor
Point3D::Point3D(double x, double y, double z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}

// Setter Methods
void Point3D::SetX(double x)
{
	m_x = x;
}

void Point3D::SetY(double y)
{
	m_y = y;
}

void Point3D::SetZ(double z)
{
	m_z = z;
}

// Getter Methods


double Point3D::GetX()const
{
	return m_x;
}

double Point3D::GetY()const
{
	return m_y;
}

double Point3D::GetZ()const
{
	return m_z;
}

// Destructor
Point3D::~Point3D()
{
	//std::cout<<"The 3D destructor called"<<std::endl;
}