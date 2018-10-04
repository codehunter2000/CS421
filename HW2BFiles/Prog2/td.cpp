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
  // ** display DFA nicely labeled
  // ** display TRS nicely labeled
}

void readTables()
{  

   ifstream fin ("trs.txt", ios::in);
   ifstream fin2 ("dfa.txt", ios::in);
   // ** read in the files into TRS and DFA

   string wTRS;
   string wDFA;
   fin >> wTRS;
   for(int i = 0; i < 10; i++)
	   for (int j = 0; j < 4; j++)
	   {
		   DFA[i][j] = wTRS;
	   }
   fin.close();



}

bool accept(info dfa, string word)
{
  // ** does the dfa accept the word?
}


int main()
{
  cout << "This is a table driven scanner. Needs trs.txt and dfa.txt." << endl;
  cout << "States are 0 to 9 and chars are a to d" << endl;

  readTables();
  displayTables();
  cout << ".....done reading tables...." << endl;

  string word;
  while(true)
    { cout << "@@Enter a string: " ;
      cin >> word;
      // ** try the DFAs one by one and see 
      //     if the word is accepted
      // ** if so, display the word and the token name
      // ** if no DFA does, generate a lexical error message.
      cout << "do control-C to quit" << endl;
    }
}
