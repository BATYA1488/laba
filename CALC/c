#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>   /* for fmod() */

#define MAXOP 100  /* max size of operand or operator */
#define NUMBER '0' /* the sign of the number */

int getop (char []);
void push (double);
double pop (void);

/* a calculator with reverse Polish entry */
int main()
{
    int type;
    double op1, op2;
    char s[MAXOP];

    while ((type = getop (s)) != EOF) {
        switch (type) {
        case NUMBER:
            push (atof(s));
            break;
        case '+':
            push (pop() + pop());
            break;
        case '*':
            push (pop() * pop());
            break;
        case '-':
            op2 = pop();
            push (pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push (pop() / op2);
            else
                printf("error: division by zero\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0) {
                op1 = pop();
                push ( op1 - op2 * floor(op1 / op2) );
            }
            else
                printf("error: division by zero\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown operation %s\n", s);
            break;
        }
    }

    return 0;
}


#define MAXVAL 100  /* the maximum depth of the stack */

int sp = 0;         /* next free position in the stack */
double val[MAXVAL]; /* stack */

/* push: to put the value of F on the stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack is full, %g does not fit\n", f);
}

/* pop: take the top of the stack and give as a result */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf ("error: stack is empty\n");
    return 0.0;
    }
}


#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: gets the next operator or operand */
int getop(char s[])
{
    int i=0, c, t;
    while ((s[i] = c = getch()) == ' ' || c == '\t');
    if (!isdigit(c) && c != '.'){
        if (c == '-') {
            if (isdigit(t = getch()) || t == '.') {
                c = t;
                s[++i] = c;
            }
            else {
                ungetch(t);
                return c;  /* not a number */
            }
        }
        else {
            return c;      /* not a number */
        }
    }
    if (isdigit(c)) /* accumulate the integer part */
        while (isdigit(s[++i] = c = getch()));
    if (c =='.')    /* accumulate the integer part */
        while (isdigit(s[++i] = c = getch()));
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}


#define BUFSIZE 100

char buf[BUFSIZE];    /* buffer for ungetch */
int bufp = 0;         /* next free position in buffer */

int getch(void)       /* to take (possibly returned) symbol */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)   /* to return the symbol to enter, zubrilin*/
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
