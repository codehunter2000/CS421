#include<iostream>
#include<string>
using namespace std;

//-------------------------------------------------------
// CS421 HW1 
// Write a recognizer in C++ for L = {x | x is a binary number}.
// Your name: *Gabriel Hunt*
//-------------------------------------------------------

//  The recognizer function should return TRUE or FALSE 
//  checking each character
//  to make sure it is 0 or 1. (leading 0's are allowed).
bool recognizer(string s)
{
	// ensure string is not empty
	int size = s.length();
	if (size == 0)
	{
		cout << "Empty String" << endl;
		return false;
	}
	
	// dummy variable for testing
	char letter = NULL;
	for (int i = 0; i < size; i++)
	{
		letter = s.at(i);
		if (letter != '0' && letter != '1')
				return false;
	}

	return true;

}// end of recognizer

//main: Given a string (from E) cined from the user, pass it to
//      the recognizer function.
//      Cout YES IN L or NO NOT IN L depending on what was returned.
int main()
{ 
	string input;	// dummy variable
	while (true)
	{
		cout << "Please enter a string: " << endl; // prompt for input
		cin >> input;

		// pass to recognizer to test binary validity
		bool result = recognizer(input);

		// print results
		if (result == true)
			cout << "YES IN L" << endl;
		else
			cout << "NO NOT IN L" << endl;
	}

}// end of main
