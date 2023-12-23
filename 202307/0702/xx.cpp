#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, minn, maxn;
    cin >> n >> minn >> maxn;
    vector<int> ve(n + 1);
    for (int i = 0; i <= n; i++) {
        cin >> ve[i];
    }
    deque<int> q;
    vector<int> dp(n + 1, -1e9);
    dp[0] = 0;
    for (int i = minn; i <= n; i++) {
        while (!q.empty() && dp[q.back()] < dp[i - minn]) {
            q.pop_back();
        }
        q.push_back(i - minn);
        while (!q.empty() && q.front() < i - maxn) {
            q.pop_front();
        }
        int qrm;
        if (q.size())
            qrm = q.front();
        else {
            qrm = 0;
        }
        dp[i] = ve[i] + dp[qrm];
    }
    int ans = -1e9;
    for (int i = n - maxn + 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}