#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if (top == -1)
        return -1;
    return stack[top--];
}

int priority(char x) {
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    if (x == '^')
        return 3;
    return 0;
}

void infixToPostfix(char infix[]) {
    char postfix[MAX];
    int i = 0, j = 0;
    char x;

    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while ((x = pop()) != '(') {
                postfix[j++] = x;
            }
        } else {
            while (priority(stack[top]) >= priority(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
    printf("Postfix Expression: %s\n", postfix);
}

void reverse(char str[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void infixToPrefix(char infix[]) {
    char temp[MAX];
    strcpy(temp, infix);

    reverse(temp);

    for (int i = 0; temp[i]; i++) {
        if (temp[i] == '(')
            temp[i] = ')';
        else if (temp[i] == ')')
            temp[i] = '(';
    }

    top = -1;
    char postfix[MAX];
    int i = 0, j = 0;
    char x;

    while (temp[i] != '\0') {
        if (isalnum(temp[i])) {
            postfix[j++] = temp[i];
        } else if (temp[i] == '(') {
            push(temp[i]);
        } else if (temp[i] == ')') {
            while ((x = pop()) != '(') {
                postfix[j++] = x;
            }
        } else {
            while (priority(stack[top]) >= priority(temp[i])) {
                postfix[j++] = pop();
            }
            push(temp[i]);
        }
        i++;
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    reverse(postfix);
    printf("Prefix Expression: %s\n", postfix);
}

int main() {
    char exp[MAX];
    int choice;

    while (1) {
        printf("\n--- Expression Conversion App ---\n");
        printf("1. Infix to Postfix\n");
        printf("2. Infix to Prefix\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            top = -1;
            printf("Enter Infix Expression: ");
            scanf("%s", exp);
            infixToPostfix(exp);
            break;

        case 2:
            top = -1;
            printf("Enter Infix Expression: ");
            scanf("%s", exp);
            infixToPrefix(exp);
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
