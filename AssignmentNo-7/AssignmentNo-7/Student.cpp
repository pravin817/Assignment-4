#include "stdafx.h"

#include "Student.h"
#include "Calculations.h"
#include "Util.h"

#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <sstream>

// Constructor
Student::Student(
	int studentId,
	int rollNo, 
	std::string name, 
	int marathi,
	int english,
	int physics,
	int chemistry,
	int biology,
	int mathematics,
	bool isActive, 
	float percentage)
{
	m_studentID = studentId;
	m_rollNo = rollNo;
	m_nameOfStudent = name;

	// Subject and marks
	m_subjectAndMarks["MARATHI"] = marathi;
	m_subjectAndMarks["ENGLISH"] = english;
	m_subjectAndMarks["PHYSICS"] = physics;
	m_subjectAndMarks["CHEMISTRY"] = chemistry;
	m_subjectAndMarks["BIOLOGY"] = biology;
	m_subjectAndMarks["MATHEMATICS"] = mathematics;

	// Set the status
	m_isActive = isActive;
	m_percentage = percentage;

	std::cout<<"The student constructor called"<<std::endl;
}

//-----------------------------------------------------------------------------
// All setter methods for student goes here
//-----------------------------------------------------------------------------

void Student::SetNameOfStudent(std::string const &studentName)
{
	this->m_nameOfStudent = studentName;
}

void Student::SetMarksOfMarathi(int const& marksOfMarathi)
{
	this->m_subjectAndMarks["MARATHI"] = marksOfMarathi;
}

void Student::SetMarksOfEnglish(int const& marksOfEnglish)
{
	this->m_subjectAndMarks["ENGLISH"] = marksOfEnglish;
}

void Student::SetMarksOfPhysics(int const& marksOfPhysics)
{
	this->m_subjectAndMarks["PHYSICS"] = marksOfPhysics;
}

void Student::SetMarksOfChemistry(int const& marksOfChemistry)
{
	this->m_subjectAndMarks["CHEMISTRY"] = marksOfChemistry;
}

void Student::SetMarksOfBiology(int const& marksOfBiology)
{
	this->m_subjectAndMarks["BIOLOGY"] = marksOfBiology;
}

void Student::SetMarksOfMathematics(int const& marksOfMathematics)
{
	this->m_subjectAndMarks["MATHEMATICS"] = marksOfMathematics;
}

void Student::SetPercentageOfStudent(float const& percentage)
{
	this->m_percentage = percentage;
}

void Student::SetStatusOfStudent(bool const &status)
{
	this->m_isActive = status;
}

//-----------------------------------------------------------------------------
// All getter methods for student goes here
//-----------------------------------------------------------------------------

int Student::GetStudentId()const
{
	return this->m_studentID;
}

int Student::GetStudentRollNo()const
{
	return this->m_rollNo;
}

std::string Student::GetStudentName()const
{
	return this->m_nameOfStudent;
}

int Student::GetMarksOfMarathi()const
{
	return this->m_subjectAndMarks.at("MARATHI");
}

int Student::GetMarksOfEnglish()const
{
	return m_subjectAndMarks.at("ENGLISH");
}

int Student::GetMarksOfPhysics()const
{
	return this->m_subjectAndMarks.at("PHYSICS");
}

int Student::GetMarksOfChemistry()const
{
	return this->m_subjectAndMarks.at("CHEMISTRY");
}

int Student::GetMarksOfBiology()const
{
	return this->m_subjectAndMarks.at("BIOLOGY");
}

int Student::GetMarksOfMathematics()const
{
	return this->m_subjectAndMarks.at("MATHEMATICS");
}

bool Student::GetStudentStatus()const
{
	return this->m_isActive;
}

float Student::GetPercentageOfStudent()const
{
	return this->m_percentage;
}


// Operator Overloading


//-----------------------------------------------------------------------------
// Function for printing the single student details in row format.
//-----------------------------------------------------------------------------

std::ostream& operator<<(std::ostream &output, Student const &studentObj)
{
	// Print student ID and roll number and name of student
	output << "| " << std::setw(11) <<std::fixed
		<< std::fixed << std::setprecision(0) << static_cast<double>(studentObj.m_studentID) 
		<< " | " << std::setw(11) 
		<< Util::alignTextAtCenterOfTable(
		Util::FloatToString(studentObj.m_rollNo), 11)
		<< " | " << std::setw(23) 
		<< Util::alignTextAtCenterOfTable(studentObj.m_nameOfStudent, 23)
		<< " | ";

	// Print the marks obtained by student in each subject
	auto it = studentObj.m_subjectAndMarks.begin();
	while(it != studentObj.m_subjectAndMarks.end())
	{		
		output<< std::setw(13) 
			  << Util::alignTextAtCenterOfTable( it->second == -1 ? "NA" : 
			  Util::FloatToString(it->second), 13); 
		output<< "|";
		++it;
	}

	// Calculate and print total marks, percentage, and grade
	int totalMarks = Calculation::CalculateTotalMarks(&studentObj);
	char gradeOfStudent = Calculation::CalculateGrade(studentObj.m_percentage);

	output << std::setw(11) << Util::alignTextAtCenterOfTable(!Util::AreMarksAlreadyAdded(&studentObj) ? "NA" :Util::FloatToString(totalMarks), 11)
		<< " | " << std::setw(11) << Util::alignTextAtCenterOfTable(studentObj.m_percentage < 0 ? "NA": Util::FloatToString(studentObj.m_percentage), 11)
		<< " | " << std::setw(11) << Util::alignTextAtCenterOfTable(std::string(1, gradeOfStudent), 11)
		<< " | " << std::setw(11) << Util::alignTextAtCenterOfTable(Util::boolToString(studentObj.m_isActive), 11)
		<< " | ";

	return output;
}

// The destructor
Student::~Student()
{
	std::cout<<"The student destructor called"<<std::endl;
}