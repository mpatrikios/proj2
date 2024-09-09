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