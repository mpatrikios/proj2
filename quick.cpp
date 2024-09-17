// quick.cpp

#include "volsort.h"

#include <iostream>

// Prototypes

Node *qsort(Node *head, bool numeric);
void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric);
Node *concatenate(Node *left, Node *right);

// Implementations

void quick_sort(List &l, bool numeric)
{

    l.head = qsort(l.head, numeric);
}

// recursive function
// call partition to split list into left and right
// call concatenate to join the sorted left and right lists
Node *qsort(Node *head, bool numeric)
{

    // base case
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    // if list is empty or only has one element left
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    // define pivot as the last element in the list
    Node *pivot = head;
    while (pivot != NULL && pivot->next != NULL)
    {

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
    head = concatenate(left, pivot);
    head = concatenate(head, right);

    // return the head of the sorted list
    return head;
}

// helper function that splits linked list into left and right list
// left list is less than pivot, right list is greater than pivot
void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric)
{
    left = nullptr;
    right = nullptr;
    Node *leftTail = nullptr;
    Node *rightTail = nullptr;
    Node *current = head;

    while (current != nullptr && current != pivot)
    {
        if (numeric)
        { // Numeric comparison
            if (node_number_compare(current, pivot))
            { // Add to the left list
                if (left == nullptr)
                {
                    left = current;
                    leftTail = left;
                }
                else
                {
                    leftTail->next = current;
                    leftTail = current;
                }
            }
            else
            { // Add to the right list
                if (right == nullptr)
                {
                    right = current;
                    rightTail = right;
                }
                else
                {
                    rightTail->next = current;
                    rightTail = current;
                }
            }
        }
        else
        { // String comparison
            if (node_string_compare(current, pivot))
            { // Add to the left list
                if (left == nullptr)
                {
                    left = current;
                    leftTail = left;
                }
                else
                {
                    leftTail->next = current;
                    leftTail = current;
                }
            }
            else
            { // Add to the right list
                if (right == nullptr)
                {
                    right = current;
                    rightTail = right;
                }
                else
                {
                    rightTail->next = current;
                    rightTail = current;
                }
            }
        }
        current = current->next; // Move to the next node
    }

    // Terminate both lists
    if (leftTail != nullptr)
        leftTail->next = nullptr;
    if (rightTail != nullptr)
        rightTail->next = nullptr;
}

// helper function that concatenates two linked lists
// returns the head of the concatenated list
Node *concatenate(Node *left, Node *right)
{

    if (left == nullptr)
        return right; // If the left list is empty
    if (right == nullptr)
        return left; // If the right list is empty

    Node *head = left; // head of list
    while (left->next != nullptr)
    { // go to the end of the left list
        left = left->next;
    }

    left->next = right; // add right list to the end of the left list

    return head;
}
