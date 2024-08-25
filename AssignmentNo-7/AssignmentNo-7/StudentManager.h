#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H

#include "Student.h"
#include <map>
#include <vector>


class StudentManager
{

private:
	std::vector<Student*>m_listOfStudents;
	std::map<int, Student*>m_rollNoToStudent;
	std::string m_fileName;
	int m_standard;

    // Function to initialize the system
	void InitSystem();
	
public:

	// Constructor
	StudentManager(int standard);

	// Setter Methods
	void SetFileName(const std::string& fileName);

	// Getter Methods
	int GetStudentCount()const;
	int GetStandard()const;
	std::string GetFileName()const;

    // Function to get a student by roll number
	Student* GetStudentByRollNo(int studentRollNo);
	
    // Function to add a new student to the database
	int AddStudent(std::string &nameOfStudent);

    // Function to delete a student by roll number
	bool DeleteStudentByRollNo(int studentRollNo);

    // Function to add marks for a student
	void AddMarksOfStudent(Student *currentStudent, 
						   int marksOfMarathi,
						   int marksOfEnglish, 
						   int marksOfPhysics, 
						   int marksOfChemistry, 
						   int marksOfBiology, 
						   int marksOfMathematics);

    // Function to update student details
	bool UpdateStudentDetails(Student *currentStudent,
							  std::string toBeUpdated, 
							  std::string toBeUpdatedWith);

    // Function to check if a student exists in the database
	bool isStudentExist(int rollNo);

   // Function to print all students details
	void PrintAllStudentList(bool const &isActive = true)const;

	// Function to start the execution of different operations
	void Execute();

	~StudentManager();
};

#endif //STUDENT_MANAGER_h