#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 50

struct stack
{
    char data[MAX];
    int top;
};

void init(struct stack *s)
{
    s->top = -1;
}

void push(struct stack *s, char c)
{
    if (s->top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    s->data[++(s->top)] = c;
}

char pop(struct stack *s)
{
    if (s->top == -1)
    {
        printf("Stack Underflow\n");
        return '\0';
    }
    return s->data[(s->top)--];
}

int main()
{
    struct stack s;
    char str[MAX];
    int i;

    init(&s);

    printf("Enter a string: ");
    gets(str);

    // Push each character to stack
    for (i = 0; str[i] != '\0'; i++)
    {
        push(&s, str[i]);
    }

    printf("Reversed string: ");
    // Pop and print each character
    while (s.top != -1)
    {
        printf("%c", pop(&s));
    }

    getch();
    return 0;
}