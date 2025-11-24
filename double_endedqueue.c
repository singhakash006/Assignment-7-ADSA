#include <stdio.h>
#include <conio.h>
#define MAX 5

struct deque
{
    int arr[MAX];
    int front, rear;
};

void initialize(struct deque *d)
{
    d->front = d->rear = -1;
}

int isFull(struct deque *d)
{
    return ((d->front == 0 && d->rear == MAX - 1) || d->front == d->rear + 1);
}

int isEmpty(struct deque *d)
{
    return (d->front == -1);
}

void insertFront(struct deque *d, int element)
{
    if (isFull(d))
    {
        printf("Deque is full!\n");
        return;
    }
    if (d->front == -1)
    {
        d->front = d->rear = 0;
    }
    else if (d->front == 0)
    {
        d->front = MAX - 1;
    }
    else
    {
        d->front--;
    }
    d->arr[d->front] = element;
}

void insertRear(struct deque *d, int element)
{
    if (isFull(d))
    {
        printf("Deque is full!\n");
        return;
    }
    if (d->front == -1)
    {
        d->front = d->rear = 0;
    }
    else if (d->rear == MAX - 1)
    {
        d->rear = 0;
    }
    else
    {
        d->rear++;
    }
    d->arr[d->rear] = element;
}

void deleteFront(struct deque *d)
{
    if (isEmpty(d))
    {
        printf("Deque is empty!\n");
        return;
    }
    if (d->front == d->rear)
    {
        d->front = d->rear = -1;
    }
    else if (d->front == MAX - 1)
    {
        d->front = 0;
    }
    else
    {
        d->front++;
    }
}

void deleteRear(struct deque *d)
{
    if (isEmpty(d))
    {
        printf("Deque is empty!\n");
        return;
    }
    if (d->front == d->rear)
    {
        d->front = d->rear = -1;
    }
    else if (d->rear == 0)
    {
        d->rear = MAX - 1;
    }
    else
    {
        d->rear--;
    }
}

void display(struct deque *d)
{
    if (isEmpty(d))
    {
        printf("Deque is empty!\n");
        return;
    }
    int i = d->front;
    printf("Deque elements: ");
    if (d->front <= d->rear)
    {
        while (i <= d->rear)
            printf("%d ", d->arr[i++]);
    }
    else
    {
        while (i < MAX)
            printf("%d ", d->arr[i++]);
        i = 0;
        while (i <= d->rear)
            printf("%d ", d->arr[i++]);
    }
    printf("\n");
}

int main()
{
    struct deque d;
    int choice, element;
    initialize(&d);

    do
    {
        printf("\n1. Insert at front\n2. Insert at rear\n");
        printf("3. Delete from front\n4. Delete from rear\n");
        printf("5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &element);
            insertFront(&d, element);
            break;
        case 2:
            printf("Enter element: ");
            scanf("%d", &element);
            insertRear(&d, element);
            break;
        case 3:
            deleteFront(&d);
            break;
        case 4:
            deleteRear(&d);
            break;
        case 5:
            display(&d);
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}