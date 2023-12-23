#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, minn, maxn;
    cin >> n >> minn >> maxn;
    vector<int> ve(n + 1);
    for (int i = 0; i <= n; i++) {
        cin >> ve[i];
    }
    //deque<int> q;
    //cout << "xx" << endl;
    vector<int> dp(n + 1,-1e9);
    dp[0] = 0;
    vector<int> q(n + 1);
    int ll = 0, rr = -1;
    for (int i = minn; i <= n; i++) {
        // int qrm;
        // if (q.empty()) {
        //     qrm = 0;
        // } else
        //     q.front();
        // cout << qrm << ' '<<q.size()<<' ';
        // dp[i] = ve[i] + dp[qrm];
        // cout << dp[i] << endl;
        // while (!q.empty() && q.front() < i - maxn) {
        //     q.pop_front();
        // }
        // while (!q.empty() && dp[q.back()] < dp[i - minn]) {
        //     q.pop_back();
        // }
        // q.push_back(i - minn);
        
        while (ll <= rr && dp[q[rr]] < dp[i - minn]) {
            rr--;
        }
        q[++rr] = i - minn;
        while (ll <= rr && q[ll] < i - maxn) {
            ll++;
        }
        dp[i] = ve[i] + dp[q[ll]];
    }
    int ans = -1e9;
    for (int i = n - maxn + 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}