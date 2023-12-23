#include <bits/stdc++.h>
using namespace std;

struct xx {
    int i, j, x;
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ve(n + 1);
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
            sum += ve[i];
        }
        if (sum % n != 0) {
            cout << "-1" << endl;
            continue;
        }
        int dit = sum / n;
        vector<xx> ans;
        for (int i = 2; i <= n; i++) {
            if (ve[i] % i == 0) {
                ans.push_back({i, 1, ve[i] / i});
                ve[1] += ve[i];
                ve[i] -= ve[i];
            } else {
                ans.push_back({1, i, i - ve[i] % i});
                ve[1] -= i - ve[i] % i;
                ve[i] += i - ve[i] % i;
                ans.push_back({i, 1, ve[i] / i});
                ve[1] += ve[i];
                ve[i] -= ve[i];
            }
        }
        // for (int i = 1; i <= n; i++) {
        //     cout << ve[i] << ' ';
        // }
        // cout << endl;
        int flag = 0;
        for (int i = 2; i <= n; i++) {
            ans.push_back({1, i, dit});
            ve[1] -= dit;
            ve[i] += dit;
        }
        // for (int i = 1; i <= n; i++) {
        //     cout << ve[i] << ' ';
        // }
        // cout << endl;
        if (flag) {
            cout << "-1" << endl;
        } else {
            cout << ans.size() << endl;
            for (auto [i, j, x] : ans) {
                cout << i << ' ' << j << ' ' << x << endl;
            }
        }
    }
}