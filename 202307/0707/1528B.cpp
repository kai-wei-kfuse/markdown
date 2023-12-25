#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1), sum(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            dp[j]++;
        }
    }
    sum[1] = dp[1];
    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i] + sum[i - 1]) % mod;
        sum[i] = (sum[i - 1] + dp[i]) % mod;
        //cout << dp[i] << endl;
    }
    cout << dp[n] << endl;
}