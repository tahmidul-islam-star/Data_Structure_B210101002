#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#define endl '\n'

struct stak {

    int siz;

    int top;

    int *arra;
};

void push(struct stak* ptr, int item) {

    ptr->top++;

    ptr->arra[ptr->top] = item;

}

int pop(struct stak* p) {

    int temp = p->arra[p->top];

    p->top--;

    return temp;
}

int operation(int num1,int num2,char op)
{
    switch(op){

        case '+': return num2+num1;

        case '-': return num2-num1;

        case '*': return num2*num1;

        case '/': return num2/num1;
    }
}
int postfix_evaluation(string s)
{
    struct stak* sp = (struct stak*)malloc(sizeof(struct stak));

    sp->siz = s.size();

    sp->top = -1;

    sp->arra = (int*)malloc(sp->siz * sizeof(int));

    for (int i = 0; i < s.size(); i++) {

        if (isdigit(s[i])) {

            int num = 0;

            while (i < s.size() && isdigit(s[i])) {

             num = num * 10 + (s[i] - '0');

                i++;
            }
            push(sp, num);

           }
            else if (s[i] == ',') { continue; }

            else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {

            char c= s[i];

            int temp1 = pop(sp);

            int temp2 = pop(sp);

            int result=operation(temp1,temp2,c);

            push(sp,result);
        }
    }
    int result= pop(sp);

    return result;
}

int main() {

    string s = "5,6,2,+,*,12,4,/-";

    int result= postfix_evaluation(s);

    cout << "postfix result: " << result<< endl;

    return 0;
}
