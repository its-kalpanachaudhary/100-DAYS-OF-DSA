#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

int main() {
    char infix[SIZE], postfix[SIZE];
    int i, k = 0;

    scanf("%s", infix);

    for(i = 0; infix[i] != '\0'; i++) {

        // Operand
        if(isalnum(infix[i])) {
            postfix[k++] = infix[i];
        }

        // Left parenthesis
        else if(infix[i] == '(') {
            push(infix[i]);
        }

        // Right parenthesis
        else if(infix[i] == ')') {
            while(top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); 
        }

        // Operator
        else {
            while(top != -1 && precedence(peek()) >= precedence(infix[i])) {
                postfix[k++] = pop();
            }
            push(infix[i]);
        }
    }

    while(top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';

    printf("%s", postfix);

    return 0;
}