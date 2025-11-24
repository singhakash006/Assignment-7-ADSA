#include <stdio.h>
#include <conio.h>
#define MAX 5

struct Queue
{
    int items[MAX];
    int front;
    int rear;
};

void initialize(struct Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isFull(struct Queue *q)
{
    return (q->rear == MAX - 1);
}

int isEmpty(struct Queue *q)
{
    return (q->front == -1 || q->front > q->rear);
}

void enqueue(struct Queue *q, int value)
{
    if (isFull(q))
    {
        printf("\nQueue Overflow!");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
    printf("\nInserted -> %d", value);
}

void dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("\nQueue Underflow!");
        return;
    }
    printf("\nDeleted : %d", q->items[q->front]);
    q->front++;
    if (q->front > q->rear)
        initialize(q);
}

void display(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("\nQueue is Empty!");
        return;
    }
    printf("\nQueue elements are: ");
    for (int i = q->front; i <= q->rear; i++)
        printf("%d ", q->items[i]);
}

int main()
{
    struct Queue q;
    initialize(&q);

    int choice, value;
    while (1)
    {
        printf("\n\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter value to enqueue: ");
            scanf("%d", &value);
            enqueue(&q, value);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            display(&q);
            break;
        case 4:
            return 0;
        default:
            printf("\nInvalid choice!");
        }
    }
    return 0;
}
