#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

struct xx {
    int n, t, id;
};

bool cmp(xx a, xx b) {
    if (a.n == b.n) {
        if (a.t == b.t) {
            return a.id < b.id;
        }
        return a.t < b.t;
    }
    return a.n > b.n;
}

signed main() {
    ios;
    int t;
    cin >> t;
    while (t--) {
        int n, m, tt;
        cin >> n >> m >> tt;
        vector<xx> ve(n + 1);
        for (int i = 1; i <= n; i++) {
            vector<int> tmp;
            for (int j = 1; j <= m; j++) {
                int x;
                cin >> x;
                tmp.push_back(x);
            }
            sort(tmp.begin(), tmp.end());
            int sum = 0, num = 0, pant = 0;
            for (auto i : tmp) {
                if (sum + i <= tt) {
                    sum += i;
                    pant += sum;
                    num++;
                } else {
                    break;
                }
            }
            ve[i] = {num, pant, i};
        }
        sort(ve.begin() + 1, ve.end(), cmp);
        for (int i = 1; i <= n; i++) {
            if (ve[i].id == 1) {
                cout << i << '\n';
                break;
            }
        }
    }
}