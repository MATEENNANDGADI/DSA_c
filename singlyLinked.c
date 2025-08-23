#include <stdio.h>
#include <stdlib.h>

// Define a Node
struct Node {
    int data;
    struct Node* next;
};

// Global head pointer (start of list)
struct Node* head = NULL;
