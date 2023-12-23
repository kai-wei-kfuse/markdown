#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n;
    vector<int> st(7);
    for (int i = 1; i <= 6; i++) {
        cin >> st[i];
    }
    cin >> n;
    vector<int> ve(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
    }
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    vector<pair<int, int>> cnt;
    cnt.push_back(make_pair(0, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            cnt.push_back(make_pair(ve[i] - st[j], i));
        }
    }
    sort(cnt.begin(), cnt.end());
    // for (auto i : cnt) {
    //     cout << i.first << " ";
    // }
    // cout << endl;
    // for (auto i : cnt) {
    //     cout << i.second << " ";
    // }
    // cout << endl;
    int l = 0, r = 0;

    vector<int> vis(n + 1);
    int ans = 1e9;
    int num = 0;
    while (r <= 6 * n) {
        // cout << l << ' ' << r <<" "<<num<< endl;

        if (num == n) {
            ans = min(ans, cnt[r].first - cnt[l].first);
        }
        if (num < n || l == r) {
            r++;
            if (vis[cnt[r].second] == 0) {
                num++;
            }
            vis[cnt[r].second]++;
        } else {
            vis[cnt[l].second]--;
            if (vis[cnt[l].second] == 0) {
                num--;
            }
            l++;
        }
    }
    cout << ans << endl;
}