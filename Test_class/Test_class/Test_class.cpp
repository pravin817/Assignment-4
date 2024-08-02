// Test_class.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Point2D.h"
#include "Util.h"

#include<iostream>

int main(){

	// Create the object of the Point2D
	Point2D p1;
	Point2D p2;
	Point2D p3;

	// Set then coordiante of the first point
	Util::GetTheCoordinatesFromUser(p1);
	Util::GetTheCoordinatesFromUser(p2);
	Util::GetTheCoordinatesFromUser(p3);

	Util::PrintAllCoordinates(p1,p2,p3);


	return 0;
}