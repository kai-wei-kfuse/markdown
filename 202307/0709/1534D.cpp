#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    vector<int> odd, even;
    cin >> n;
    vector<int> edge[n + 1];
    cout << "? " << 1 << endl;
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp == 1) {
            edge[1].push_back(i);
        }
        if ((tmp & 1) && i != 1) {
            odd.push_back(i);
        } else if (i != 1) {
            even.push_back(i);
        }
    }
    // cout << odd.size() << " " << even.size() << endl;
    if (odd.size() > even.size()) {
        for (auto x : even) {
            cout << "? " << x << endl;
            // cout << "???" << endl;
            for (int i = 1; i <= n; i++) {
                // cout << "???" << endl;
                int tmp;
                cin >> tmp;
                if (tmp == 1) {
                    edge[x].push_back(i);
                }
            }
        }
        cout << "!" << endl;
        for (int i = 1; i <= n; i++) {
            for (auto j : edge[i]) {
                cout << i << ' ' << j << endl;
            }
        }
    } else {
        for (auto x : odd) {
            cout << "? " << x << endl;
            // cout << "????" << endl;
            for (int i = 1; i <= n; i++) {
                int tmp;
                cin >> tmp;
                if (tmp == 1 && i != 1) {
                    // cout << x << ' ' << i << endl;
                    edge[x].push_back(i);
                }
            }
        }
        cout << "!" << endl;
        for (int i = 1; i <= n; i++) {
            for (auto j : edge[i]) {
                cout << i << ' ' << j << endl;
            }
        }
    }
}