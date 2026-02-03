#include <stdio.h>
#define SIZE 5

int queue[SIZE], front = -1, rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue is Full!\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = value;
    printf("%d inserted into queue\n", value);
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("%d removed from queue\n", queue[front++]);
    if (front > rear) front = rear = -1;
}

void display() {
    if (front == -1) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int queue_size() {
    if (front == -1) return 0;
    return rear - front + 1;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    dequeue();
    display();

    enqueue(40);
    enqueue(50);
    display();

    printf("Current Queue Size: %d\n", queue_size());

    return 0;
}
