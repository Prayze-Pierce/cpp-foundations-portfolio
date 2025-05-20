//**************************************************************
// Structures
// Name: William Pierce
//***************************************************************
// This code exemplifies my ability to use Structures as well as arrays of structures. I will intitally partially inititalize the first 3 element of the AOS, then use
// use a loop to inititalize the remining two element of the AOS in a element by element manner. I will then finally use a function to display these AOS and their contents.
//*****************************************************************
//*******************************************************************
// FOR ALL FUNCTIONSShowME::Void()
// Parameters: (const MsuFaculty FacultyArray[], const int CSIZE)
// MSU Faculty is the AOS that i will be passign into the function, and the CSIZE is the size of said AOS.
// The function will retrieve the valuues within the AOS and each of its element at each indexd, it will then displays these value, after the values name. 
//********************************************************************

#include <iostream>  // Include the iostream library for input and output
using namespace std;  // Use the standard namespace so we don't need to type "std::" before every command

//Defining a new Datatype for a structure named MsuFaculty
struct MsuFaculty
{
	string FLName;
	int Age;
	string Phone;
	string Email;
	string SSN;
	double GPA;
}; 

//Constant for the five element array of structures
const int CSIZE = 5;

//Function Prototype called ShowMe for displaying the  text
void ShowMe(const MsuFaculty FacultyArray[], const int CSIZE);



int main() 
{
	//Creating the Array of structures of 5 Faculty members, each with six elements.
	MsuFaculty FacultyArray[CSIZE] =
	{
		{"Tina Johnson", 39, "940-882-4864", "Tina.Johnson@gmail.com", "123-45-6789", 4.0},
		{"Eduardo Colmoneres", 38, "940-882-6321", "Eduardo.Colmoneres@gmail.com", "223-47-6759", 3.9},
		{"Mika Morgan", 31, "940-892-6721", "Mika.Morgan@gmail.com", "423-57-8759", 3.8},
	};


	// Using a loop to fill the remaining faculty members in the array.
	for (int i = 3; i < CSIZE; i++)
	{
		FacultyArray[i].FLName = "Sample Name";
		FacultyArray[i].Age = 22;
		FacultyArray[i].Phone = "999-999-9999";
		FacultyArray[i].Email = "Sample.Name@gmail.com";
		FacultyArray[i].SSN = "999-99-9999";
		FacultyArray[i].GPA = 2.2;
	}

	ShowMe(FacultyArray, CSIZE);

	return 0; // End of program
}
	

//Function Definition called ShowMe for displaying the  text
void ShowMe(const MsuFaculty FacultyArray[], const int CSIZE)
{
	// Displaying all faculty members
	for (int j = 0; j < CSIZE; j++)
	{
		cout << "Faculty Name: " << FacultyArray[j].FLName << endl;
		cout << "Age: " << FacultyArray[j].Age << endl;
		cout << "Phone: " << FacultyArray[j].Phone << endl;
		cout << "Email: " << FacultyArray[j].Email << endl;
		cout << "SSN: " << FacultyArray[j].SSN << endl;
		cout << "GPA: " << FacultyArray[j].GPA << endl;
		cout << "=========================" << endl;
	}

}

