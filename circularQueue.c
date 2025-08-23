#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

// Enqueue operation
void enqueue(int value) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue is FULL!\n");
    } else {
        if (front == -1)  // first insertion
            front = 0;
        rear = (rear + 1) % SIZE;
        queue[rear] = value;
        printf("Inserted %d\n", value);
    }
}

// Dequeue operation
void dequeue() {
    if (front == -1) {
        printf("Queue is EMPTY!\n");
    } else {
        printf("Deleted %d\n", queue[front]);
        if (front == rear) {
            // Queue becomes empty
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }
}

// Display operation
void display() {
    if (front == -1) {
        printf("Queue is EMPTY!\n");
    } else {
        int i = front;
        printf("Queue elements: ");
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    
    enqueue(40);
    enqueue(50);  // Queue full
    display();
    
    dequeue();
    dequeue();
    display();
    
    enqueue(60);
    enqueue(70);
    display();
    
    return 0;
}
