#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ve(n + 1);
        int sum;
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
        }
        sum = ve[1];
        for (int i = 2; i <= n; i++) {
            sum = (sum & ve[i]);
        }
        if (sum != 0) {
            cout << "1" << endl;
        } else {
            int tmp = ve[1];
            int ans = 0;
            for (int i = 2; i <= n; i++) {
                if (tmp == 0 && tmp < n) {
                    ans++;
                    tmp = ve[i];
                    continue;
                }
                tmp &= ve[i];
               // cout << tmp << " ";
            }
            //cout << n << '?' << endl;
            if (tmp != 0) {
                cout << ans << endl;
            } else {
                cout << ans + 1 << endl;
            }
        }
    }
}