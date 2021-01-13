#pragma once

//LIBRARIES
#include<iostream>
#include<string>
#include<fstream>
#include"Librarain.h"
#include"GlobalV.h"
#include"Linklist.h"
using namespace std;


/////////////READER/////////////////

class reader
{
public:
	//READER DATA MEMBERS
	string username; 
	int age;
	string Gender;
	string PIN;
public:
	reader() //CONSTRUCTOR
	{
		username = "";
		PIN = "";
	}
	void loginS() //LOGIN FOR THE READER
	{
		int count=0;
		ifstream line("student.txt");
		reader s[3]; 
		//LOADING THE READERS CREDENTIALS FROM THE FILE
		for (int i = 0; i < 3; i++)
		{
			line >> s[i].username;
			line >> s[i].PIN;
			line >> s[i].Gender;
			line >> s[i].age;
		}
		string susername;
		string password;
		cout << "Login" << endl;
	point1:
		//ASKING TO ENTER AND THEN CHECKING THE CREDENTIALS
		cout << "Enter your username: " << endl;
		cin >> susername;
		cout << "Enter the password: " << endl;
		cin >> password;
		for (int i = 0; i < 3; i++)
		{
			if (susername == s[i].username && password == s[i].PIN)
			{
				count = 1;
				cout << "LOGIN" << endl;
				Aage=s[i].age; //STORING THR INFO ABOUT THE USER AGE
				Ggender = s[i].Gender; //STORING THE INFO ABOUT GENDER
				if (susername == "Usama")
				{
					readercounter = 1; //SETTING THE COUNTER
					break;
				}
				else if (susername == "Zain")
				{
					readercounter = 2;
					break;
				}
				else if(susername=="Sarah")
				{
					readercounter = 3;
					break;
				}
			}
		}
		//INCORRECT PASSWORD OR USERNAME
		if (count == 0)
		{
			cout << "Invalid USERNAME OR PASSWORD" << endl;
			goto point1;
		}
		count = 0;
		Logincounter = 1;
	}

	// FUNCTION FOR THE USER TO RECOMMEND THE BOOKS
	//COMPOSITION USED
	void LaunchLibrarian()
	{
		Librarian LL;
		LL.recommendabook(Aage, Ggender);
	}

	//MARK AS WANT TO READ
	void WantToRead()
	{
		string ID;
		linklist L00;
		string ame;
		ifstream Input("Books.txt");
		L00.Loadbook(Input);
		L00.display();
		cout << "Enter the Book ID you want to read" << endl;
		cin >> ID;
		L00.MarkAsWantToReadByID(ID);
	}

	//MARKING A BOOK AS READ
	void MarkAsRead()
	{
		string name;
		linklist l;
		linklist l4;
		l.WantToReadList();
		cout << "Enter the name of the book you have read" << endl;
		cin >> name;
		l4.MarkAsRead(name);
		if (readercounter == 1)
		{
			ifstream Input("UsamaWantToRead.txt");
			l4.deleteindata(name, Input);
		}
		else if (readercounter == 2)
		{
			ifstream Input("ZainWantToRead.txt");
			l4.deleteindata(name, Input);
		}
		else if (readercounter == 3)
		{
			ifstream Input("SarahWantToRead.txt");
			l4.deleteindata(name, Input);
		}
	}

	//WANT TO READ BOOKS LIST
	void WantToReadBooks()
	{
		linklist List;
		List.WantToReadList();
	}

	//LOGOUT FUNCTION
	void logout()
	{
		Logincounter = 0;
		readercounter = 0;
	}

	//LIST THE BOOKS
	void BooksListings()
	{
		linklist Listings;
		Listings.Bookslist();
	}

	//SEARCH THE BOOKS
	void SearchBooks()
	{
		linklist searchbooks;
		searchbooks.SearchByGenre();
	}

	//DESTRUCTOR
	~reader()
	{
		username = "";
		PIN = "";
	}
};

