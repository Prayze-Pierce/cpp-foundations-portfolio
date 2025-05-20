//**************************************************************
//Recursive Thinking
//Name: william Pierce
//***************************************************************
// This program displays my ability to understand an dimplement the concepts involved with recursion. There will be two functions Summation and BaseExponent
// Further details on the purpose of these functions will be providied at their definitions. 
//*****************************************************************


	// A note to colmenarez : I was struggling to understand exactly how i could implement the use of such large nbumbers as 10,000,000 without causing stack overflow. I must admit i did have to use google 
	// to understand the issue at hand. It seems that the problem lies within the users PC as you can choose how large you want your stack size to be, and by default i belive its at 1MB which is why it would 
	//only allow a certain number of recvursive calls to be done. The other solution would have to do with something called chunk sizes and implementing that into the recursion,
	// however i opted to not do as such since this wasnt a part of the syllabus. 


#include <iostream>
using namespace std;

// Function prototypes (more details for each fx is giving at its definition)
long long Summation(long long n1);
long double BaseExponent(long double base, long long exponent);


//*******************************************************************
// Function: main
// Parameters: None
// Returns: int - program termination
// Description: 
//*******************************************************************
int main()
{
	// The following chunk of code is the function call for summation and recieving the user value for the summation fx and storing it into the variable named result and print this. Long Long is used to account 
	// for the potentional of a very very big number. The while loop is used to account for the only restricition of a number larger than 0.
	long long n1;
	cout << "Please enter any number larger than zero that you would like to see the summation of all its odd components." << endl;
	cin >> n1;
	while (n1 <= 0)
	{
		cout << "That numebr is below or equal to zero, please eneter a new number." << endl;
		cin >> n1;
		cout << endl;
	}
	long long result = Summation(n1);
	cout << "The sum of all odd integers from 1 to " << n1 << " is: " << result << endl;
	cout << endl;

	// The following chunk of code is the function call for BaseExponent and recieving the user value for the Base value and Exponent Value and stores teh results into exp_result. Long double is used to account 
	// for the potentional of a negative exponent. 
	long double base;
	long long exponent;
	cout << "Please enter the base that you would like: " << endl;
	cin >> base;
	cout << endl;
	cout << "Please enter the exponent that you would like (Only positive integeres are allowed in this current model) " << endl;
	cin >> exponent;
	long double exp_result = BaseExponent(base, exponent);
	cout << base << " to the power of " << exponent << " is equal to " << exp_result << endl;


	//Termination of program
	return 0;
}

//*******************************************************************
// Function: Summation
// Parameters: n1 - The value the user wnat to be summed
// Returns: After all the recursion is complete, it returns the the summation of all odd number within the values of 1 and n1;
// Description: Computes the summation of all odd integers numbers between 1 and n1
//*******************************************************************
long long Summation(long long n1)
{
	// Base case for if n1 is zero or a negatiuve number
	if (n1 <= 0)
	{
		return 0;
	}

	//If n1 is odd include it into the summation, but if even skip it. This is also where the recursion occurs. 
	if (n1 % 2 == 1)
	{
	return n1 + Summation(n1 - 1);
	}
	else
	{
		return Summation(n1 - 1);
	}
}

//*******************************************************************
// Function: BaseExponent
// Parameters: long long Base and Long Long Exponent
// Returns: After recusion is complete, it will return base to the power of exponent. 
// Description: This function uses recursion to return the base to the power of exponent. 
//*******************************************************************
long double BaseExponent(long double base, long long exponent)
{
	// Base case for if exponent is 0, return 1
	if (exponent == 0.0) 
	{
		return 1;
	}

	// Recursive step that continues with base * base^(exponent-1) for all positive exponents
	else if (exponent > 0.0)
	{
		return base * BaseExponent(base, exponent - 1);
	}

	//This  is the use case for if the exponent is negative. ypou just do 1 / by the vale if the exponent were positive. 
	else
	{
		return 1.0 / (base * BaseExponent(base, -exponent - 1));
	}
}	