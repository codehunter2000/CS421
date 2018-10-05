#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

//--------------------------------------
// CS421 File td.cpp for HW2B
// Your name: *Gabriel Hunt*
//--------------------------------------

// ** Complete this to fit the HW2B specification - look for **
// ** Must have the same types of tracing couts as my demo program.

// info on each DFA
struct info
{
  string name;  // token name
  int startstate;
  int finalstate;
};

info DFA[4];      // store up to 4 dfas' start and final
int  TRS[10][4];  // store trs's - states 0-9 and chars a b c d 

// ----- utility functions -----------------------

void displayTables()
{
  // ** display TRS nicely labeled
	cout << "\n        a b c d" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "State " << i << ":";
		for (int j = 0; j < 4; j++)
		{
			if (TRS[i][j] != -1)
				cout << TRS[i][j] << " ";
			else
				cout << "  ";
		}
		cout << endl;
	}

  // ** display DFA nicely labeled
	for (info elem : DFA)
		if (elem.name != "")
			cout << "Token " << elem.name << ": " << elem.startstate << " is start and ends in " << elem.finalstate << endl;

}

void readTables()
{  

   ifstream fin ("C://Users//Gabriel//source//repos//codehunter2000//CS421//HW2BFiles//Prog2//trs.txt", ios::in);
   ifstream fin2 ("C://Users//Gabriel//source//repos//codehunter2000//CS421//HW2BFiles//Prog2//dfa.txt", ios::in);
   // ** read in the files into TRS and DFA

   int wTRS, ss, fs;
   string name, stuff;
   info elem;


	   for (int i = 0; i < 10; i++)
		   for (int j = 0; j < 4; j++)
		   {
			   fin >> stuff;
			   wTRS = stoi(stuff);
			   TRS[i][j] = wTRS;
		   }
   
   
   fin.close();

   int index = 0;
   while (fin2 >> name)
   {
	  // fin2 >> name;
	   fin2 >> ss;
	   fin2 >> fs;
	   elem.name = name;
	   elem.startstate = ss;
	   elem.finalstate = fs;
	   DFA[index] = elem;
	   index++;
   }
   
   fin2.close();

}

bool accept(info dfa, string word)
{
  // ** does the dfa accept the word?

	int state;
	if (dfa.name != "")
	{

		for (int i = 0; i < word.length(); i++)
		{
			state = 0;
			if ((state == 0) && (word[i] == dfa.name[0]))
				state = 1;
			else if ((state == 1) && (word[i] == dfa.name[0]))
				state = 1;
			else if ((state = 1) && (word[i] == dfa.name[1]))
				state = 2;
			else
				return false;
		}

		return true;

	}

	return false;
}


int main()
{
  cout << "This is a table driven scanner. Needs trs.txt and dfa.txt." << endl;
  cout << "States are 0 to 9 and chars are a to d" << endl;

  readTables();
  displayTables();
  cout << ".....done reading tables...." << endl;

  string word;
  bool accepted;
  while(true)
    { cout << "@@Enter a string: " ;
      cin >> word;
      // ** try the DFAs one by one and see 
      //     if the word is accepted
      // ** if so, display the word and the token name
      // ** if no DFA does, generate a lexical error message.
	  
	  for (info elem : DFA)
	  {
		  if (accept(elem, word))
		  {
			  cout << "word: " << word << "\t" << "token: " << elem.name << endl;
		  }

		  else
			  cout << "Lexical error!" << endl;
	  }
      cout << "do control-C to quit" << endl;
    }
}
