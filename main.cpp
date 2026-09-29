#include "LinkList.h"
#include <fstream>
#include <iostream>

using namespace std;

bool processFile(LinkList& ll, const std::string& file)
{
	ifstream fin;

	string word;
	char cmd; 

	fin.open(file);
	if (!fin.is_open()) return false;

	// all commands in command.txt have two parts -- the command and the data
	// the commands are:
	// a word -- append a word
	// p word -- prepend a word
	// s word -- search for a word
	// r word -- remove a word from the head
	// R word -- remove a word from the tail -- this should fail in singly linked lists
	// d head -- display the list from the head
	// d tail -- display the list from the tail -- this should fail in singly linked lists
	// q word -- quit, the word is irrelevant and is simply a place holder

	while (true)
	{
		// reading information from the file 
		if (fin.eof()) break;
		fin >> cmd;
		fin >> word; 

		if (cmd == 'q') break;

		switch (cmd)
		{
		case 'a':
			ll.append(word);
			break;
		case 'p':
			ll.prepend(word);
			break;
		case 's':
			if (ll.search(word))
			{
				std::cout << word << " is in the linked list" << std::endl;
			}
			else
			{
				std::cout << "Failed to find the word " << word << std::endl;
			}
			break;
		case 'r':
			if (!ll.remove(word))
			{
				std::cout << word << " wasn't in the list" << std::endl;
			}
			break;
		case 'R':
			if (!ll.removeBack(word))
			{
				std::cout << word << " wasn't in the list or this is a singly linked list" << std::endl;
			}
			break;
		case 'd':
			if (word == "head")
			{
				ll.display(std::cout);
				std::cout << std::endl;
			}
			if (word == "tail")
			{
				ll.displayBack(std::cout);
				std::cout << std::endl;
			}
			break;
		default:
			break;
		}
	}

	return true;
}

int main()
{
	// this program processes a series of commands from the specified file "dcommand.txt" 
	LinkList ll;
	bool worked = processFile(ll, "dcommand.txt");
	if (!worked)
	{
		cout << "Failed to process file ... check to see if it exists or can be read" << endl;
	}

	return 0;
}
