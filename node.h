#pragma once

#include <string>
using namespace std;

#ifndef NODE_H
#define NODE_H 

// In the node's class (or struct) definition, add a new member: a pointer named prev. 
// Edit the node's constructors to incorporate the new prev pointer.

class Node 
{
public: 
    string data;
    Node* next; // points to the next node in the sequence 
    Node* prev; // doubly linked list: points to the previous node in the sequence 

    Node() // zero constructor 
    {
        data = "";
        next = nullptr;
        prev = nullptr;
    };

    // take in data -- assigns next pointer to nullptr 

    Node(string data)
    {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    };

};

#endif // NODE_H
