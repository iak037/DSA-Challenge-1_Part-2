#pragma once

#include <string>
#include <iostream>
#include "node.h" // include node structure 

using namespace std;

#ifndef LINKLIST_H
#define LINKLIST_H 

class LinkList
{
private: 
    Node* head; // first node in the list 
    Node* tail; // last node in the list 
    Node* before;

public: 
    LinkList();
    ~LinkList();
    LinkList(const LinkList& old);	// Copy constructor 
    void append(const string& data); // insert data after the tail 
    void prepend(const string& data); // insert data before the head 
    bool search(const string& data); // find the string data in the list 
    bool remove(const string& data); // remove the node containing data from the list starting at the head 
    bool removeBack(const string& data); // remove the node containing data from the list starting at the tail
    void display(ostream& out); // displays the contents of the list starting at the head 
    void displayBack(ostream& out); // displays the contents of the list starting from the tail 

  };

#endif // LINKLIST_H;
