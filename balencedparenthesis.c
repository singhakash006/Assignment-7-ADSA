#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *next;
};

struct Node *push(struct Node *top, char data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = top;
    return newNode;
}

struct Node *pop(struct Node *top)
{
    if (top == NULL)
        return NULL;
    struct Node *temp = top;
    top = top->next;
    free(temp);
    return top;
}

int isMatchingPair(char opening, char closing)
{
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

int isBalanced(char expr[])
{
    struct Node *stack = NULL;

    for (int i = 0; expr[i] != '\0'; i++)
    {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[')
        {
            stack = push(stack, expr[i]);
        }
        else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']')
        {
            if (stack == NULL)
                return 0;
            if (!isMatchingPair(stack->data, expr[i]))
                return 0;
            stack = pop(stack);
        }
    }
    return stack == NULL;
}

void main()
{
    char expr[100];

    printf("Enter an expression: ");
    gets(expr);

    if (isBalanced(expr))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    getch();
}