#include <bits/stdc++.h>
using namespace std;

const int post = 2e4 + 10;
const int mod = 998244353;
const int N = 1e3 + 10;
vector<vector<int> > dp(N, vector<int>(post * 2, 0));

int main() {
    int n;
    cin >> n;
    vector<int> ve(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            (dp[i][ve[i] - ve[j] + post] += dp[j][ve[i] - ve[j] + post] + 1) %= mod;
            (ans += dp[j][ve[i] - ve[j] + post] + 1) %= mod;
        }
    }
    cout << (ans + n) % mod << endl;
}