// quick.cpp

#include "volsort.h"

#include <iostream>

// Prototypes

Node *qsort(Node *head, bool numeric);
void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric);
Node *concatenate(Node *left, Node *right);

// Implementations

void quick_sort(List &l, bool numeric) {

    l.head = qsort(l.head, numeric);

}

// recursive function
// call partition to split list into left and right
// call concatenate to join the sorted left and right lists
Node *qsort(Node *head, bool numeric) {

    // base case
    // if list is empty or only has one element left
    if (head == nullptr || head->next == nullptr) {

        return head;

    }

    // define pivot as the last element in the list
        Node *pivot = head;
        while (pivot != NULL && pivot->next != NULL) {

            pivot = pivot->next;

        }


    // Define left and right lists
    Node *left = nullptr;
    Node *right = nullptr;


    // call partition to split list into left and right
    partition(head, pivot, left, right, numeric);


    // recursively call qsort on left and right lists
    left = qsort(left, numeric);
    right = qsort(right, numeric);


    // call concatenate to join the sorted left and right lists
    head = concatenate(left, right);


    // return the head of the sorted list
    return head;
}

// helper function that splits linked list into left and right list
// left list is less than pivot, right list is greater than pivot
void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {
  
        Node *left_head = nullptr;
        Node *right_head = nullptr;

    
        
}

// helper function that concatenates two linked lists
// returns the head of the concatenated list
Node *concatenate(Node *left, Node *right) {

    while(left->next != nullptr) {

        left = left->next;

    }

    while(right != nullptr) {

        left->next = right;
        right = right->next;
        left = left->next;

    }
    
    return left;
}

