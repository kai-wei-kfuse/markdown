#include <bits/stdc++.h>
using namespace std;

#define int long long
bool cmp(pair<int, int> i, pair<int, int> j) {
    return i.first > j.first;
}

signed main() {
    int n, m;
    cin >> n >> m;
    multiset<int> se;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        se.emplace(tmp);
        ans+=tmp;
    }
    vector<int> vis(n + 1, 0);
    vector<pair<int, int> > vv(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> vv[i].second;
    }
    for (int i = 1; i <= m; i++) {
        cin >> vv[i].first;
    }
    sort(vv.begin() + 1, vv.end(),cmp);
    for (int i = 1; i <= m; i++) {
        auto [d,l]=vv[i];
        auto x = se.lower_bound(l);
        if(x==se.end())continue;
        else{
            ans-=d;
            se.erase(x);
        }
    }

    cout << ans << endl;
}