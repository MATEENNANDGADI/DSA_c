#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Header node (dummy node that points to first actual node)
struct Node* header = NULL;

// ---------------- Helper Functions ----------------

// Create a new node
struct Node* getnode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory not allocated!\n");
        exit(0);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Free a node
void freenode(struct Node* node) {
    free(node);
}

// Initialize Header Node
void initHeader() {
    header = getnode(-1);   // header stores dummy value
    header->next = NULL;
}

// ---------------- Operations ----------------

// Insert at beginning
void insertAtBeginning(int value) {
    struct Node* newNode = getnode(value);
    newNode->next = header->next;
    header->next = newNode;
}

// Insert at end
void insertAtEnd(int value) {
    struct Node* newNode = getnode(value);
    struct Node* temp = header;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Insert at specific position (1-based, after header)
void insertAtPosition(int value, int pos) {
    struct Node* newNode = getnode(value);
    struct Node* temp = header;
    for (int i = 0; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid Position!\n");
        freenode(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete at beginning
void deleteAtBeginning() {
    if (header->next == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = header->next;
    header->next = temp->next;
    freenode(temp);
}

// Delete at end
void deleteAtEnd() {
    if (header->next == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = header, *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == header) {   // only one node after header
        header->next = NULL;
    } else {
        prev->next = NULL;
    }
    freenode(temp);
}

// Delete at specific position
void deleteAtPosition(int pos) {
    if (header->next == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = header->next, *prev = header;
    for (int i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid Position!\n");
        return;
    }
    prev->next = temp->next;
    freenode(temp);
}

// Display Linked List
void display() {
    if (header->next == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = header->next;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// ---------------- Main Function ----------------
int main() {
    initHeader(); // initialize dummy header node

    insertAtBeginning(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtPosition(15, 1); // insert after 1st node

    display();

    deleteAtBeginning();
    display();

    deleteAtEnd();
    display();

    deleteAtPosition(1);
    display();

    return 0;
}
