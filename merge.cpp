// merge.cpp

#include "volsort.h"

#include <iostream>

// Prototypes

Node *msort(Node *head, bool numeric);
void split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, bool numeric);

// Implementations
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
    l.head = msort(l.head, numeric);
}

Node *msort(Node *head, bool numeric)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *leftptr = head;
    Node *rightptr = head;
    split(head, leftptr, rightptr);

    Node *leftHead = msort(leftptr, numeric);
    Node *rightHead = msort(rightptr, numeric);
    head = merge(leftHead, rightHead, numeric);

    return head;
}

void split(Node *head, Node *&left, Node *&right)
{
    /*Node *beforeSlow = nullptr;
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        beforeSlow = slow;
        slow = slow->next;
        fast = fast->next;
        fast = fast->next;
    }

    right = slow;
    beforeSlow->next = nullptr;
    */

    if (head == nullptr || head->next == nullptr)
    {
        left = head;
        right = nullptr;
        return;
    }

    Node *slow = head;
    Node *fast = head->next;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    right = slow->next;
    slow->next = nullptr;
}

Node *merge(Node *left, Node *right, bool numeric)
{
    Node *firstNode;
    Node *currentNode;
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
