#ifndef STRING_H
#define STRING_H

#include <vector>

class String{

private:
	char *m_ptr;
	int m_lengthOfString;

public:

	// Declare the constructor
	String(std::vector<char>&ch);

	// Copy constructor
	String(String const &obj);

	// Setter Methods
	void SetLength(int length);
	
	// Getter Methods
	int GetLength()const;

	// Function for the printing the string
	void PrintString();

	// Function for the concatenation of the two strings
	String operator+(const String &str);

	// Function for the reversing the string
	void Reverse();

	// Function for the comparison of two string
	bool CompareTwoString(String const &str);

	// Declare the destructor 
	~String(void);
};

#endif // STRING_H