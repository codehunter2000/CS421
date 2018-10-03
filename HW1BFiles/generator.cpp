#include<iostream>
#include<sstream>
#include<string>
#include<queue>
#include<vector>
using namespace std;
// include queue.h or equivalent such as <queue>

//----------------------------------------------
// CS421 HW1 
// Write a generator in C++ for L = {x | x is a binary number}.
// Your name: *Gabriel Hunt*
//----------------------------------------------

// Copy the recognizer function here from the other file.
bool recognizer(string s)
{
	// check to make sure string is not empty
	int size = s.length();
	if (size == 0)
	{
		cout << "Empty String" << endl;
		return false;
	}

	// dummy variable for debuging 
	char letter = NULL;

	// loop through string to ensure all characters are either 1's or 0's
	for (int i = 0; i < size; i++)
	{
		letter = s.at(i);
		if (letter != '0' && letter != '1')
			return false;
	}

	return true;

}// end of recognizer

template <typename T>
string to_string(T val)
{
	std::stringstream stream;
	stream << val;
	return stream.str();
}


// main: It should create each string over E = {0,1,2} systematically
//   (short to long) and pass each string to the recognizer function
//   created in Part a).  Hint: use a queue to generate strings
//   Only those strings for which the recognizer returned TRUE
//   should be displayed. 
//   Keeps on going until the queue overflows but the user can
//   terminate the program with control-C 
//   after about 20 strings have been displayed.
int main()
{ 
	queue<string> theQueue;	// to hold the final string
	vector<int> builder;	// used to ensure proper string structure/ordering
	string theString = "";	// dummy variable for debuging
	int lsd = 0;	// reset after 2. zero inputs ok. rightmost digit
	int index = 0;	// index for tracking
	bool good = false;	// if binary
	int elem;	// dummy variable
	builder.push_back(0);	// initialize vector

  while(true)
    {
	  // construct binary string
	  if (lsd < 3)	// ensures number don't exceed 2 as per project specs
	  {
		  theString.clear();	// empty string
		  builder[index] = lsd;	// modify last digit in string

		  // construct string for binary test
		  for (int i = 0; i < builder.size(); i++)
		  {
			  elem = builder[i];
			  theString = theString + to_string(elem);
		  }
		
		  theQueue.push(theString);	// place in the queue for testing
		  lsd++;
	  }

	  // reset and add new digit to vector
	  if (lsd == 3)
	  {
		  builder[index] = 0;
		  index++;
		  builder.push_back(0);
		  lsd = 0;
	  }
	
	  // check binary validity 
	  good = recognizer(theQueue.front());

	  // print number and bool result
	  cout << theQueue.front() << endl;
	  if (good)
		  cout << "TRUE" << endl;
	  else
		  cout << "FLASE" << endl;

	  // remove from queue
	  theQueue.pop();

    }// end of while

}// end of main
