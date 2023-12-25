#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> ve(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
        }
        vector<int> ans;
        for (int i = 2; i <= n; i++) {
            ans.push_back(abs(ve[i] - ve[i - 1]));
        }
        sort(ans.begin(), ans.end());
        int sum = 0;
        for (int i = 0; i < n - k; i++) {
            sum += ans[i];
        }
        cout << sum << endl;
    }
}