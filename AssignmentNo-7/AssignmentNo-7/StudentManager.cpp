#include "stdafx.h"

#include "Student.h"
#include "StudentManager.h"
#include "Interface.h"
#include "Util.h"
#include "Calculations.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

//-----------------------------------------------------------------------------
// Constructor called
//-----------------------------------------------------------------------------
StudentManager::StudentManager(int standard) : m_standard(standard)
{
	m_fileName = "StudentDataOfClass"
		+std::to_string(static_cast<long long>(standard)) + ".txt";

	// Call the function that will load the initial data 
	// from file into the program
	InitSystem();
}


//-----------------------------------------------------------------------------
// Function used for loading the data from the file
//-----------------------------------------------------------------------------
void StudentManager::InitSystem()
{
	std::string fileName = GetFileName();
	std::ifstream fin(fileName);

	// Check if the file is open successfully or not.
	if(fin.is_open())
	{
		std::cout<<"The file opened successfully."<<std::endl;

		std::string currentStudent = "";

		while(getline(fin,currentStudent))
		{
			char delimiter = '\t';

			// Variables to hold the extracted values
			int studentId = -1,
				rollNo    = -1,
				marathi	  = -1,
				english	  = -1,
				physics	  = -1,
				chemistry = -1,
				biology	  = -1,
				mathematics = -1;
			bool isActive = true;
			std::string studentName = "";

			// Extract the student data and store it in the variables
			Util::GetOneStudentDataFromLine(currentStudent,
				studentId,
				rollNo,
				studentName,
				marathi,
				english,
				physics,
				chemistry,
				biology,
				mathematics,
				isActive);

			// Create the object of the student class
			Student *studObj = new Student(studentId, rollNo, 
				studentName, 
				marathi, 
				english, 
				physics,
				chemistry,
				biology,
				mathematics,
				isActive);

			int totalMarks = Calculation::CalculateTotalMarks(studObj);
			float percentage = Calculation::CalculatePercentage(totalMarks,6);

			// Set the percentage for the student
			studObj->SetPercentageOfStudent(percentage);

			// Add the student to the vector
			m_listOfStudents.push_back(studObj);

			// Update the map
			m_rollNoToStudent[rollNo] = studObj;
		}

		// close the file
		fin.close();
		std::cout << "The file closed successfully." << std::endl;
	}
	else
	{
		std::cout << "Warning : The file not open for the reading operation."
			      << std::endl;
	}
}

//Setter Methods

//-----------------------------------------------------------------------------
// Function to set filename 
//-----------------------------------------------------------------------------
void StudentManager::SetFileName(const std::string& fileName)
{
	m_fileName = fileName;
}


// Getter Methods

//-----------------------------------------------------------------------------
// Function for the getting the student count
//-----------------------------------------------------------------------------
int StudentManager::GetStudentCount()const
{
	return m_listOfStudents.size();
}


//-----------------------------------------------------------------------------
// Function for the getting the student standard
//-----------------------------------------------------------------------------
int StudentManager::GetStandard()const
{
	return m_standard;
}


//-----------------------------------------------------------------------------
// Function for the getting the name of file in which data is stored.
//-----------------------------------------------------------------------------
std::string StudentManager::GetFileName()const
{
	return m_fileName;
}

//-----------------------------------------------------------------------------
// Function for the additing the student
// Systen will generate the rollNo for the student and returns it
//-----------------------------------------------------------------------------
int StudentManager::AddStudent(std::string  &nameOfStudent)
{
	int standard = GetStandard();

	// 1. Generate the new roll number for new student
	int systemGeneratedRollNo = Util::CreateRollNo(*this);
	int studentId =Util::CreateUniqueStudnetID(standard,systemGeneratedRollNo);
	int studentRollNo = systemGeneratedRollNo;

    // Create the new student with studentId, rollNo, name
	Student *newStudent = new Student(studentId,studentRollNo,nameOfStudent);

    // Add new student to current list of students
	m_listOfStudents.push_back(newStudent);

	// Add newly created student to rollToStudentMap
	m_rollNoToStudent[studentRollNo] = newStudent;

	// Add new student to the file
	std::string fileName = GetFileName();
	Util::WriteToFile(fileName,studentId,studentRollNo,nameOfStudent);

	return studentRollNo;
}


