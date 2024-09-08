// volsort.h

#ifndef VOLSORT_H
#define VOLSORT_H

#include <string>
#include <iostream>

struct Node {
    std::string string;
    int         number;
    Node       *next;
};

struct List {
    Node       *head;
    size_t      size;

    List(); 					// define in list.cpp
    ~List();					// define in list.cpp

    void push_front(const std::string &s);	//define below
};


// Functions -------------------------------------------------------------------

// adds a new node to the front of the list
void List::push_front(const std::string &s){
  
    Node *newNode = new Node; 

    newNode->string = s; //string field

    try { //if conversion fails default to 0
      newNode->number = stoi(s);
      } catch (std::invalid_argument){
        newNode->number = 0;
      }

    newNode->next = head; //make the head of the current list the 2nd node

    head = newNode; //make the new node the head of the list
    size++; //increase the size of the list
}



// prints all information in list starting at Node n
void dump_node(Node *n){

    while (n != nullptr) {
        std::cout << "String: " << n->string << ", Number: " << n->number << std::endl;
        n = n->next;
    }

}		

bool node_number_compare(const Node *a, const Node *b); 	//implement in list.cpp to avoid compile-time issues, used by quick, merge and stl
bool node_string_compare(const Node *a, const Node *b);		//implement in list.cpp to avoid compile-time issues, merge and stl
			

void stl_sort(List &l, bool numeric);	// define in stl.cpp - sort using std::sort
void qsort_sort(List &l, bool numeric);	// define in qsort.cpp - sort using qsort from cstdlib
void merge_sort(List &l, bool numeric);	// define in merge.cpp - your implementation
void quick_sort(List &l, bool numeric);	// define in quick.cpp - your implementation

#endif
