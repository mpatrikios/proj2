#include "volsort.h"

//constructor
List::List() {

    head = nullptr;
    size = 0;
    
}

//deconstructor
List::~List() { 

     Node* current = head;
     
     while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    
}

// compares number field
// returns true if a < b
bool node_number_compare(const Node *a, const Node *b){

    return a->number < b->number;

}

// compares string field
// returns true if a < b
bool node_string_compare(const Node *a, const Node *b){

    return a->string < b->string;

}