//-----------------------------------------------------------------------------
// Function that checks if the student exists in the file or not
//-----------------------------------------------------------------------------
bool StudentManager::isStudentExist(int studentRollNo)
{
	if(m_rollNoToStudent.count(studentRollNo) > 0)
	{
		if(m_rollNoToStudent[studentRollNo]->GetStudentStatus())
			return true;
	}
	return false;
}


//-----------------------------------------------------------------------------
// Function for getting a student by roll number
//-----------------------------------------------------------------------------
Student* StudentManager::GetStudentByRollNo(int studentRollNo)
{
	return m_listOfStudents[studentRollNo-1];
}


//-----------------------------------------------------------------------------
// Function for adding marks to a student
//-----------------------------------------------------------------------------
void StudentManager::AddMarksOfStudent(Student *currentStudent,
									   int marksOfMarathi,
									   int marksOfEnglish, 
									   int marksOfPhysics, 
									   int marksOfChemistry, 
									   int marksOfBiology, 
									   int marksOfMathematics)
{
	// Add the marks of the particular student
	currentStudent->SetMarksOfMarathi(marksOfMarathi);
	currentStudent->SetMarksOfEnglish(marksOfEnglish);
	currentStudent->SetMarksOfPhysics(marksOfPhysics);
	currentStudent->SetMarksOfChemistry(marksOfChemistry);
	currentStudent->SetMarksOfBiology(marksOfBiology);
	currentStudent->SetMarksOfMathematics(marksOfMathematics);

	// Update the details of the students like percentage

	int updatedTotalMarks = Calculation::CalculateTotalMarks(currentStudent);
	float updatedPercentage = 
		Calculation::CalculatePercentage(updatedTotalMarks,6);

	currentStudent->SetPercentageOfStudent(updatedPercentage);

	// Update the marks in file
	Util::WriteToFile(*this);
}


//-----------------------------------------------------------------------------
// Function for the printing the list of the students 
//-----------------------------------------------------------------------------
void StudentManager::PrintAllStudentList(bool const &isActive)const
{
	int studentCount = m_listOfStudents.size();
	Util::PrintTableHeader();

	for(int iIndex = 0; iIndex < studentCount; ++iIndex)
	{
		// print the student in table if it is active (Not deleted)
		if(m_listOfStudents[iIndex]->GetStudentStatus() == isActive)
		{
			std::cout<<*m_listOfStudents[iIndex]<<std::endl;
		}
	}

	Util::PrintTableFooter();
}


//-----------------------------------------------------------------------------
// Function for updating student details
//-----------------------------------------------------------------------------
bool StudentManager::UpdateStudentDetails(Student *currentStudent, 
										  std::string tobeUpdate, 
										  std::string tobeUpdatedWith)
{
	bool isUpated = false;
	if(tobeUpdate == "nameOfStudent")
	{
		currentStudent->SetNameOfStudent(tobeUpdatedWith);
		isUpated =  true;
	}
	else if(tobeUpdate == "marksOfMarathi")
	{
		currentStudent->SetMarksOfMarathi(std::stoi(tobeUpdatedWith));
		isUpated = true;
	}
	else if(tobeUpdate == "marksOfEnglish")
	{
		currentStudent->SetMarksOfEnglish(std::stoi(tobeUpdatedWith));
		isUpated = true;
	}
	else if(tobeUpdate == "marksOfPhysics")
	{
		currentStudent->SetMarksOfPhysics(std::stoi(tobeUpdatedWith));
		isUpated = true;
	}
	else if(tobeUpdate == "marksOfChemistry")
	{
		currentStudent->SetMarksOfChemistry(std::stoi(tobeUpdatedWith));
		isUpated = true;
	}
	else if(tobeUpdate == "marksOfBiology")
	{
		currentStudent->SetMarksOfBiology(std::stoi(tobeUpdatedWith));
		isUpated = true;
	}
	else if(tobeUpdate == "marksOfMathematics")
	{
		currentStudent->SetMarksOfMathematics(std::stoi(tobeUpdatedWith));
		isUpated = true;
	}

	// If the student detail is updated then rewrite the file again
	if(isUpated)
	{
		// Update the percentage of the student

		int updatedTotalMarks = 
				Calculation::CalculateTotalMarks(currentStudent);
		float updatedPercentage = 
				Calculation::CalculatePercentage(updatedTotalMarks, 6);

		// Update the percentage of student
		currentStudent->SetPercentageOfStudent(updatedPercentage);

		Util::WriteToFile(*this);
		return true;
	}
	else
	{
		return false;
	}
}


