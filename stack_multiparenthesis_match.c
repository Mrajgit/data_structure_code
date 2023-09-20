#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    char *arr;
};
// stack empty
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//stack full
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *ptr, char val)
{
    if (isFull(ptr))
    {
        printf("stack is full\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("stack is empty\n");
        return -1;
    }
    else
    {
        char a = ptr->arr[ptr->top];
        ptr->top--;
        return a;
    }
}
int match(char a, char b)
{
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}
int parenthesismatch(char *exp)
{
    struct stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char popped;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            else
            {
                popped = pop(sp);
                if (!match(popped, exp[i]))
                {
                    return 0;
                }
            }
        }
    }
    if (isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    char *exp = "4{34+2[34*45](45+1)}";
    if (parenthesismatch(exp))
    {
        printf("the multiparenthesis is matching");
    }
    else
    {
        printf("the multiparenthesis is not matching");
    }
    return 0;
}
