// merge.cpp

#include "volsort.h"

#include <iostream>

Node *msort(Node *head, bool numeric);
void split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, bool numeric);

// This function compares 2 nodes and takes in numeric as to know how to compare the 2 nodes
bool compareNodes(Node *left, Node *right, bool numeric)
{
    if (numeric)
    {
        return (left->number <= right->number);
    }
    else
    {
        return (left->string < right->string);
    }
}

void merge_sort(List &l, bool numeric)
{
    l.head = msort(l.head, numeric); // Call recursive function on list
}

Node *msort(Node *head, bool numeric)
{
    // Base case
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    // Pointers for left and right sublist are modified inside split
    Node *leftptr = head;
    Node *rightptr = head;
    split(head, leftptr, rightptr);

    // Call recursive function on the 2 sublists
    Node *leftHead = msort(leftptr, numeric);
    Node *rightHead = msort(rightptr, numeric);

    // Merge 2 sublists
    head = merge(leftHead, rightHead, numeric);

    return head;
}

void split(Node *head, Node *&left, Node *&right)
{
    // If list is 1 or less no need to split
    if (head == nullptr || head->next == nullptr)
    {
        left = head;
        right = nullptr;
        return;
    }

    // Slow fast ptr trick
    Node *slow = head;
    Node *fast = head->next;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Set right ptr to beginning of right sublist, and the element before to the end of the left sublist
    right = slow->next;
    slow->next = nullptr;
}

Node *merge(Node *left, Node *right, bool numeric)
{
    // Set first node to return
    Node *firstNode;
    Node *currentNode;
    // Select first node
    if (compareNodes(left, right, numeric))
    {
        firstNode = left;
        left = left->next;
    }
    else
    {
        firstNode = right;
        right = right->next;
    }

    currentNode = firstNode;

    // Iterate through rest of sublists
    while (left != nullptr && right != nullptr)
    {
        if (compareNodes(left, right, numeric))
        {
            currentNode->next = left;
            left = left->next;
        }
        else
        {
            currentNode->next = right;
            right = right->next;
        }
        currentNode = currentNode->next;
    }

    // Add the remaining list to the end
    if (left == nullptr)
    {
        currentNode->next = right;
    }
    else
    {
        currentNode->next = left;
    }

    return firstNode;
}