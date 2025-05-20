//**************************************************************
// Vector Showcase
// Name: William Pierce
//***************************************************************
// This program is designed to create three parallel vectors, fill these vectors with values, display these vectors, and the finally allow the option to remove an element from a vector.
// I will use a function to display the vectors, and an if statament inside of a while loop to allow the user the ability to remove elements. You can run this program
// by simply compiling and running
//*****************************************************************
//*******************************************************************
// FOR ALL FUNCTIONS ShowMe::Void()
// Parameters: vector<string>, vector<int>, vector<string>, int howbig
// vectors used are the three parallel vectors creates for faculty information, and the howbig int is a variable to detemrin e the size of the vector.
// This function displays the three vectors that were previosuly defined. 
//********************************************************************


#include <iostream> //Include the input output stream library
#include <vector>  //Include the use of vectors
using namespace std; //Eliminate need for "std::" 

// Function prototype for ShowMe
void ShowMe(vector<string>, vector<int>, vector<string>, int howbig);


int main()
{
	//Creating a variable that will be used for the Faculty removal
	char Answer;

	//Defining three vectors
	vector<string>Faculty;
	vector<int>Age;
	vector<string>Phone;

	//Growing Faculty vector
	Faculty.push_back("Tina Johnson");
	Faculty.push_back("Mika Morgan");
	Faculty.push_back("Eduardo Colmenares");

	//Growing Age vector
	//These ages are guesses, do not take at face value.
	Age.push_back(39);
	Age.push_back(28);
	Age.push_back(36);

	//Growing Number vector
	Phone.push_back("940-882-4864");
	Phone.push_back("940-882-3664");
	Phone.push_back("940-337-7456");

	//Get the size of the vectors
	int howbig = Faculty.size();
	
	// Call the ShowMe Function
	ShowMe(Faculty, Age, Phone, howbig);

	
	// While loop to run the removal procedure
	while (!Faculty.empty())
	{
		//Ask user if they would like to remove the last member of faculty
		cout << "Would you like to remove the last Faculty Member in the list? (Y/N)" << endl;
		cin >> Answer;
		cout << endl;

		if (Answer == 'Y' || Answer == 'y')
		{
			Faculty.pop_back();
			Age.pop_back();
			Phone.pop_back();
		}
		if (Answer == 'N' || Answer == 'n')
			cout << "Ok." << endl;

		// Call the ShowMe Function
		howbig = Faculty.size();
		ShowMe(Faculty, Age, Phone, howbig);
	}

	//Display that vector is empty
	if (Faculty.empty() == 1)
		cout << "Cannot remove more elements, the vector is empty" << endl;




	return 0;  // End of program
}

// Function HEader and Definition for ShowMe
void ShowMe(vector<string>Faculty, vector<int>Age, vector<string>Phone, int howbig)
{
	int i; 
	for (i = 0; i < howbig; i++)
	{
		cout << "Faculty Name: " << Faculty[i] << endl;
		cout << "Age: " << Age[i] << endl;
		cout << "Phone Number: " << Phone[i] << endl;
		cout << " =========================" << endl;
	}
}
