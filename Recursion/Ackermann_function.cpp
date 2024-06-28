#include <iostream>

using namespace std;

#define int long long
#define improve ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'

int Ackerman(int m, int n)
{
	if (m == 0){

    return n + 1;
	}
	else if(m > 0 && n == 0){

    return Ackerman(m - 1, 1);
	}
	else if(m > 0 && n > 0){

    return Ackerman(m - 1, Ackerman(m, n - 1));
	}
}
signed main()
{
	int A;

	A = Ackerman(1, 3);

	cout << A << endl;

	return 0;
}


