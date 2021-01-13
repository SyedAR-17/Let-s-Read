#pragma once
//LIBRARIES
#include<iostream>
#include<string>
#include<fstream>
#include"GlobalV.h"
#include"Linklist.h"
using namespace std;

////////////////LIBRARIAN///////////////////
class Librarian
{
protected:
	//LIBRARIAN DATA VARAIBLES
	string name;
	string PIN;
public:
	Librarian()
	{
		name = "";
		PIN = "";
	}

	//LOGIN FOR THE LIBRARIAN FUNCTION
	void loginLibrarian()
	{
		//OPENING THE FILE FOR READING
		ifstream line("Librarian.txt");
		Librarian L;
		line >> L.name;
		line >> L.PIN;
		string adminname;
		string password;
		cout << "Login" << endl;
	point2:
		//LOADING AND CHECKING THE CREDENTIALS
		cout << "Enter your username: " << endl;
		cin >> adminname;
		cout << "Enter the password: " << endl;
		cin >> password;
		if (L.name == adminname && password == L.PIN)
		{
			cout << "LOGIN" << endl;
		}
		else
		{
			cout << "Invalid Info." << endl;
			goto point2;
		}
		Logincounter = 2;
	}

	//ADD THE BOOK IN DATA BASE
	void addbook()
	{
		system("cls");
		linklist l1;
		string BN;
		string AN;
		string ID;
		string GN[3];
		float RA;
		//ENTER THE BOOK DATA
		cout << "Enter the Book Name: " << endl;
		cin >> BN;
		cout << "Enter the Authors Name: " << endl;
		cin >> AN;
		cout << "Enter the Book ID: " << endl;
		cin >> ID;
		for (int i = 0; i < 3; i++)
		{
			cout << "Enter the Book GENRE: "<< i << endl;
			cin >> GN[i];
		}
		cout << "Enter the Rating: " << endl;
		cin >> RA;
		l1.InsertDataBase(ID, BN, AN, GN, RA);
	}

	//DELETING THE BOOK IN DATA BASE
	void deletebook()
	{
		system("cls");
		string name;
		cout << "Enter the name of the book you want to delete: " << endl;
		cin >> name;
		linklist l1;
		ifstream input("Books.txt");
		l1.deleteindata(name, input);
	}

	//RECOMMEND THE BOOK TO THE USER
	void recommendabook(int a, string g)
	{
		//CALLING THE FUNCTIONS
		system("cls");
		cout << "BOOKS YOU MAYLIKE" << endl;
		linklist l1,l2,l3;
		l1.recommendinglist(a,g);
		l2.recommendgenre();
		l3.recommendations();
	}
	//LOGGING OUT
	void logoutLibrarian()
	{
		Logincounter = 0;
	}
};

