#pragma once
//LIBRARIES
#include<iostream>
#include<string>
#include<fstream>
#include"GlobalV.h"
using namespace std;

/////////////NODE///////////////////
struct node
{
public:
	string Bookname; //BOOKNAME
	string Author; //AUTHOR NAME
	string BookID; //BOOKID
	string Genre[3]; //ARRAY OF GENRE
	float rating; //RATING FOR EACH BOOK
	node* next; //NEXT POINTER
	node* prev; // PREVIOUS POINTER
};

/////////////LINKLIST/////////////////

class linklist
{
public:
	node* head = NULL; //INTIALIAZING HEAD POINTER
public:
	void Loadbook(ifstream& ifile) //FUNCTION TO LOAD THE BOOK LIST FROM FILE TO LINKLIST
	{
		string cont,line;
		for(;!ifile.eof();) //LOOP TO RUN UNTIL THE END OF FILE IS REACHED
		{
			node* NBook = new node;
			ifile >> NBook->Bookname; //WRITING THE DATA TO THE LINKLIST
			ifile >> NBook->Author;
			ifile >> NBook->BookID;
			ifile >> NBook->Genre[0];
			ifile >> NBook->Genre[1];
			ifile >> NBook->Genre[2];
			ifile >> NBook->rating;
			NBook->next = NULL;
			// ADJUSTING THE POINTERS OF THE NODES
			if (head == NULL)
			{
				head = NBook;         
				NBook->prev = NULL;
			}
			else
			{
				node* ptr = head;
				while (ptr->next)
				{
					ptr = ptr->next;
				}
				//ADJUSTING THE OTHER POINTERS
				ptr->next = NBook; 
				NBook->prev = ptr;
			}	
		}
	}
	// INSERT THE DATA INTO THE DATA BASE
	void InsertDataBase(string ID, string BookName, string BookAuthor, string Genre[3], float Rating)
	{
		ofstream line("Books.txt", std::ios_base::app); //OPENING THE FILE TO WRITE
		line << endl;
		line << "Book--:" << BookName << endl; //ENTERING THE NAME OF THE BOOK
		line << "AUTHOR:" << BookAuthor << endl; //ENTERING ATUTHOR NAME
		line << "BOOKID:" << ID << endl; //ENTERING OTHER DETAILS
		line << "GENRE-:" << Genre[0] << endl;
		line << "GENRE-:" << Genre[1] << endl;
		line << "GENRE-:" << Genre[2] << endl;
		line << Rating;
		cout << "BOOK ADDED" << endl;

	}
	//SERACH FUCNTIONS
	void SearchByGenre() //SEARCH BY GENRE THIS FUCNTIONS FINDS A BOOK ACCORDING TO THE GENRE ASKED
	{
		system("cls"); //CLEARING THE SCREEN
		int counter = 0;
		cout << "LETS SEARCH" << endl;
		cout << endl;
		ifstream Input("Books.txt"); //OPENING THE BOOK TO READ
		Loadbook(Input); //LOADING THE LIST CONTENTS IN THE LINKED LIST
		string name;
		cout << "Enter the Genre: " << endl; //ENTER THE NAME OF THE GENRE
		cin >> name;
		//LOOP TO SEARCH IN THE LINKLIST
		for (node* temp = head; temp ->next != nullptr; temp = temp->next)
		{
			if ((temp->Genre[0] == "GENRE-:" + name) || (temp->Genre[1] == "GENRE-:" + name))
			{
				cout << "--------------------" << endl;
				cout << temp->Bookname << endl;
				cout << temp->Author << endl;
				cout << temp->BookID << endl;
				cout << temp->Genre[0] << endl;
				cout << temp->Genre[1] << endl;
				cout << temp->Genre[2] << endl;
				cout << temp->rating << endl;
				cout << endl;
				counter=counter+1;
			}
			else if (temp->next == NULL && temp->Bookname != name && counter!=0) //ELSE CONDITION TO CHECK IF BOOK WAS NOT FOUND
			{
				cout << "No Book Found" << endl;
			}
		}
		cout << "Press Enter to Continue";
		cin.ignore();
	}
	void SearchByName(string name) //SERACH BY NAME, THIS FUCNTION SEARCHES A BOOK BY ITS NAME
	{
		system("cls");
		for (node* temp = head; temp != nullptr; temp = temp->next)
		{
			if (temp->Bookname == "Book--:" + name)
			{
				cout << temp->Bookname << endl;
				cout << temp->Author << endl;
				cout << temp->BookID << endl;
				cout << temp->Genre[0] << endl;
				cout << temp->Genre[1] << endl;
				cout << temp->Genre[2] << endl;
				cout << temp->rating << endl;
				cout << endl;
				break;
			}
			else if (temp->next == NULL && temp->Bookname != name)//ELSE CONDITION TO CHECK IF BOOK WAS NOT FOUND
			{
				cout << "Book Not Found" << endl;
			}
		}
		cout << "Press Enter to Continue";
		cin.ignore();
	}
	//MARK AS READ BY ID
	void MarkAsWantToReadByID(string ID)// FUNCTION TO CHECK THE BOOK LIST AND MARK THE ANY BOOK AS WANT TO READ
	{
		string rating; //RATING VARIABLE
		system("cls");
		string fileame;
		if (readercounter == 1)
		{
			fileame = "UsamaWantToRead.txt"; //OPENING THE FILES FOR THE USER, ACCORDING TO EACH ONE WHO HAS LOGGED IN
		}
		else if (readercounter == 2)
		{
			fileame = "ZainWantToRead.txt"; 
		}
		else if (readercounter == 3)
		{
			fileame = "SarahWantToRead.txt";
		}
		//MARKING THE BOOK AS WANT TO READ
		//WRITING THE DETAILS IN WANT TO READ FILE
		for (node* temp = head; temp != nullptr; temp = temp->next)
		{
			if (temp->BookID == "BOOKID:" + ID)
			{
				ofstream line(fileame, std::ios_base::app);
				line << endl;
				line << temp->Bookname << endl;
				line << temp->Author << endl;
				line << temp->BookID << endl;
				line << temp->Genre[0] << endl;
				line << temp->Genre[1] << endl;
				line << temp->Genre[2] << endl;
				line << temp->rating << endl;
				cout << "BOOK MARKED AS WANT TO READ" << endl;
				break;
			}
			else if((temp->BookID != "BOOKID:" + ID) && (temp->next==NULL))//ELSE CONDITION TO CHECK IF BOOK WAS NOT FOUND
			{
				cout << "BOOK NOT FOUND" << endl;
			}
		}
		cout << "Press Enter to Continue";
		cin.ignore();//TO PAUSE THE PROGRAM UNTIL USER PRESSES SOMETHING
	}
	// MAKR THE BOOK AS READ
	void MarkAsRead(string name)
	{

		system("cls");
		float rating;
		string fileame;
		//OPENING THE FILE ACCORDING TO THE USER
		if (readercounter == 1)
		{
			fileame = "UsamaWantToRead.txt";
		}
		else if (readercounter == 2)
		{
			fileame = "ZainWantToRead.txt";
		}
		else if (readercounter == 3)
		{
			fileame = "SarahWantToRead.txt";
		}
		ifstream Input(fileame);
		Loadbook(Input); //LOADING THE FILE IN LINKLIST FROM DATA BASE

		//WRITING THE BOOK IN MARKED AS READ LIST IN THE FILE
		for (node* temp = head; temp != nullptr; temp = temp->next)
		{
			if (temp->Bookname == "BOOK--:" + name)
			{
				cout << "How would you rate this book out of 5 ?" << endl;
				cin >> rating;
				if (readercounter == 1)
				{
					//OPENING THE FILE FOR USAMA
					ofstream line("UsamaMarkedAsRead.txt", std::ios_base::app);
					line << endl;
					line << temp->Bookname << endl;
					line << temp->Author << endl;
					line << temp->BookID << endl;
					line << temp->Genre[0] << endl;
					line << temp->Genre[1] << endl;
					line << temp->Genre[2] << endl;
					line << rating << endl;
					cout << "BOOK MARKED AS READ" << endl;
					break;
				}
				else if (readercounter == 2)
				{
					//OPENING THE FILE FOR ZAIN
					ofstream line("ZainMarkedAsRead.txt", std::ios_base::app);
					line << endl;
					line << temp->Bookname << endl;
					line << temp->Author << endl;
					line << temp->BookID << endl;
					line << temp->Genre[0] << endl;
					line << temp->Genre[1] << endl;
					line << temp->Genre[2] << endl;
					line << rating << endl;
					cout << "BOOK MARKED AS READ" << endl;
					break;
				}
				else if (readercounter == 3)
				{
					//OPENING THE FILE FOR SARAH
					ofstream line("SarahMarkedAsRead.txt", std::ios_base::app);
					line << endl;
					line << temp->Bookname << endl;
					line << temp->Author << endl;
					line << temp->BookID << endl;
					line << temp->Genre[0] << endl;
					line << temp->Genre[1] << endl;
					line << temp->Genre[2] << endl;
					line << rating << endl;
					cout << "BOOK MARKED AS READ" << endl;
					break;
				}
				
			}
			else if ((temp->Bookname != "BOOK--:" + name) && (temp->next == NULL))//ELSE CONDITION TO CHECK IF BOOK WAS NOT FOUND
			{
				cout << "BOOK NOT FOUND" << endl;
			}
		}
		bookcompleted = true;// SETTING THE VARIABLE TO TRUE
		cout << "Press Enter to Continue";
		cin.ignore();
	}
	//FUCNTION TO SEARCH THE BOOK ACCORDING TO THE AUTHOR
	void SearchByAuthor(string name)
	{
		system("cls"); //CLEARING THE SCREEN
		int counter = 0;
		//SEARCHIGN ALGORITHM
		for (node* temp = head; temp != nullptr; temp = temp->next)
		{
			if (temp->Author == "AUTHORs:" + name)
			{
				cout << temp->Bookname << endl;
				cout << temp->Author << endl;
				cout << temp->BookID << endl;
				for (int i = 0; i < 3; i++)
				{
					cout << temp->Genre[i] << endl;
				}
				cout << temp->rating << endl;
				cout << endl;
				counter++;
			}
			else if (temp->next == NULL && temp->Bookname != name && counter == 0)//ELSE STATEMENT IF NO BOOKS WERE FOUND
			{
				cout << "Book Not Found" << endl;
			}
		}
		cout << "Press Enter to Continue";
		cin.ignore();
	}

