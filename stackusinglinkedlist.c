#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

// Function to push an element onto the stack
void push(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Stack Overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("Pushed %d onto the stack\n", value);
}

// Function to pop an element from the stack
void pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }
    struct Node *temp = top;
    printf("Popped element: %d\n", temp->data);
    top = top->next;
    free(temp);
}

// Function to peek at the top element of the stack
void peek()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element is: %d\n", top->data);
}

// Function to display the stack
void display()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    struct Node *temp = top;
    printf("Stack elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting program\n");
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}