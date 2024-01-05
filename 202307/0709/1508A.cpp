#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a, b, c;
        cin >> a >> b >> c;
        int z1 = 0, z2 = 0, z3 = 0;
        for (int i = 0; i < 2 * n; i++) {
            if (a[i] == '0')
                z1++;
            if (b[i] == '0')
                z2++;
            if (c[i] == '0')
                z3++;
        }
        vector<char> ans[n + 1];
        string f, s;
        int flag = 0;
        if (z1 >= n && z2 >= n) {
            f = a, s = b;
        } else if (z1 >= n && z3 >= n) {
            f = a, s = c;
        } else if (z2 >= n && z3 >= n) {
            f = b, s = c;
        } else if (z1 < n && z2 < n) {
            f = a, s = b;
            flag = 1;
        } else if (z1 < n && z3 < n) {
            f = a, s = c;
            flag = 1;
        } else if (z2 < n && z3 < n) {
            f = b, s = c;
            flag = 1;
        }
        int x = 0;
        char tmp = '0';
        if (flag) {
            tmp = '1';
        }
        for (auto i : f) {
            if (x == n) {
                ans[x].push_back(i);
            } else {
                if (i == tmp) {
                    x++;
                } else {
                    ans[x].push_back(i);
                }
            }
        }
        x = 0;
        for (auto i : s) {
            if (x == n) {
                ans[x].push_back(i);
            } else {
                if (i == tmp) {
                    x++;
                } else {
                    ans[x].push_back(i);
                }
            }
        }

        for (int i = 0; i <= n; i++) {
            for (auto j : ans[i]) {
                cout << j;
            }
            if (i < n)
                cout << flag;
        }
        cout << endl;
    }
}