	//DELETING THE BOOK
	void deleteaBOOK(string name)
	{
		system("cls");//CLEARING THE SCREEN
		char d;
		//SEARCHING FOR THE BOOK TO BE DELETED
		for (node* temp = head; temp != nullptr; temp = temp->next)
		{
			if (temp->Bookname == "BOOK--:" + name)
			{
				cout << temp->Bookname << endl;
				cout << temp->Author << endl;
				cout << temp->BookID << endl;
				for (int i = 0; i < 3; i++)
				{
					cout << temp->Genre[i] << endl; //SPECIFYING THE GENRE
				}
				cout << temp->rating << endl;
				cout << endl;
				cout << "Do you want to Delete it ?(y/n)" << endl; //ASKING FOR CONFIRMATION TO DELETE THE BOOK
				cin >> d;
				//DELETING THE NODE IN THE LIST
				if (d == 'y')
				{
					if (temp == head)
					{
						head = head->next;
						head->prev = NULL;
						delete temp;
					}
					else if (temp->next == NULL)
					{
						temp->prev->next = NULL;
						delete temp;
					}
					else
					{
						temp->prev->next = temp->next;
						temp->next->prev = temp->prev;
						delete temp;
					}
				}
				cout << "DELETED" << endl;
				break;
			}
			else if (temp->next == NULL && temp->Bookname != name)// ELSE IF THE BOOK IS NOT FOUND
			{
				cout << "Book Not Found" << endl;
			}
		}
		cout << "Press Enter to Continue";
		cin.ignore();
	}

