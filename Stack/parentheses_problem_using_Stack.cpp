#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

struct stak {

    int siz;

    int top;

    char* arra;
};

int isEmpty(struct stak* ptr) {

    if (ptr->top == -1) return 1;

    return 0;
}

void pus(struct stak* ptr, char c) {

    ptr->top++;

    ptr->arra[ptr->top] = c;
}

void pop(struct stak* ptr) {

    if (ptr->top == -1) {

        return;
    }
    ptr->top--;
}
bool Check(string s)
{
     struct stak* sp = (struct stak*)malloc(sizeof(struct stak));

    sp->siz = s.size();

    sp->top = -1;

    sp->arra = (char*)malloc(sp->siz * sizeof(char));

    bool balanced = true;

    for (int i = 0; i < s.size(); i++) {

        if (s[i] == '(') {

            pus(sp, s[i]);

        } else if (s[i] == ')') {

            if (isEmpty(sp)) {

                balanced = false;

                break;

            } else {

                pop(sp);
            }
        }
    }
    if (balanced && isEmpty(sp)) {

        return true;

    } else {

       return false;
    }
}
int main() {

    string s; cin >> s;

   bool ans= Check(s);

  if(ans) cout<<"Yes"<<endl;

  else cout<<"NO"<<endl;

    return 0;
}
