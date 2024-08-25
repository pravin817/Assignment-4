#ifndef UTIL_H
#define UTIL_H

#include "StudentManager.h"

#include <string>
#include <sstream>

class Util
{

public:
	//--------------------------------------------------------------------------
	// File Operation
	// 1. Read data from file
	static void ReadFromFile(std::string const &fileName, 
		char const &delimeter, 
		int &rollNo, 
		std::string &studentName, 
		int &marathi, 
		int &english, 
		int &physics, 
		int &chemistry, 
		int &biology, 
		int &mathematics);

	// 2. Function for the writing data to the file
	static void WriteToFile(
		std::string const &fileName,
		int studentId,
		int rollNo,
		std::string const &studentName,
		int marksOfMarathi = -1,
		int marksOfEnglish = -1,
		int marksOfPhysics = -1,
		int marksOfChemistry = -1,
		int marksOfBiology = -1,
		int marksOfMathematics = -1,
		bool status = true);

	// 3. Function used the writing complete data (complete list of the student to file).
	static void WriteToFile(StudentManager &studentManager);

	// Processing data from file

	// 1. Function for the getting the onestudent data.
	static void GetOneStudentDataFromLine(
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
		);

	// Automatic Operations
	static int CreateUniqueStudnetID(int standard, int studentRollNo);
	static int CreateRollNo(StudentManager const &studentManagerObj);

	// Conversion Functions
	static std::string FloatToString(float value);
	static std::string boolToString (bool value);


	// Validation functions

	// Function for the validations of marks
	// User must enter the marks between 0 to 100 both inclusive
	static void ValidateMarks(int &marks);
	static bool AreMarksAlreadyAdded(Student const *currentStudent);

	// Formatting and Output
	static void PrintTableHeader();
	static void PrintTableFooter();
	static std::string alignTextAtCenterOfTable(const std::string& text,
		int const &width);

	// Printing
	static void PrintSingleStudent(Student const *student);
	static void PrintAllStudentList(
		std::vector<Student*>const &listOfStudents, 
		bool const &isActive = true);

	// Function for the printing the student report
	static void PrintTheStudentReport(Student const *currentStudent, 
		int const &totalMarksOfStudent, 
		float const &percentageOfStudent, 
		char const &gradeObtainedByStudent);
};


#endif //UTIL_H