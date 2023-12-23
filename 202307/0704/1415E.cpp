#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, k;
    cin >> n >> k;
    vector<int> ve(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
    }
    sort(ve.begin() + 1, ve.end(), greater<int>());
    priority_queue<int,vector<int>,less<int>> q;
    for (int i = 1; i <= k + 1; i++) {
        q.push(0);
    }
    int ans = 0, inc = 0;
    for (int i = 1; i <= n; i++) {
        inc = q.top();
        //cout << inc << endl;
        q.pop();
        ans += inc;
        inc += ve[i];
        q.push(inc);
    }
    cout << ans << endl;
}