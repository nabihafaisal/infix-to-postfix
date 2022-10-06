#include <iostream>
#include <string.h>
using namespace std;

// Function to verify whether an operator has higher precedence over other
int precedence(char op)
{
    
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;

    else
        return 0;
}

int main()

{
    // Declaring a Stack 
    char stack[20];
    int top = -1;
    int j = 0;

    char infix[20];
    strcpy(infix, "(a+b)*(c-d)");
    // cin>>infix;

    char postfix[20];
    strcpy(postfix, " ");

    for (int i = 0; i < strlen(infix); i++)
    {
     // If the scanned character is an
        // ‘(‘, push it to the stack.

        if (infix[i] == '(')
        {
            stack[++top] = '(';
            continue;
        }
// If the scanned character is an ‘)’,
        // pop and to output string from the stack
        // until an ‘(‘ is encountered.
        if (infix[i] == ')')
        {
            while (stack[top] != '(')
            
                postfix[j++] = stack[top--];
            
            top--;
            continue;
        }
        /// operand
        //  if character is an operand
        if (precedence(infix[i]) == 0)
        {
            postfix[j++] = infix[i];
        }
        // operator
        else
        {
            /// if stack is empty or "(" is encountered at the very first of stack coming operator is pushed in stack
            if (stack[top] == '(' || top == -1)
            {
                stack[++top] = infix[i];
                continue;
            }
            // If character is operator, pop two elements from stack, perform operation and push the result back. 
            while (top != -1 && precedence(infix[i]) <= precedence(stack[top]))
                postfix[j++] = stack[top--];

            stack[++top] = infix[i];
        }
    }
    //emptying the stack
    while (top >= 0)

        postfix[j++] = stack[top--];
    postfix[j++] = '\0';
    printf("%s", postfix);
}