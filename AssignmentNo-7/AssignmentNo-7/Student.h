#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include <unordered_map>

class Student
{
private:

	int m_studentID;
	int m_rollNo;
	std::string m_nameOfStudent;
	std::unordered_map<std::string, int>m_subjectAndMarks;
	float m_percentage;
	bool m_isActive;

public:

	// Constructors
	// User defined default constructor
	Student();

	// Parametrised Constructor
	Student(
		int studentId,
		int rollNo, 
		std::string nameOfStudent = "", 
		int marksOfMarathi = -1,
		int marksOfEnglish = -1,
		int marksOfPhysics = -1,
		int marksOfChemistry = -1,
		int marksOfBiology = -1,
		int marksOfMathematics = -1,
		bool isActive = true, 
		float percentage = -1);

	// Setter Methods
	void SetNameOfStudent(std::string const &studentName);
	void SetMarksOfMarathi(int const &marathi);
	void SetMarksOfEnglish(int const &english);
	void SetMarksOfPhysics(int const &physics);
	void SetMarksOfChemistry(int const &chemistry);
	void SetMarksOfBiology(int const &biology);
	void SetMarksOfMathematics(int const &Mathematics);
	void SetPercentageOfStudent(float const &percentage);
	void SetStatusOfStudent(bool const &status);

	// Getter Methods
	int GetStudentId()const;
	int GetStudentRollNo()const;
	std::string GetStudentName()const;
	int GetMarksOfMarathi()const;
	int GetMarksOfEnglish()const;
	int GetMarksOfPhysics()const;
	int GetMarksOfChemistry()const;
	int GetMarksOfBiology()const;
	int GetMarksOfMathematics()const;
	bool GetStudentStatus()const;
	float GetPercentageOfStudent()const;

	// Function for the printing the single student details in row
	friend std::ostream& operator<<(std::ostream& output, Student const &studentObj);

	// Destructor
	~Student();
};

#endif  // STUDENT_H