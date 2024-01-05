#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    for (int i = 2; i <= 1e6; i++) {
        int cnt = 1;
        int pos = i;
        cnt += pos;
        pos *= i;
        while (cnt + pos <= 1e18) {
            cnt += pos;
            cout << cnt << ' ';
            pos *= i;
        }
        cout << endl;
    }
    return 0;
}