//-----------------------------------------------------------------------------
// Function for deleting a student from the database
//-----------------------------------------------------------------------------
bool StudentManager::DeleteStudentByRollNo(int studentRollNo)
{
	// 1. Check if the student exist in the database (file)
	bool isExist = isStudentExist(studentRollNo);

	if(isExist)
	{
		// Show the details of the student that you wnat to delete
		Student *studentToBeDeleted = GetStudentByRollNo(studentRollNo);

		Util::PrintSingleStudent(studentToBeDeleted);

		// Ask the confirmation for the delations
		char deleteConfirmation = '-1';

		std::cout<<"Are you really want to delete this student: (y/n)(1/0) : ";
		std::cin>>deleteConfirmation;

		if(deleteConfirmation == 'y' || deleteConfirmation == '1')
		{
			// Just change the student active status
			studentToBeDeleted->SetStatusOfStudent(false);

			// Update the student data in file 
			Util::WriteToFile(*this);

			return true;
		}
	}
	return false;
}


//-----------------------------------------------------------------------------
// Function that performs all operations on data
//-----------------------------------------------------------------------------
void StudentManager::Execute()
{

	int choice = -1;
	do{
        std::cout << "\n-------------- MENU --------------------" << std::endl;
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "1. Add New Student" << std::endl;
        std::cout << "2. Add Marks to Existing Student" << std::endl;
        std::cout << "3. Update the Details of Existing Students" << std::endl;
        std::cout << "4. Delete a Student" << std::endl;
        std::cout << "5. Display the List of Active Students" << std::endl;
        std::cout << "6. Display the List of Inactive Students" << std::endl;
        std::cout << "7. Search Student" << std::endl;
        std::cout << "8. Get List of Toppers" << std::endl;
        std::cout << "9. Get List of Students by Marks" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

		switch(choice)
		{
		case 0:
			{
				std::cout<<"Exiting....."<<std::endl;
				break;
			}

		case 1:
			{
				std::cout << "Add the student" <<std::endl;

				std::string nameOfNewStudent = "";
				Interface::GetNameOfStudentFromUser(nameOfNewStudent);

				int rollNoOfStudent = AddStudent(nameOfNewStudent);

				if(rollNoOfStudent == -1)
				{
					std::cout<< "WARNING - Sorry unable to create the student."
						<<std::endl;
				}
				else
				{
					std::cout << "Message : The student with roll number "
						<<rollNoOfStudent<<" created successfully."
						<<std::endl;
				}
				break;
			}

		case 2:
			{

				std::cout<<"2. Add the marks "<<std::endl;

				int studentRollNo = -1;

				Interface::GetRollNumberFromUser(studentRollNo);

				// check if the student exist in the database
				bool isExist = isStudentExist(studentRollNo);

				if(isExist)
				{
					std::cout<<" The detail of the student with Roll No : "
						<<studentRollNo<<std::endl;

					// Get the student that marks we want to update
					Student *currentStudent = 
						GetStudentByRollNo(studentRollNo);

					// Print the student details
					Util::PrintSingleStudent(currentStudent);

					bool isMarksAlreadyAddedStatus = 
						Util::AreMarksAlreadyAdded(currentStudent);

					if(isMarksAlreadyAddedStatus)
					{					
						std::cout <<"WARNING - The marks of the student "
							<<"already entered. You can only update "
							<<"the marks of student"<<std::endl;
					}
					else
					{
						int marksOfMarathi = 0,
							marksOfEnglish = 0,
							marksOfPhysics = 0,
							marksOfChemistry = 0,
							marksOfBiology = 0,
							marksOfMathematics = 0;

						// Get the student marks from the user
						Interface::GetMarksFromUser(marksOfMarathi, 
							marksOfEnglish, 
							marksOfPhysics, 
							marksOfChemistry, 
							marksOfBiology, 
							marksOfMathematics);

						AddMarksOfStudent(currentStudent, 
							marksOfMarathi, 
							marksOfEnglish, 
							marksOfPhysics, 
							marksOfChemistry, 
							marksOfBiology, 
							marksOfMathematics);
					}
				}
				else
				{
					std::cout << "WARNING : Student with roll number "
						<<studentRollNo<<" doesn't exist in database."
						<<std::endl;
				}
				break;
			}

		case 3:
			{

				std::cout<<"3. Update the student"<<std::endl;

				int choiceForUpdate = -1;

				int rollNoStudent = -1;
				Interface::GetRollNumberFromUser(rollNoStudent);

				bool isExist = isStudentExist(rollNoStudent);

				if(isExist)
				{

					// Get the student that you want to update.
					Student *studentToBeUpdated = 
						GetStudentByRollNo(rollNoStudent);

					Util::PrintSingleStudent(studentToBeUpdated);

					std::cout <<"\n***** Student Update Menu *****"<<std::endl;
					std::cout << " 0. Exit from update student."<<std::endl;
					std::cout << " 1. Update Student Name. "<<std::endl;
					std::cout << " 2. Update Marathi Marks. "<<std::endl;
					std::cout << " 3. Update English Marks. "<<std::endl;
					std::cout << " 4. Update Physics Marks. "<<std::endl;
					std::cout << " 5. Update Chemistry Marks. "<<std::endl;
					std::cout << " 6. Update Biology Marks. "<<std::endl;
					std::cout << " 7. Update Mathematics Marks. "<<std::endl;

					std::cout << "Please select the update choice : ";
					std::cin >> choiceForUpdate;

					switch(choiceForUpdate)
					{
					case 0:
						{
							std::cout<<"Exiting from update option....."
								<<std::endl;
							break;
						}

					case 1:
						{
							std::cout << " 1. Update Student Name : "
								<<std::endl;

							std::string nameOfStudent;
							Interface::GetNameOfStudentFromUser(nameOfStudent);

							bool updateStatus = 
								UpdateStudentDetails(studentToBeUpdated,
								"nameOfStudent",
								nameOfStudent);

							if(updateStatus)
							{
								std::cout<<"UPDATE - Student name updated "
									<<"successfully."<<std::endl;		
							}
							else
							{
								std::cout<<"WARNING - Sorry student details "
									<<"are not updated."<<std::endl;
							}
							break;
						}

					case 2:
						{
							std::cout << " 2. Update Marks Of Marathi"
								<<std::endl;

							int marksOfMarathi = -1;

							std::cout<<"Enter the marks of marathi : ";
							Util::ValidateMarks(marksOfMarathi);

							bool updateStatus = 
								UpdateStudentDetails(studentToBeUpdated,
								"marksOfMarathi",
								std::to_string(
								static_cast<long long>(marksOfMarathi)
								));

							if(updateStatus)
							{
								std::cout << "UPDATE - The student marathi "
										  << "marks updated sucessfully."
										  << std::endl;		
							}
							else
							{
								std::cout << "WARNING - Sorry student details "
										  << "are not updated."<<std::endl;
							}

							break;
						}

					case 3:
						{
							std::cout << " 3. Update Marks Of English "
								      << std::endl;

							int marksOfEnglish = -1;

							std::cout<<"Enter the marks of English : ";
							Util::ValidateMarks(marksOfEnglish);

							bool updateStatus = UpdateStudentDetails(studentToBeUpdated,"marksOfEnglish",std::to_string(static_cast<long long>(marksOfEnglish)));

							if(updateStatus)
							{
								std::cout<<"UPDATE - The student English marks updated sucessfully."<<std::endl;		
							}
							else
							{
								std::cout<<"WARNING - Sorry student details are not updated."<<std::endl;
							}

							break;
						}

					case 4:
						{
							std::cout << " 4. Update Marks Of Physics "<<std::endl;

							int marksOfPhysics = -1;

							std::cout<<"Enter the marks of Physics : ";
							Util::ValidateMarks(marksOfPhysics);

							// Update the marks of Physics
							bool updateStatus = UpdateStudentDetails(studentToBeUpdated,"marksOfPhysics",std::to_string(static_cast<long long>(marksOfPhysics)));

							if(updateStatus)
							{
								std::cout<<"UPDATE - The student physics marks updated sucessfully."<<std::endl;		
							}
							else
							{
								std::cout<<"WARNING - Sorry student details are not updated."<<std::endl;
							}

							break;
						}

					case 5:
						{
							std::cout << " 5. Update Marks Of Chemistry "<<std::endl;

							int marksOfChemistry = -1;

							std::cout<<"Enter the marks of Chemistry : ";
							Util::ValidateMarks(marksOfChemistry);

							// Update the marks of Chemistry
							bool updateStatus = UpdateStudentDetails(studentToBeUpdated,"marksOfChemistry",std::to_string(static_cast<long long>(marksOfChemistry)));

							if(updateStatus)
							{
								std::cout<<"UPDATE - The student chemistry marks updated sucessfully."<<std::endl;		
							}
							else
							{
								std::cout<<"WARNING - Sorry student details are not updated."<<std::endl;
							}

							break;
						}

					case 6:
						{
							std::cout << " 6. Update Marks Of Biology "<<std::endl;

							int marksOfBiology = -1;

							std::cout<<"Enter the marks of biology : ";
							Util::ValidateMarks(marksOfBiology);

							// Update the marks of Biology
							bool updateStatus = UpdateStudentDetails(studentToBeUpdated,"marksOfBiology",std::to_string(static_cast<long long>(marksOfBiology)));

							if(updateStatus)
							{
								std::cout<<"UPDATE - The student biology marks updated sucessfully."<<std::endl;		
							}
							else
							{
								std::cout<<"WARNING - Sorry student details are not updated."<<std::endl;
							}

							break;
						}

					case 7:
						{
							std::cout << " 7. Update Marks of Mathematics "<<std::endl;

							int marksOfMathematics = -1;

							std::cout<<"Enter the marks of mathematics : ";
							Util::ValidateMarks(marksOfMathematics);

							// Update the marks of mathematics
							bool updateStatus = UpdateStudentDetails(studentToBeUpdated,"marksOfMathematics",std::to_string(static_cast<long long>(marksOfMathematics)));

							if(updateStatus)
							{
								std::cout<<"UPDATE - The student mathematics marks updated sucessfully."<<std::endl;		
							}
							else
							{
								std::cout<<"WARNING - Sorry student details are not updated."<<std::endl;
							}

							break;
						}

						// Update the percentage of the student
						int totalMarksOfStudent = Calculation::CalculateTotalMarks(studentToBeUpdated);
						float updatedPercentage = Calculation::CalculatePercentage(totalMarksOfStudent,6);

						// Update the percentage of the student
						studentToBeUpdated->SetPercentageOfStudent(updatedPercentage);
					}
				}
				else
				{
					std::cout << "WARNING - Student with "<<rollNoStudent<<" doesn't exit in database."<<std::endl;
				}

				break;
			}

		case 4:
			{
				// DELETE 

				std::cout << " 4. Delete the student by roll number."
					      << std::endl;

				int studentRollNo = -1;
				Interface::GetRollNumberFromUser(studentRollNo);

				bool deleteStudentStatus = 
					DeleteStudentByRollNo(studentRollNo);

				if(deleteStudentStatus)
				{
					std::cout << " The student with roll number "
						      << studentRollNo<<" deleted successfully."
							  << std::endl;
				}
				else
				{
					std::cout << " WARNING : Student with roll number "
						      << studentRollNo
							  << " doesn't deleted from the database."
							  << std::endl;
				}
				break;
			}

		case 5:
			{
				std::cout << "The complete list of the active students"
					      << std::endl;
				PrintAllStudentList();
				break;
			}

		case 6:
			{
				std::cout << "The complete list of the inactive students"
					      << std::endl;
				PrintAllStudentList(false);
				break;
			}

		case 7:
			{
				// Search the student

				int studentRollNo = -1;
				Interface::GetRollNumberFromUser(studentRollNo);
				bool isExist = isStudentExist(studentRollNo);

				if(isExist)
				{
					Student *studentToBeDisplay =
						GetStudentByRollNo(studentRollNo);
					Util::PrintSingleStudent(studentToBeDisplay);
				}
				else
				{
					std::cout << "Warning : Student with roll number "
						      << studentRollNo
							  << " not exist in database." << std::endl;
				}
				break;
			}

		case 8:
			{
				int studentStatisticsChoice = -1;  	
				std::cout << " 0. Back to main menu"<<std::endl;
				std::cout << " 1. Overall Topper list "<<std::endl;
				std::cout << " 2. Marathi Topper list "<<std::endl;
				std::cout << " 3. English Topper list "<<std::endl;
				std::cout << " 4. Physics Topper list "<<std::endl;
				std::cout << " 5. Chemistry Topper list "<<std::endl;
				std::cout << " 6. Biology Topper list "<<std::endl;
				std::cout << " 7. Mathematics Topper list "<<std::endl;

				std::cout<<"Please enter the choice : ";
				std::cin>>studentStatisticsChoice;

				// We need to copy the data for the perfroming operation
				std::vector<Student*>copyOfStudentList ;

				int studentCount = GetStudentCount();

				for(int iIndex = 0; iIndex < studentCount ; ++iIndex)
				{
					copyOfStudentList.push_back(GetStudentByRollNo(iIndex+1));
				}

				switch(studentStatisticsChoice)
				{

				case 0:
					{
						std::cout<<"Back to main menu...";
						break;
					}

				case 1:
					{
						std::cout << " 1. Overall Topper"<<std::endl;

						// Calculate the percentage of each student
						int studentCount = GetStudentCount();

						// Clear the list of students
						copyOfStudentList.clear();

						for(int iIndex = 0; iIndex < studentCount; ++iIndex)
						{
							Student *currentStudent = 
								GetStudentByRollNo(iIndex+1);

							// Calculate the total marks and percentage and update it
							int totalMarks = 
								Calculation::CalculateTotalMarks(currentStudent);
							float percentageOfStudent = 
								Calculation::CalculatePercentage(totalMarks,6);
							currentStudent->SetPercentageOfStudent(
								percentageOfStudent);

							copyOfStudentList.push_back(
								GetStudentByRollNo(iIndex+1));
						}

						// Sort the students based on the total marks
						std::sort(copyOfStudentList.begin(), copyOfStudentList.end(),
							[](Student *currentStudent1, Student *currentStudent2)
						{
							return currentStudent1->GetPercentageOfStudent() > currentStudent2->GetPercentageOfStudent();
						}
						);

						Util::PrintAllStudentList(copyOfStudentList);
						break;
					}

				case 2:
					{
						std::cout<<"2. Marathi Topper."<<std::endl;

						std::sort(copyOfStudentList.begin(), copyOfStudentList.end(),
							[](Student *student1, Student *student2)
						{
							return student1->GetMarksOfMarathi() > student2->GetMarksOfMarathi();
						});

						Util::PrintAllStudentList(copyOfStudentList);

						break;
					}

				case 3:
					{
						std::cout<<"3. English Topper."<<std::endl;

						std::sort(copyOfStudentList.begin(), copyOfStudentList.end(),
							[](Student *student1, Student *student2)
						{
							return student1->GetMarksOfEnglish() > student2->GetMarksOfEnglish();
						});

						Util::PrintAllStudentList(copyOfStudentList);
						break;
					}

				case 4:
					{
						std::cout<<"4. Physics Topper."<<std::endl;

						std::sort(copyOfStudentList.begin(), copyOfStudentList.end(),
							[](Student *student1, Student *student2)
						{
							return student1->GetMarksOfPhysics() > student2->GetMarksOfPhysics();
						});

						Util::PrintAllStudentList(copyOfStudentList);
						break;
					}

				case 5:
					{
						std::cout<<"5. Chemistry Topper."<<std::endl;

						std::sort(copyOfStudentList.begin(), copyOfStudentList.end(),
							[](Student *student1, Student *student2)
						{
							return student1->GetMarksOfChemistry() > student2->GetMarksOfChemistry();
						});

						Util::PrintAllStudentList(copyOfStudentList);
						break;
					}

				case 6:
					{
						std::cout<<"6. Biology Topper."<<std::endl;

						std::sort(copyOfStudentList.begin(), copyOfStudentList.end(),
							[](Student *student1, Student *student2)
						{
							return student1->GetMarksOfBiology() > student2->GetMarksOfBiology();
						});

						Util::PrintAllStudentList(copyOfStudentList);
						break;
					}

				case 7:
					{
						std::cout<<"7. Mathematics Topper."<<std::endl;

						std::sort(copyOfStudentList.begin(), copyOfStudentList.end(),
							[](Student *student1, Student *student2)
						{
							return student1->GetMarksOfMathematics() > student2->GetMarksOfMathematics();
						});

						Util::PrintAllStudentList(copyOfStudentList);
						break;
					}
				}
				break;
			}

		case 9:
			{
				std::cout<<" 9. Print Student Report"<<std::endl;

				int reportOption = -1;
				std::cout << " 0. Go to main menu."<<std::endl;
				std::cout << " 1. Get the report of one student by roll no"
						  << std::endl;
				std::cout << " 2. Get the report of all students."<<std::endl;

				std::cout <<" Please enter the report option:";
				std::cin >> reportOption;

				switch(reportOption)
				{
				case 1:
					{
						std::cout<<"1. Get the report of one student."<<std::endl;

						int studentRollNo;
						Interface::GetRollNumberFromUser(studentRollNo);

						bool isExist = isStudentExist(studentRollNo);

						if(isExist)
						{
							int totalNumberOfSubject = 6;

							// Get the current processing student
							Student *currentStudent = GetStudentByRollNo(studentRollNo);

							// Get the result of all calculation
							int totalMarksOfStudent = 
								Calculation::CalculateTotalMarks(currentStudent);
							float percentageOfStudent = 
								Calculation::CalculatePercentage(totalMarksOfStudent, 
								totalNumberOfSubject);
							char gradeObtainedByStudent = 
								Calculation::CalculateGrade(percentageOfStudent);

							//Set the percentage of the student 
							currentStudent->SetPercentageOfStudent(percentageOfStudent);

							// check if we get the report of the student or not.

							bool isMarksOfAllSubjectAdded = 
								Util::AreMarksAlreadyAdded(currentStudent);

							if(isMarksOfAllSubjectAdded)
							{
								// Print the student report card
								Util::PrintTheStudentReport(currentStudent, 
									totalMarksOfStudent, 
									percentageOfStudent, 
									gradeObtainedByStudent);
							}
							else
							{
								std::cout << " Marks of the student not added."
									      << std::endl;
							}
						}
						else
						{
							std::cout << "WARNING - Student with roll number "
								      << studentRollNo
									  << " doen't exist in database."
									  << std::endl;
						}
						break;
					}

				case 2:
					{
						std::cout << "2. Print all student report."
							      << std::endl;

						Util::PrintAllStudentList(m_listOfStudents);
						break;
					}
				}
				break;
			}

		case 100:
			{

				int roll;
				Interface::GetRollNumberFromUser(roll);

				bool isExist = isStudentExist(roll);
				break;
			}

		default:
			{
				std::cout<<"Please enter the correct choice."<<std::endl;
			}
		}
	}while(choice!=0);
}


//-----------------------------------------------------------------------------
// Function for the destruction of the student manager object.
//-----------------------------------------------------------------------------
StudentManager::~StudentManager()
{
	int studentCount = GetStudentCount();
	for(int iIndex = 0; iIndex < studentCount; ++iIndex)
	{
		delete m_listOfStudents[iIndex];
	}

	//m_listOfStudents.clear();
	std::cout<<"The student manager destructor called...."<<std::endl;
}