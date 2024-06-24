#include<iostream>
#include<stdlib.h>
#include<cstring>

using namespace std;
#define improve ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

struct stak
{
    int siz;

    int top;

    char *arra;
};
int isEmpty(struct stak* ptr)
{
    if(ptr->top == -1) return 1;

    return 0;
}
void pus(struct stak* ptr,char c)
{
    ptr->top++;

    ptr->arra[ptr->top]=c;
}
char pop(struct stak *p)
{

        char temp = p->arra[p->top];

        p->top--;

        return temp;

}
bool matching(char a,char b)
{
    if(a== '(' and b == ')' ) return true;

    else if(a== '{' and b== '}') return true;

    else if(a=='[' and b== ']') return true;

    else return false;
}
int main()
{
    string s;cin>>s;

    bool p= true;

    struct stak * sp= (struct stak*) malloc(sizeof(struct stak));

    sp->siz = s.size();

    sp->top =-1;

    sp->arra=(char *) malloc(sp->siz* sizeof(char));

    for(int i=0;i<s.size();i++){

        if(s[i]=='(' || s[i]=='{' || s[i]=='['){

            pus(sp,s[i]);
           }
           else if(s[i]==')' || s[i]=='}' || s[i]==']'){

            if(isEmpty(sp)) {

                p= false;

                break;
            }
            else{

                char ch= pop(sp);

                if(!matching(ch,s[i])){

                    p= false;

                    break;
                }

            }

           }
    }
    if(p and isEmpty(sp)) cout<<"Yes"<<endl;

    else cout<<"No"<<endl;

    return 0;
}
