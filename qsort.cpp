// qsort.cpp

#include "volsort.h"

#include <cstdlib>
#include <vector>
#include <array>
#include <iostream>

using namespace std;

void qsort_sort(List &l, bool numeric)
{
    vector<Node *> nodeVector;

    Node *current = l.head;

    while (current != nullptr)
    { // push all nodes into the vector
        nodeVector.push_back(current);
        current = current->next;
    }

    int arraySize = nodeVector.size();

    // Add all nodes to an array as that will work with qsort
    Node **array = new Node *[arraySize];
    for (int i = 0; i < arraySize; i++)
    {
        array[i] = nodeVector.at(i);
    }

    if (numeric == true)
    { // sort based on number
        qsort(array, arraySize, sizeof(Node *), qnode_number_compare);
    }
    else
    { // sort based on string
        qsort(array, arraySize, sizeof(Node *), qnode_string_compare);
    }

    for (int i = 0; i < arraySize - 1; i++)
    { // relink the nodes
        array[i]->next = array[i + 1];
    }

    l.head = array[0];                    // set the head of the list to the first node in the array
    array[arraySize - 1]->next = nullptr; // set the last node to nullptr
    delete[] array;
}
