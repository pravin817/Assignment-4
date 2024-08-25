#include "stdafx.h"
#include "Util.h"

#include "StudentManager.h"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

//-----------------------------------------------------------------------------
// Function for reading the data from a file (EXTRA FUNCTION FOR TESTING FILE)
//-----------------------------------------------------------------------------
//void Util::ReadFromFile(std::string const &fileName, char const &delimeter, 
//	int &rollNo, std::string &studentName, int &marathi, 
//	int &english, int &physics, int &chemistry, 
//	int &biology, int &mathematics)
//{
//	std::ifstream fin(fileName);
//
//	// Check if the file is open successfully or not.
//	if(fin.is_open())
//	{
//		std::string line;
//
//        while (std::getline(fin, line))
//        {
//            std::stringstream ss(line);
//            ss >> rollNo >> delimeter;
//            std::getline(ss, studentName, delimeter);
//            ss >> marathi >> delimeter;
//            ss >> english >> delimeter;
//            ss >> physics >> delimeter;
//            ss >> chemistry >> delimeter;
//            ss >> biology >> delimeter;
//            ss >> mathematics;
//            
//            // Process the read data here or store in appropriate structures
//            std::cout << "Read line: " << line << std::endl;
//        }
//
//		// Close the file
//		fin.close();
//	}
//	else
//	{
//		std::cout<<"Warning : The file not open for the reading operation."
//			<<std::endl;
//	}
//}


//-----------------------------------------------------------------------------
// Function for writing student data to a file
//-----------------------------------------------------------------------------
void Util::WriteToFile(std::string const &fileName,int studentId,
	int rollNo,
	std::string const &studentName,
	int marksOfMarathi,
	int marksOfEnglish,
	int marksOfPhysics,
	int marksOfChemistry,
	int marksOfBiology,
	int marksOfMathematics,
	bool status)
{

	std::ofstream fout(fileName, std::ios_base::app);

	// Check if the file open successfully.
	if(fout.is_open())
	{
		std::cout << "File open successfully for the write operation"
			      << std::endl;

		// Now write to the file
		fout << studentId << '\t'
             << rollNo << '\t'
             << studentName << '\t'
             << marksOfMarathi << '\t'
             << marksOfEnglish << '\t'
             << marksOfPhysics << '\t'
             << marksOfChemistry << '\t'
             << marksOfBiology << '\t'
             << marksOfMathematics << '\t'
             << (status ? 1 : 0) << std::endl;

        std::cout << "Student data written to file successfully." << std::endl;

		// close the file 
		fout.close();
	}
	else
	{
		std::cout << "Warning: File could not be opened for writing." 
				  << std::endl;
	}
}


//-----------------------------------------------------------------------------
// Function for writing all students data to a file
//-----------------------------------------------------------------------------
void Util::WriteToFile(StudentManager &studentManager)
{
	std::string fileName = studentManager.GetFileName();

	std::ofstream fout(fileName);

	// Check if the file is open or not
	if(fout.is_open())
	{
		std::cout<<"The File open for the updating the file data."<<std::endl;

		// Write the data of each and every student in file
		int studentCount = studentManager.GetStudentCount();

		for(int iIndex = 1; iIndex <= studentCount; ++iIndex)
		{
			// Get the current student
			Student *currentStudent = studentManager.GetStudentByRollNo(iIndex);

			// Write the current student data to the file
			fout<< currentStudent->GetStudentId() << '\t'
				<< currentStudent->GetStudentRollNo() << '\t'
				<< currentStudent->GetStudentName() << '\t'
				<< currentStudent->GetMarksOfMarathi() << '\t'
				<< currentStudent->GetMarksOfEnglish() << '\t'
				<< currentStudent->GetMarksOfPhysics() << '\t'
				<< currentStudent->GetMarksOfChemistry() << '\t'
				<< currentStudent->GetMarksOfBiology() << '\t'
				<< currentStudent->GetMarksOfMathematics() << '\t'
				<< (currentStudent->GetStudentStatus() ? 1 : 0) << std::endl;
		}
		std::cout << " Message : All student data updated successfully."
			      << std::endl;
	}
	else
	{
		std::cout << "Warning: File could not be opened for writing." 
			      << std::endl;
	}
}


