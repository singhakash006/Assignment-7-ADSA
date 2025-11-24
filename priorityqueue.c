#include <stdio.h>
#include <conio.h>
#define MAX_SIZE 100

// Structure for priority queue element
struct PQElement
{
    int data;
    int priority;
};

// Priority Queue structure
struct PriorityQueue
{
    struct PQElement arr[MAX_SIZE];
    int size;
};

// Initialize priority queue
void initialize(struct PriorityQueue *pq)
{
    pq->size = 0;
}

// Check if priority queue is empty
int isEmpty(struct PriorityQueue *pq)
{
    return pq->size == 0;
}

// Check if priority queue is full
int isFull(struct PriorityQueue *pq)
{
    return pq->size == MAX_SIZE;
}

// Enqueue element with priority
void enqueue(struct PriorityQueue *pq, int data, int priority)
{
    if (isFull(pq))
    {
        printf("Queue is full!\n");
        return;
    }

    pq->arr[pq->size].data = data;
    pq->arr[pq->size].priority = priority;
    pq->size++;
}

// Dequeue highest priority element
int dequeue(struct PriorityQueue *pq)
{
    if (isEmpty(pq))
    {
        printf("Queue is empty!\n");
        return -1;
    }

    int highestPriority = 0;
    // Find highest priority element
    for (int i = 1; i < pq->size; i++)
    {
        if (pq->arr[i].priority > pq->arr[highestPriority].priority)
        {
            highestPriority = i;
        }
    }

    // Store the data to return
    int data = pq->arr[highestPriority].data;

    // Remove the element by shifting others
    for (int i = highestPriority; i < pq->size - 1; i++)
    {
        pq->arr[i] = pq->arr[i + 1];
    }
    pq->size--;

    return data;
}

int main()
{
    struct PriorityQueue pq;
    initialize(&pq);

    // Test the priority queue
    enqueue(&pq, 10, 2);
    enqueue(&pq, 20, 1);
    enqueue(&pq, 30, 3);
    enqueue(&pq, 40, 2);

    printf("Dequeuing elements:\n");
    while (!isEmpty(&pq))
    {
        printf("%d ", dequeue(&pq));
    }

    getch();
    return 0;
}