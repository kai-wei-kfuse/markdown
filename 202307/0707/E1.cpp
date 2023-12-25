#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    vector<int> ans(1e6 + 5);
    for (int i = 2; i <= 1000; i++) {
        int cnt = 1;
        int pos = i;
        cnt += pos;
        pos *= i;
        while (cnt + pos <= 1e6) {
            cnt += pos;
            ans[cnt] = 1;
            pos *= i;
        }
    }
    // cout << "x" << endl;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (ans[n]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}