	//DELETING THE BOOK IN DATA BASE BY FILE HANDLING
	void deleteindata(string Bname, ifstream& ifile)
	{
		int counter = 0;
		ofstream temp;
		temp.open("temp.txt", std::ios_base::app); //OPENING THE FILE
		string deleteline = "BOOK--:" + Bname;
		string line;

		//FINDING THE LINES AND DELETING THE DATA
		while (getline(ifile, line))
		{
			if (line.substr(0, deleteline.size()) != deleteline && counter == 0)
			{
				temp << line << endl;
			}
			else
			{
				counter++;
				if (counter == 7) //DELETING THE 7 CONSECUTIVE LINES TO THE DELETING BOOK
				{
					counter = 0;
				}
			}
		}
		temp.close();
		ifile.close();

		//DELETING 
		if (bookcompleted == true)
		{
			if (readercounter == 1)
			{
				remove("UsamaWantToRead.txt");
				rename("temp.txt", "UsamaWantToRead.txt");
				bookcompleted = false;
			}
			else if (readercounter == 2)
			{
				remove("ZainWantToRead.txt");
				rename("temp.txt", "ZainWantToRead.txt");
				bookcompleted = false;
			}
			else if (readercounter == 3)
			{
				remove("SarahWantToRead.txt");
				rename("temp.txt", "SarahWantToRead.txt");
				bookcompleted = false;
			}
		}
		else
		{
			remove("Books.txt");
			rename("temp.txt", "Books.txt"); //DELETING AND RENAMING
			deleteaBOOK(Bname);
			cout << "Deleted" << endl;
		}
		cout << "Press Enter to Continue"; //PAUSING THE PROGRAM AND ENTERING TO CONTINUE
		cin.ignore();
	}

