#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 50

// Structure for Stack
struct Stack
{
    char items[MAX];
    int top;
};

// Structure for Queue
struct Queue
{
    char items[MAX];
    int front, rear;
};

// Stack operations
void initStack(struct Stack *s)
{
    s->top = -1;
}

void push(struct Stack *s, char c)
{
    if (s->top < MAX - 1)
        s->items[++(s->top)] = c;
}

char pop(struct Stack *s)
{
    if (s->top >= 0)
        return s->items[(s->top)--];
    return '\0';
}

// Queue operations
void initQueue(struct Queue *q)
{
    q->front = q->rear = -1;
}

void enqueue(struct Queue *q, char c)
{
    if (q->rear < MAX - 1)
    {
        if (q->front == -1)
            q->front = 0;
        q->items[++(q->rear)] = c;
    }
}

char dequeue(struct Queue *q)
{
    if (q->front <= q->rear && q->front != -1)
        return q->items[(q->front)++];
    return '\0';
}

int main()
{
    struct Stack stack;
    struct Queue queue;
    char str[MAX];
    int i, isPalindrome = 1;

    initStack(&stack);
    initQueue(&queue);

    printf("Enter a string: ");
    gets(str);

    // Loading characters into stack and queue
    for (i = 0; str[i] != '\0'; i++)
    {
        push(&stack, str[i]);
        enqueue(&queue, str[i]);
    }

    // Comparing characters from stack and queue
    while (stack.top >= 0)
    {
        if (pop(&stack) != dequeue(&queue))
        {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome)
        printf("\nThe string is a palindrome");
    else
        printf("\nThe string is not a palindrome");

    getch();
    return 0;
}