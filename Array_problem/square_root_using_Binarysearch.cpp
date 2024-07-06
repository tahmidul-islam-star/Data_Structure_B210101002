#include <iostream>
#include <cmath>

using namespace std;
#define ll unsigned long long

int square_root(int x) {

    if (x == 0 || x == 1) return x;

    int low = 1;

    int high = x;

    int ans = 0;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        ll sq = static_cast<ll>(mid) * mid;

        if (sq == x) return mid;

        else if (sq < x) {

            low = mid + 1;

            ans = mid;

        } else {

            high = mid - 1;
        }
    }
    return ans;
}

int main() {

    int n;

    cin >> n;

    int res = square_root(n);

    cout << res << endl;

    return 0;
}
