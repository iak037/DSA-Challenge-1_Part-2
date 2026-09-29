#include "LinkList.h"

LinkList::LinkList() // default constructor 
{
    head = nullptr;
    tail = nullptr; 
}

LinkList::~LinkList() // destructor  
{
    Node* temp;

    while (head != nullptr)
    {
        temp = head->next; // grabs the node after the head 

        delete head; // deletes the head 

        head = temp; // reassigns the head 
    }
}

LinkList::LinkList(const LinkList& old) // Copy constructor 
{
    head = nullptr;
    tail = nullptr; 

    Node* temp = old.head;

    while (temp != nullptr)
    {
        append(temp->data);
        temp = temp->next;
    }
}

void LinkList::append(const string& data) // insert data after the tail 
{
    Node* temp = new Node(data); // create the new node 

    temp->prev = tail; // set the new node's previous pointer to the tail 

    if (head == nullptr) // check for an empty list 
    {
        head = temp; // if the list is empty, set the head to the new node 
    }

    else
    {
        tail->next = temp; // set tail's next to the new node
    }

    tail = temp; // set tail to the new node

}

void LinkList::prepend(const string& data) // insert data before the head 
{
    Node* temp = new Node(data); // create the new node

    if (head == nullptr) // check for an empty list
    {
        tail = temp; // if the list is empty, set the tail to the new node
    }
    else
    {
        head->prev = temp; 
    }

    temp->next = head; // set the new node's next to head
    head = temp; // set the head to the newly created node
}

bool LinkList::search(const string& data) // find the string data in the list 
{ 
    Node* temp = head; // set the current temp node to the head

    while (temp != nullptr) // loop while the node is still in the list
    {
        if (temp->data == data) // if the data is found
            return true; // return true
        temp = temp->next; // set temp to the next node in the chain 
    }

    return false; // return false if the loop has exited without finding the data
}

bool LinkList::remove(const string& data) // remove the node containing data from the list starting at the head 
{
    Node* temp = head; // set the current node to the head
    Node* prev = nullptr; // set the previous node to nullptr

    while (temp != nullptr) // loop while the node is still in the list
    {
        if (temp->data == data) // if the data is found
        {
            if (temp == head) // check to see if we are deleting the head
            {
                head = temp->next; // set head to the next node in the chain
            }
            else
            {
                temp->prev->next = temp->next; // set prev node next to next node 
            }
            if (temp == tail) // check to see if we are deleting the tail
            {
                tail = prev; // set the tail to the prev node in the chain
            }
            else
            {
                temp->next->prev = temp->prev;
            }

            delete temp; // delete the current node
            return true;
        }
        temp = temp->next; // set the current node to the next node in the chain
    }
    return false; // return false if the loop has exited without finding the data
}

bool LinkList::removeBack(const string& data) // remove the node containing data from the list starting at the tail 
{
    Node* temp = tail; // start here and move backwards 

    while (temp != nullptr) // loop while the node is still in the list 
    {
        if (temp->data == data) 
        {
            if (temp == head) 
            {
                head = temp->next;
                head->prev = nullptr;
            }
            
            else if (temp == tail)
            {
                tail = temp->prev;
                tail->next = nullptr;
            }

            else
            {
                temp->prev->next = temp->next; // if you get confused later see the yellow paper chart 
                temp->next->prev = temp->prev;
            }

            delete temp;
            return true;
        }
        else
        {
            temp = temp->prev;
        }
    }

    return false;
}

void LinkList::display(ostream& out) // displays the contents of the list starting at the head 
{
    Node* temp = head; // set the current temp node to the head
    while (temp != nullptr) // loop while the node is still in the list
    {
        out << temp->data << " "; // output the data stored in the current node
        temp = temp->next; // set temp to the next node in the chain 
    }
}

void LinkList::displayBack(ostream& out) // displays the contents of the list starting from the tail (double) 
{
    Node* temp = tail; 
    while (temp != nullptr)
    {
        out << temp->data << " ";
        temp = temp->prev;
    }

}