//-----------------------------------------------------------------------------
// Function for processing a line of student data
//-----------------------------------------------------------------------------
void Util::GetOneStudentDataFromLine(
	std::string const &oneStudentDataForProcessing, 
	int &studentId,
	int &rollNo,
	std::string &studentName,
	int &marathi,
	int &english,
	int &physics,
	int &chemistry,
	int &biology,
	int &mathematics,
	bool &isActive
	)
{
	// Create the string steam from the line
	std::stringstream ss(oneStudentDataForProcessing);

	ss>>studentId;
	ss.ignore(1); // Skip tab

	ss>>rollNo;
	ss.ignore(1);

	std::getline(ss,studentName,'\t');

	ss>>marathi;
	ss.ignore(1);

	ss>>english;
	ss.ignore(1);

	ss>>physics;
	ss.ignore(1);

	ss>>chemistry;
	ss.ignore(1);

	ss>>biology;
	ss.ignore(1);

	ss>>mathematics;
	ss.ignore(1);

	ss>>isActive;
	ss.ignore(1);
}


// Automatic Operations

//-----------------------------------------------------------------------------
// Function for creating a unique student ID
//-----------------------------------------------------------------------------
int Util::CreateUniqueStudnetID(int standard,int studentRollNo)
{
	int currentYear = 2024;
	int studentStrength = 1000;
	int studentId = ( ( currentYear * 100 ) + standard )
					* studentStrength + studentRollNo;
	return studentId;
}


//-----------------------------------------------------------------------------
// Function for creating a roll number
//-----------------------------------------------------------------------------
int Util::CreateRollNo(StudentManager const &studentManagerObj)
{
	//static int rollNo = 0;

	//// Get the number of the records in the file
	//int studentCount = studentManagerObj.GetStudentCount();


	///***********************************************************************

	//CHECK THE BELOW CODE

	//************************************************************************/
	//// If we get stduentCount = 0 indicating that new school started no 
	//// student haven't taken the admission in this college
	////if(studentCount >= 0 && rollNo <= 0){
	//	rollNo = studentCount;
	////}

	//// Update the value by one because we are going to call this function when 
	//// the new student is added to the list of student
	//++rollNo;
	//return rollNo;

	int rollNo = studentManagerObj.GetStudentCount();
    ++rollNo;
    return rollNo;
}


//-----------------------------------------------------------------------------
// Function for converting float to string
//-----------------------------------------------------------------------------
std::string Util::FloatToString(float value)
{
	std::ostringstream oss;
	oss << value;
	return oss.str();
}


//-----------------------------------------------------------------------------
// Function for converting bool to string
//-----------------------------------------------------------------------------
std::string Util::boolToString (bool value)
{
	return value ? "Active" : "Inactive";
}


//-----------------------------------------------------------------------------
// Function for validating marks entered by the user
//-----------------------------------------------------------------------------
void Util::ValidateMarks(int &marksOfSubject)
{
	int marks = -1;
	std::cin>>marks;

	while(true)
	{
		if(marks >= 0 && marks <= 100)
		{
			marksOfSubject = marks;
			break;
		}
		else
		{
			std::cout<<"Please enter the marks in range (0, 100) : ";
			std::cin>>marks;
		}
	}	
}


//-----------------------------------------------------------------------------
// Function for checking if marks are already added for a student
//-----------------------------------------------------------------------------
bool Util::AreMarksAlreadyAdded(Student const *currentStudent)
{
	// Check if the marks already added
	if(currentStudent->GetMarksOfMarathi() > 0 
		|| currentStudent->GetMarksOfEnglish() > 0 
		|| currentStudent->GetMarksOfPhysics() > 0
		|| currentStudent->GetMarksOfChemistry() > 0
		|| currentStudent->GetMarksOfBiology() > 0
		|| currentStudent->GetMarksOfMathematics() > 0)
	{
		return true;
	}
	return false;
}


