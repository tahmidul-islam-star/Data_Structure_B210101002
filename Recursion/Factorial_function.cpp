#include<iostream>
#include<cstdlib>

using namespace std;

#define int long long
#define improve ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

int factorial(int n)
{
    if(n==0) return 1;

    else return n*factorial(n-1);
}
signed main()
{
    improve;

    int num;cin>>num;

    int fact_num= factorial(num);

    cout<<fact_num<<endl;

    return 0;
}
