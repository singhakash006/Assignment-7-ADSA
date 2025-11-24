#include <stdio.h>
#include <conio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push()
{
    int item;
    if (top == MAX - 1)
    {
        printf("\nStack Overflow!");
    }
    else
    {
        printf("\nEnter element to push: ");
        scanf("%d", &item);
        top++;
        stack[top] = item;
        printf("\nItem pushed successfully!");
    }
}

void pop()
{
    if (top == -1)
    {
        printf("\nStack Underflow!");
    }
    else
    {
        printf("\nPopped element: %d", stack[top]);
        top--;
    }
}

void display()
{
    if (top == -1)
    {
        printf("\nStack is empty!");
    }
    else
    {
        printf("\nStack elements are:\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n\nStack Operations:");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
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