#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> ve(n + 1), pre(n + 1);
        int flag = 0;
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
            if (ve[i] == k) flag = 1;
            if (ve[i] >= k)
                ve[i] = 1;
            else
                ve[i] = 0;
            pre[i] = pre[i - 1] + ve[i];
        }
        if (flag == 0) {
            cout << "no" << endl;
            continue;
        }
        if (n == 1 && ve[1] == 1) {
            cout << "yes" << endl;
            continue;
        }

        int flag2 = 0;
        for (int i = 2; i <= n; i++) {
            if (pre[i] - pre[i - 2] == 2) {
                flag2 = 1;
                break;
            }
            if (i >= 3 && pre[i] - pre[i - 3] == 2) {
                flag2 = 1;
                break;
            }
        }
        if (flag2 == 0)
            cout << "no" << endl;
        else
            cout << "yes" << endl;
    }
}