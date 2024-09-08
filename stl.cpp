// stl.cpp

#include "volsort.h"

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void stl_sort(List &l, bool numeric) {
    vector <Node*> nodeVector; //use a container that works with stl sort

    Node* current = l.head;

    while (current != nullptr) { //push all nodes into the vector
        nodeVector.push_back(current);
        current = current->next;
    }

    if (numeric) { //sort based on number
        sort(nodeVector.begin(), nodeVector.end(), node_number_compare);
    } else { //sort based on string
        sort(nodeVector.begin(), nodeVector.end(), node_string_compare);
    }

    l.head = nodeVector[0]; //set the head of the list to the first node in the vector

    for (size_t i = 0; i < nodeVector.size() - 1; i++) { //relink the nodes
        nodeVector[i]->next = nodeVector[i + 1];
    }

}

