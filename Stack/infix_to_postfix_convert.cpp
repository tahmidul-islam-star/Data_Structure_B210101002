#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

string postfix = "";

struct stak {

    int siz;

    int top;

    char *arra;
};

void push(struct stak* ptr, char c) {

    ptr->top++;

    ptr->arra[ptr->top] = c;
}

char pop(struct stak* ptr) {

    char c = ptr->arra[ptr->top];

    ptr->top--;

    return c;
}

bool Empty(struct stak* ptr) {

   if(ptr->top == -1) return true;

   return false;
}

char stakTop(struct stak* ptr) {

    return ptr->arra[ptr->top];
}

int prec(char c) {

    if (c == '^') return 3;

    else if (c == '/' || c == '*') return 2;

    else if (c == '+' || c == '-') return 1;

    else return 0;

}
char associat(char c) {

    if (c == '^') return 'R';

    else return 'L';
}

int main() {

    string infix = "a+b*(c^d-e)^(f+g*h)-i";

    struct stak* sp = (struct stak*)malloc(sizeof(struct stak));

    sp->siz = infix.size();

    sp->top = -1;

    sp->arra = (char*)malloc(sp->siz * sizeof(char));

    for (int i = 0; i < infix.size(); i++) {

        if ((infix[i])>='a' && infix[i]<='z' || infix[i]>='A' && infix[i]<='Z') {

            postfix += infix[i];

        } else if (infix[i] == '(') {

            push(sp, infix[i]);

        } else if (infix[i] == ')') {

            while (stakTop(sp) != '(') {

                postfix += pop(sp);
            }
             pop(sp);// remove left parenthesis

        } else {

            while (!Empty(sp) && prec(infix[i]) <= prec(stakTop(sp)) && associat(infix[i]) == 'L') {

                postfix += pop(sp);
            }
            push(sp, infix[i]); // higher precedence
        }
    }

    while (!Empty(sp)) {

        postfix += pop(sp);
    }

    cout << postfix << endl;

    free(sp->arra);

    free(sp);

    return 0;
}
