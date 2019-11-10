/* this is based on 4.4.c */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100
#define MAXVAL 100
#define BUFSIZE 100
#define NUMBER '0'

int getop(char []);
int getch(void);
void ungetch(int);
void push(double);
double pop(void);

void peek(void); // print the top of the stack
double peek_and_return(void); // return the top of the stack
void change(void); // switch the top two numbers on the stack
void clear_stack(void); // clear stack

int sp = 0; // index on the value stack
int bufp = 0;   // next free position
double val[MAXVAL]; // value stack
char buf[BUFSIZE];
double temp;

int main() {
    printf("enter number now:\n");
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                }
                else {
                    printf("error: can't divide by zero\n");
                }
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0) {
                    double op1 = pop();
                    op1 = (op1 < 0) ? op1 * -1 : op1;
                    while (op1 > op2) {
                        op1 -= op2;
                    }
                    push(op1);
                }
                else {
                    printf("error: cannot mod by zero.\n");
                }
                break;
            case '^':
                op2 = pop();
                push(pow(pop(), op2));
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("unknown command\n");
                break;
        }
    }
    return 0;
}

void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    }
    else {
        printf("stack full\n");
    }
}

double pop(void) {
    if (sp > 0) {
        return val[--sp];
    }
    else {
        printf("stack empty\n");
        return 0;
    }
}

int getop(char s[]) {
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    if (!isdigit(c) && c != '.') {
        return c; // not a number
    }

    i = 0;
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch()));
    }
    if (c == '.') {
        while (isdigit(s[++i] = c = getch()));
    }

    s[i] = '\0';
    if (c != EOF) {
        ungetch(c);
    }
    return NUMBER;
}

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {   // push character back on input
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters.\n");
    }
    else {
        buf[bufp++] = c;
    }
}

void peek(void) {
    if (sp > 0) {
        temp = pop();
        printf("Top of the stack: %f\n", temp);
        push(temp);
    }
    else {
        printf("error: can't peek stack is empty\n");
    }
}

double peek_and_return(void) {
    if (sp > 0) {
        temp = pop();
        push(temp);
        return temp;
    }
    else {
        printf("error: can't peek stack is empty\n");
        return -1;
    }
}

void change(void) {
    if (sp > 1) {
        double first = pop();
        double second = pop();
        push(first);
        push(second);        
    }
    else {
        printf("error: there aren't enough numbers to change\n");
    }
}

void clear_stack() {
    sp = 0;
}