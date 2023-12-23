#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> ve(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
        pre[i] = pre[i - 1] ^ ve[i];
    }
    if (n > 60) {
        cout << "1" << endl;
        return 0;
    }
    int ans = 1e9;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            for (int k = i; k <= n; k++) {
                if ((pre[i - 1] ^ pre[j - 1]) > (pre[i - 1] ^ pre[k])) {
                    ans = min(ans, i - j - 1 + k - i);
                }
            }
        }
    }
    if (ans == 1e9)
        cout << "-1" << endl;
    else
        cout << ans << endl;
}