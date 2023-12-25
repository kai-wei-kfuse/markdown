#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        double d, h;
        cin >> n >> d >> h;
        vector<int> ve(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
        }
        double ans = d * h * n;
        double tmp = 0;
        for (int i = 2; i <= n; i++) {
            if (ve[i] - ve[i - 1] <= h)
                tmp += d * (h - (ve[i] - ve[i - 1])) *
                       (h - (ve[i] - ve[i - 1])) / h;
        }
        ans -= tmp;
        // cout << ans << endl;
        // cout << tmp << endl;
        cout << fixed << setprecision(7) << ans / 2.0 << '\n';
    }
}