#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    map<__int128, int> ans;
    for (__int128 i = 2; i <= 1e6; i++) {
        __int128 cnt = 1;
        __int128 pos = i;
        cnt += pos;
        pos *= i;
        while (cnt + pos <= 1e18) {
            cnt += pos;
            ans[cnt] = 1;
            pos *= i;
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (ans[n]) {
            cout << "YES" << endl;
        } else {
            if (n > 1e12) {
                int p = (int)sqrt(n - 1);
                if (p * (p + 1) + 1 == n) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}