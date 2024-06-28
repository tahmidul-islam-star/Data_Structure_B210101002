#include<iostream>
#include<cstdlib>

using namespace std;

#define int long long
#define improve ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

int fibonacci(int n)
{
    // n= 0 or n= 1

    if(n <= 1) return n;

    else{

        // sum of the two previous terms

        return fibonacci(n-2)+fibonacci(n-1);
    }

}
signed main()
{
    improve;

    int num;cin>>num;

    int nth_fibnum= fibonacci(num);

    cout<<nth_fibnum<<endl;

    return 0;
}

