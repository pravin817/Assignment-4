#include "stdafx.h"
#include "String.h"
#include <iostream>
#include <cmath>
#include <vector>


//-----------------------------------------------------------------------------
// Constructor used for the creating the string
String::String(std::vector<char>&input)
{
	int inputLength = input.size();
    
	// We added the one inorder to insert the '\0' at the end of the string
	// as the null character
    char *ch = new char[inputLength+1];
    
    // now copy the values one by one
    for( int i = 0; i < inputLength; ++i){
        ch[i] = input[i];
    }
    
	// We know that In C++, a string is usually just an 
	// array of (or a reference/points to) characters that ends with 
	// the NULL character ‘\0‘.
	// Hence insert the null ('\0') character at the end of the string

    ch[inputLength] = '\0';

	// Store the address in ptr
	m_ptr=ch;

	// Set the length for the string
	SetLength(inputLength);
}

// Copy constructor
String::String(String const &obj)
{
	char *tempchar = new char[obj.m_lengthOfString + 1];

	for(int  i = 0; i < obj.m_lengthOfString+1; ++i)
	{
		tempchar[i] = obj.m_ptr[i];
	}

	this->m_ptr=tempchar;
	this->m_lengthOfString = obj.m_lengthOfString;
};

// Setter Method


//-----------------------------------------------------------------------------
// Function for the setting the length of the string
void String::SetLength(int length)
{
	m_lengthOfString = length;
}

// Getter Methods 

//-----------------------------------------------------------------------------
// Function for the getting the length of the string
int String::GetLength()const
{
	return m_lengthOfString;
}


// Other functions

//-----------------------------------------------------------------------------
// Function for the printing the string
void String::PrintString()
{
	std::cout<<m_ptr;
};


//-----------------------------------------------------------------------------
// Function for the concatenation of the two strings
//String String::operator+(const String &str)
//{
//	// get the length of the First String
//	int lengthOfFirstString = this->GetLength();
//	int lengthOfSecondstring = str.GetLength();
//
//	int totalLength = lengthOfFirstString + lengthOfSecondstring;
//
//	char *tptr = new char[totalLength+1];
//
//	// Now copy the values one by one
//
//	int i = 0;
//
//	// Copy the values from the first string
//	for(int index = 0; index < lengthOfFirstString; ++index)
//	{
//		tptr[i++] = m_ptr[index];
//	}
//
//	// Now copy the values from the second string
//	for(int index = 0; index < lengthOfSecondstring; ++index)
//	{
//		tptr[i++] = str.m_ptr[index];
//	}
//
//	// Now append the null character at the end of the newly created string
//	tptr[totalLength] = '\0';
//
//	// Make the tptr points to m_ptr
//	m_ptr = tptr;
//
//	// Set the length
//	m_lengthOfString = totalLength+1;
//
//	std::cout<<"The string concatenation done successfully"<<std::endl;
//
//	return *this;
//}


//-----------------------------------------------------------------------------
// Function for the concatenation of the two strings
String String::operator+(const String &str)
{
	// get the length of the strings
	int lengthOfFirstString = this->GetLength();
	int lengthOfSecondstring = str.GetLength();

	std::vector<char>input;

	// Take the first string
	for(int index = 0; index < lengthOfFirstString; ++index){
		input.push_back(m_ptr[index]);
	}

	// Take the second string
	for(int index = 0; index < lengthOfSecondstring; ++index){
		input.push_back(str.m_ptr[index]);
		std::cout<<(str.m_ptr[index])<<std::endl;
	}
	
	String newStr(input);
	std::cout<<"The string concatenation done successfully"<<std::endl;
	return newStr;
}

//-----------------------------------------------------------------------------
// Function for the reversing the string
void String::Reverse()
{
	std::cout<<"The reverse function called "<<std::endl;

	int start = 0;
	int end = m_lengthOfString-1;

	while(start <= end)
	{
		char tempChar = m_ptr[start];
		m_ptr[start] = m_ptr[end];
		m_ptr[end] = tempChar;

		start++;
		end--;
	}
}

//-----------------------------------------------------------------------------
// Function for the string destruction
String::~String(void){
	//std::cout<<"The string destructor is called "<<std::endl;

	// Release the resources that you used
	delete [] m_ptr;

	std::cout<<"Before null : ";
	std::cout<<m_ptr<<std::endl;

	m_ptr = nullptr;

	std::cout<<"After null : ";
	std::cout<<m_ptr<<std::endl;

	/*	Question : In C++, deleting a pointer to a character involves two steps:
		Deallocate the memory: Use the delete operator to free the memory pointed to by the pointer.
		Set the pointer to nullptr: This prevents accidental access to the deallocated memory. 

		did it is neccessary to set nullptr
	*/
}

