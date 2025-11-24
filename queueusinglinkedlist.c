#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *front, *rear;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty queue
struct Queue *createQueue()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to add an element to the queue (enqueue)
void enqueue(struct Queue *queue, int data)
{
    struct Node *newNode = createNode(data);

    if (queue->rear == NULL)
    {
        queue->front = queue->rear = newNode;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
}

// Function to remove an element from the queue (dequeue)
int dequeue(struct Queue *queue)
{
    if (queue->front == NULL)
    {
        printf("\nQueue is empty!");
        return -1;
    }

    struct Node *temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;

    if (queue->front == NULL)
        queue->rear = NULL;

    free(temp);
    return data;
}

// Function to display the queue
void display(struct Queue *queue)
{
    if (queue->front == NULL)
    {
        printf("\nQueue is empty!");
        return;
    }

    struct Node *temp = queue->front;
    printf("\nQueue elements are: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    struct Queue *queue = createQueue();
    int choice, value;

    do
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
            enqueue(queue, value);
            break;

        case 2:
            value = dequeue(queue);
            if (value != -1)
                printf("\nDequeued value: %d", value);
            break;

        case 3:
            display(queue);
            break;

        case 4:
            printf("\nExiting...");
            break;

        default:
            printf("\nInvalid choice!");
        }
    } while (choice != 4);

    return 0;
}