#include<iostream>
#include<cmath>

using namespace std;

static int coun=0;

void Tower_of_Hanoi(int n, char Beg, char Aux, char End)
{
    if (n == 0) return;

    if (n == 1)
    {
        coun++;

        cout << Beg << "->" << End << endl;

        return;
    }

    Tower_of_Hanoi(n - 1, Beg, End, Aux);

    cout << Beg << "->" << End << endl;

    coun++;

    Tower_of_Hanoi(n - 1, Aux, Beg, End);
}
bool Check(int n,int total)
{
    // equation: from book page number 6.25
   // f(n) = 2^n-1 total step count

    int orginal= pow(2,n)-1;

    if(orginal==total) return true;

    else return false;
}

signed main()
{
    int n = 3;

    char Beg = 'A';

    char Aux = 'B';

    char End = 'C';

    Tower_of_Hanoi(n, Beg, Aux, End);

    cout << "Total steps: " << coun << endl;

    if(Check(n,coun)) cout<<"Successful"<<endl;

    else cout<<"No Wrong"<<endl;

    return 0;
}