	//DISPLAY FUNCTION
	void display()
	{
		system("cls");//CLEARING THE SCREEN
		int counter = 0;
		//DISPLAYING EACH NDOE IN THE LINKLIST
		for (node* temp = head; temp != nullptr; temp = temp->next)
		{
			cout << "----------------" << endl;
			cout << temp->Bookname << endl;
			cout << temp->Author << endl;
			cout << temp->BookID << endl;
			for (int i = 0; i < 3; i++)
			{
				cout << temp->Genre[i] << endl;
			}
			cout << temp->rating << endl;
			cout << endl;
			counter = 1;
		}
		if (counter == 0) //IF LIST IS EMPTY
		{
			cout << "Nothing to Display" << endl;
		}
		cin.ignore();
	}

	//DISPLAYING THE FULL LIST OF BOOKS
	void Bookslist()
	{
		ifstream Inputfile("Books.txt");
		Loadbook(Inputfile);
		display();
		cout << "Press Enter to Continue";
		cin.ignore();
	}

	//DISPLAYING THE USER WANT TO READ LIST
	void WantToReadList()
	{
		system("cls");
		//OPENING THE LIST AN DISPLAYING IT
		if (readercounter == 1)
		{
			ifstream Input("UsamaWantToRead.txt");
			Loadbook(Input);
		}
		else if (readercounter == 2)
		{
			ifstream Input("ZainWantToRead.txt");
			Loadbook(Input);
		}
		else if (readercounter == 3)
		{
			ifstream Input("SarahWantToRead.txt");
			Loadbook(Input);
		}
		display();
		cout << "Press Enter to Continue";
		cin.ignore();
	}

	// DISPLAYING THE RECOMMENDED BOOKS
	void recommendinglist(int a, string g)
	{
		system("cls");
		int counter = 0;
		ifstream Inputfile("Books.txt");
		Loadbook(Inputfile);
		cout << "--------------------" << endl;
		cout << "BOOKS YOU MAY LIKE  " << endl;
		cout << "--------------------" << endl;
		//THIS FUNCTION DISPLAYS THE BOOK ACCORDING TO THE USER DATA
		for (node* temp = head; temp != nullptr; temp = temp->next)
		{
			if(g == "Male") //RECOMMENDATIONS FOR MALE USER
			{
				if ((temp->Genre[0] == "GENRE-:Buisness") || (temp->Genre[0] == "GENRE-:Fiction") || (temp->Genre[0] == "GENRE-:Political") || (temp->Genre[0] == "GENRE-:Fantasy") || (temp->Genre[0] == "GENRE-:History") || (temp->Genre[0] == "GENRE-:Classic") || (temp->Genre[0] == "GENRE-:Current_Affairs"))
				{
					cout << "---------------" << endl;
					cout << temp->Bookname << endl;
					cout << temp->Author << endl;
					cout << temp->BookID << endl;
					for (int i = 0; i < 3; i++)
					{
						cout << temp->Genre[i] << endl;
					}
					cout << temp->rating << endl;
					cout << endl;
					counter = counter + 1;
				}
				else if ((temp->Genre[1] == "GENRE-:Buisness") || (temp->Genre[1] == "GENRE-:Fiction") || (temp->Genre[1] == "GENRE-:Political") || (temp->Genre[1] == "GENRE-:Fantasy") || (temp->Genre[1] == "GENRE-:History") || (temp->Genre[1] == "GENRE-:Classic") || (temp->Genre[1] == "GENRE-:Current_Affairs"))
				{
					cout << "---------------" << endl;
					cout << temp->Bookname << endl;
					cout << temp->Author << endl;
					cout << temp->BookID << endl;
					for (int i = 0; i < 3; i++)
					{
						cout << temp->Genre[i] << endl;
					}
					cout << temp->rating << endl;
					cout << endl;
					counter = counter + 1;
				}
			}
			else if (g == "Female") //RECOMMENDATIONS FOR FEMALE USERS
			{
				if ((temp->Genre[0] == "GENRE-:Poetry") || (temp->Genre[0] == "GENRE-:Fiction") || (temp->Genre[0] == "GENRE-:Classic") || (temp->Genre[0] == "GENRE-:Crime") || (temp->Genre[0] == "GENRE-:Fantasy") || (temp->Genre[0] == "GENRE-:Classic") || (temp->Genre[0] == "GENRE-:Romance"))
				{
					cout << "---------------" << endl;
					cout << temp->Bookname << endl;
					cout << temp->Author << endl;
					cout << temp->BookID << endl;
					for (int i = 0; i < 3; i++)
					{
						cout << temp->Genre[i] << endl;
					}
					cout << temp->rating << endl;
					cout << endl;
					counter = counter + 1;
				}
				else if ((temp->Genre[1] == "GENRE-:Poetry") || (temp->Genre[1] == "GENRE-:Fiction") || (temp->Genre[1] == "GENRE-:Classic") || (temp->Genre[1] == "GENRE-:Crime") || (temp->Genre[1] == "GENRE-:Fantasy") || (temp->Genre[1] == "GENRE-:Health") || (temp->Genre[1] == "GENRE-:Romance"))
				{
					cout << "---------------" << endl;
					cout << temp->Bookname << endl;
					cout << temp->Author << endl;
					cout << temp->BookID << endl;
					for (int i = 0; i < 3; i++)
					{
						cout << temp->Genre[i] << endl;
					}
					cout << temp->rating << endl;
					cout << endl;
					counter = counter + 1;
				}
			}
			if (counter == 15)
			{
				break;
			}
		}
		node* current = head;
		//DESTROYING THE LST FOR NEXT DISPLAY LIST
		while (current != 0)
		{
			node* next = current->next;
			delete current;
			current = next;
		}
		head = 0;
	}

