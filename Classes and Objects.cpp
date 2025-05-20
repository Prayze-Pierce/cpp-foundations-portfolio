
//**************************************************************
// Classes and Objects
// Name: William Pierce
//***************************************************************
// This program simulates a supermarket basket system where customers can manage apples and oranges.
// It implements a Basket class with functionality to create baskets, modify their contents, display
// their contents, combine baskets, and clean up with a destructor. The program meets the requirements
// of the Midwestern State University Data Structures and ADT Spring 2025 HM3 assignment.
//
// The Basket class includes:
// - A default constructor (initializes to 0 apples and 0 oranges)
// - A parameterized constructor (sets initial apples and oranges)
// - Mutators (SetApples, SetOranges) to modify contents
// - Accessors (GetApples, GetOranges) to retrieve contents
// - A ShowMe function to display both apples and oranges
// - An AddBaskets function to combine two baskets into a new one
// - A destructor to print a farewell message
//
// How to Run:
// - Compile and run in Visual Studio.
// - No input files or user input required; the program uses hardcoded values as per assignment steps.
// - Output displays basket contents and destructor messages automatically.

#include <iostream>  // Include the iostream library for input and output
using namespace std;  // Use the standard namespace so we don't need to type "std::" before every command

//Class for the 
class Baskets
{
private:
	int Apples;
	int Oranges;


public:
	//Fx Prototype for default constructor. Used to create Object B1 and have default values of 0.
	Baskets();

	//Fx Prototype fpr parametrized constructor. Used to create an object with given values. 
	Baskets(int NApples, int NOranges);

	//Mutator to set the values of number of Apples within the object.
	void SetApples(int NApples);

	//Mutator to set the values of number of Oranges within the object
	void SetOranges(int NOranges);


	//Accessor used to display the number of Apples within the object.
	int GetApples();

	//Accessor used to display the number of Oranges within the object.
	int GetOranges();

	//Member Fx used to display the contents of the object
	void ShowMe();

	//member Fx to add the baskets and return a final basket
	Baskets AddBaskets(Baskets other);

	//Desturctor to display farewell text
	~Baskets();
};




int main()
{
	Baskets b1;			// Create a basket b1 using default constructor
	b1.SetApples(20);	//use the mutator to change the number of apples in b1 to 20.
	b1.SetOranges(20);	//use the mutator to change the number of oranges in b1 to 20.
	
	Baskets b2(30, 40);  //Create a second basket b2 using your parameterized constructor.

	cout << "These are the conetents of b1:" << endl;
	b1.ShowMe();		//Display the conetents of b1
	cout << "These are the conetents of b2:" << endl;
	b2.ShowMe();		//Display the conetents of b2
	
	Baskets b3 = b1.AddBaskets(b2);	//Call the add baskets fucntion to add the baskets.

	cout << "These are the conetents of b3:" << endl;
	b3.ShowMe();		//Display the conetents of b3

	cout << "There are " << b1.GetApples() << " apples in b1." << endl;  //Display the apples in b1

	cout << "===============================" << endl;

	cout << "There are " << b2.GetOranges() << " Oranges in b2." << endl;  //Display the conetents of b2

	cout << "===============================" << endl;
	
	return 0;		//Terminate Main
}

//Fx Definitions 
//Class Orientated Definitions

//Default Constructor used to create the first object B1 and assign it values of 0
Baskets::Baskets()
{
	Apples = 0;
	Oranges = 0;
}

//parametrized constructor Used to create an object with given values. 
Baskets::Baskets(int NApples, int NOranges)
{
	Apples = NApples;
	Oranges = NOranges;
}

//Mutator to set the values of number of Apples within the object
void Baskets::SetApples(int NApples)
{
	Apples = NApples;
}

//Mutator to set the values of number of Oranges within the object
void Baskets::SetOranges(int NOranges)
{
	Oranges = NOranges;
}

//Accessor used to display the number of Apples within the object.
int Baskets::GetApples()
{
	return Apples;
}

//Accessor used to display the number of Oranges within the object.
int Baskets::GetOranges()
{
	return Oranges;
}

//Member Fx used to display the contents of the object
void Baskets::ShowMe()
{
	cout << "This Basket contains " << GetApples() << " apples, and " << GetOranges() << " Oranges."
		<< endl;
	cout << "===============================" << endl;
}


//member Fx to add the baskets and return a final basket
Baskets Baskets:: AddBaskets(Baskets other)
{
	int TotApples = Apples + other.GetApples();  //uses other as a placeholder for other objects. Using the 'datatype' of Baskets
	int TotOranges = Oranges + other.GetOranges();  //it then adds these values to the value of the variables of the object used to invoke and stores in new variabkle

	Baskets b3;				//creates a new object of b3
	b3.SetApples(TotApples);  //sets the values of apples and oranges in this new object to the values we just caluclated
	b3.SetOranges(TotOranges);
	return b3;					//returns the object
}

//Desturctor to display farewell text
Baskets::~Baskets()
{
	cout << "bye-bye destructor being called" << endl;
	cout << "===============================" << endl;
}