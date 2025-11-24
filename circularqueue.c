#include <stdio.h>
#include <conio.h>
#define MAX 5

struct CircularQueue
{
    int items[MAX];
    int front;
    int rear;
};

void initialize(struct CircularQueue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isFull(struct CircularQueue *q)
{
    return (q->front == 0 && q->rear == MAX - 1) || (q->front == q->rear + 1);
}

int isEmpty(struct CircularQueue *q)
{
    return q->front == -1;
}

void enqueue(struct CircularQueue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

int dequeue(struct CircularQueue *q)
{
    int item;
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
        return -1;
    }
    item = q->items[q->front];
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % MAX;
    }
    return item;
}

void display(struct CircularQueue *q)
{
    int i;
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (i = q->front; i != q->rear; i = (i + 1) % MAX)
    {
        printf("%d ", q->items[i]);
    }
    printf("%d\n", q->items[i]);
}

int main()
{
    struct CircularQueue q;
    int choice, value;
    initialize(&q);

    do
    {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(&q, value);
            break;
        case 2:
            value = dequeue(&q);
            if (value != -1)
                printf("Dequeued: %d\n", value);
            break;
        case 3:
            display(&q);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}