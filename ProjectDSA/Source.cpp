//LIBRARIES
#include<iostream>
#include<string>

//SFML LIBRARIES
#include<SFML\Graphics.hpp>

//CLASSES AND OTHER FUNCTIONS
#include"GlobalV.h"
#include"Button.h"
#include"MainScreen.h"
#include"ReadersScreen.h"
#include"LoginScreen.h"
#include"LibrarianScreen.h"
using namespace std;
using namespace sf;

//GLOBAL VARAIABLE INITIALIZED
int Logincounter = 0;
bool run = true;
bool bookcompleted = false;
int readercounter = 1;
string Ggender = " ";
int Aage = 0;
string markgenre[3] = { "","",""};
int ScreenCounter = 0;


//MAIN FUCNTIONS
int main()
{
	P1:
	if (ScreenCounter == 0)
	{
		MainScreen(); //MAINSCREEN
	}
	else if (ScreenCounter==1)
	{
		LoginScreen(); //LOGIN SCREEN
	}
	else if (ScreenCounter == 2)
	{
		ReaderSScreen(); //READER SCREEN DISPLAYED ONCE READER HAS LOGGED IN
	}
	else if(ScreenCounter == 3)
	{
		LibrarianScreenFunc(); // LIBRARIAN SCREEN FOR THE LIBRARIAN LOG IN
 	}
	goto P1; //LOOPING UNTIL USER CALLS EXIT


	return 0;
}