//-----------------------------------------------------------------------------
// Function for printing the table header
//-----------------------------------------------------------------------------
void Util::PrintTableHeader()
{
	std::cout << "+-------------+-------------+-------------------------+--------------+-------------+-------------+-------------+-------------+-------------+------------+-------------+-------------+-------------+" << std::endl;
	std::cout << "| Student ID  |   Roll No   |           Name          |   Marathi    |  English    |   Physics   |  Chemistry  |    Biology  | Mathematics |Total Marks |  Percentage |    Grade    |    Status   |" << std::endl;
	std::cout << "+-------------+-------------+-------------------------+--------------+-------------+-------------+-------------+-------------+-------------+------------+-------------+-------------+-------------+" << std::endl;

}

//-----------------------------------------------------------------------------
// Function for printing the table footer
//-----------------------------------------------------------------------------
void Util::PrintTableFooter()
{
	std::cout << "+-------------+-------------+-------------------------+--------------+-------------+-------------+-------------+-------------+-------------+------------+-------------+-------------+-------------+" << std::endl;
}


//-----------------------------------------------------------------------------
// Function for aligning text at the center of a table column
//-----------------------------------------------------------------------------
std::string Util::alignTextAtCenterOfTable(const std::string& text, 
	int const &width)
{
	int padding = width - text.size();
	if (padding <= 0) 
		return text; // No need to pad if the text is longer than width

	int padLeft = padding / 2;
	int padRight = padding - padLeft;

	return std::string(padLeft, ' ') + text + std::string(padRight, ' ');
}


//-----------------------------------------------------------------------------
// Function for printing a single student's details
//-----------------------------------------------------------------------------
void Util::PrintSingleStudent(Student const *currentStudent)
{
	Util::PrintTableHeader();
	std::cout<<*currentStudent<<std::endl;
	Util::PrintTableFooter();
}


//-----------------------------------------------------------------------------
// Function for printing the student report
//-----------------------------------------------------------------------------
void Util::PrintTheStudentReport(Student const *currentStudent, 
	int const &totalMarksOfStudent, 
	float const &percentageOfStudent, 
	char const &gradeObtainedByStudent)
{
	std::cout<< "-----------------------------------------------------------------------------------------------"<<std::endl;
	std::cout <<"                                                                                               "<<std::endl;
	std::cout<< "   							  Annual Report card : 2024	            					    "<<std::endl;
	std::cout <<"                                                                                               "<<std::endl;
	std::cout<< "-----------------------------------------------------------------------------------------------"<<std::endl;
	std::cout <<"                                                                                               "<<std::endl;

	Util::PrintSingleStudent(currentStudent);

	std::cout<< " Total Marks Obtaind : "<<totalMarksOfStudent<<std::endl;
	std::cout<< " Percentage Obtained : "<<percentageOfStudent<<" %"<<std::endl;
	std::cout<< " Grade Obtained : "<<gradeObtainedByStudent<<std::endl;

	std::cout<< "-----------------------------------------------------------------------------------------------"<<std::endl;

}


//-----------------------------------------------------------------------------
// Function for printing all students details
//-----------------------------------------------------------------------------
void Util::PrintAllStudentList(std::vector<Student*>const &listOfStudent, 
	bool const &isActive)
{
	int studentCount = listOfStudent.size();
	Util::PrintTableHeader();

	for(int iIndex = 0; iIndex < studentCount; ++iIndex)
	{
		// print the student in table if it is active (Not deleted)
		if(listOfStudent[iIndex]->GetStudentStatus() == isActive)
		{
			std::cout<<*listOfStudent[iIndex]<<std::endl;
		}
	}
	Util::PrintTableFooter();
}