	//CHECKING THE GENRE WHICH USER PREFER OR RATED HIGHLY
	void recommendgenre()
	{
		if (readercounter == 1)
		{
			ifstream input("UsamaMarkedAsRead.txt");
			Loadbook(input);
		}
		else if (readercounter == 2)
		{
			ifstream input("ZainMarkedAsRead.txt");
			Loadbook(input);
		}
		else if (readercounter == 3)
		{
			ifstream input("SarahMarkedAsRead.txt");
			Loadbook(input);
		}
		float rate = 4.0;
		for (node* temp = head; temp != nullptr; temp = temp->next)
		{
			//STORING THE HIGHEST RATED BOOKS GENRE IN THE ARRAY
			if (temp->rating > rate)
			{
				rate = temp->rating;
				markgenre[0] = temp->Genre[0];
				markgenre[1] = temp->Genre[1];
				markgenre[2] = temp->Genre[2];
			}
		}
		for (int i = 0; i < 3; i++)
		{
			cout << markgenre[i] << endl;
		}
	}

	//MAKING THE RECOMMENDATIONS ACCORDING TO GENRE
	void recommendations()
	{
		int counter = 0;
		//OPENING AND LOADING THE LIST
		ifstream input("Books.txt");
		Loadbook(input);
		for (node* temp = head; temp != nullptr; temp = temp->next)
		{
			//FILTERING THE BOOKS
			if(temp->Genre[0] == markgenre[0] || temp->Genre[1] == markgenre[1] || temp->Genre[2] == markgenre[2] || temp->Genre[0] == markgenre[1] || temp->Genre[1] == markgenre[2] || temp->Genre[2] == markgenre[0])
			{
				cout << "---------------" << endl;
				cout << temp->Bookname << endl;
				cout << temp->Author << endl;
				cout << temp->BookID << endl;
				cout << temp->Genre[0] << endl;
				cout << temp->Genre[1] << endl;
				cout << temp->Genre[2] << endl;
				cout << temp->rating << endl;
				cout << endl;
				counter = counter + 1;
				if (counter == 15)
				{
					break;
				}
			}
		}
		cout << "Press Enter to Continue";
		cin.ignore();
	}

	//DESTRUCTOR
	~linklist()
	{
		node* current = head;
		while (current != 0) 
		{
			node* next = current->next;
			delete current;
			current = next;
		}
		head = NULL;
	}
};
