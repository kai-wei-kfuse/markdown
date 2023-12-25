#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ve(n + 1), pre(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
            pre[i] = (pre[i - 1] ^ ve[i]);
        }
        int ans = 0;
        set<int> se;
        se.insert(0);
        for (int i = 1; i <= n; i++) {
            for (auto j : se)
                ans = max(ans, pre[i] ^ j);
            se.insert(pre[i]);
        }
        cout << ans << '\n';
    }
}