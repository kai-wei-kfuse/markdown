#include <bits/stdc++.h>
using namespace std;

#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

struct xx {
    int x, y, t;
};
vector<xx> ve(1e4 + 5);
vector<int> dp(1e4 + 5, 1);

inline int dist(xx a, xx b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int main() {
    ios;
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        cin >> ve[i].t >> ve[i].x >> ve[i].y;
        for (int j = 1; j < i; j++) {
            if (ve[i].t - ve[j].t >= dist(ve[i], ve[j])) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}