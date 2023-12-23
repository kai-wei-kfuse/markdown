#include <bits/stdc++.h>
using namespace std;

#define int long long

int tt[] = {0, 2, 3, 1};

signed main() {
    // vector<int> vis(1e6);
    // for (int i = 1; i <= 10000; i++) {
    //     if (vis[i] == 0) {
    //         for (int j = i + 1; j <= 10000; j++) {
    //             int flag = 0;
    //             for (int k = j + 1; k <= 10000; k++) {
    //                 if (vis[j] == 0 && vis[k] == 0 && ((i ^ j ^ k) == 0)) {
    //                     vis[i] = 1;
    //                     vis[j] = 1;
    //                     vis[k] = 1;
    //                     flag = 1;
    //                     cout << i << " " << j << " " << k << endl;
    //                     break;
    //                 }
    //             }
    //             if (flag)
    //                 break;
    //         }
    //     }
    // }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m = (n + 3 - 1) / 3;
        //cout << m << endl;
        int tmp = m;
        int st = 1;
        while (tmp > 0) {
            tmp -= st;
            st <<= 2;
        }
        st >>= 2;
        tmp += st;
        tmp--;
        // cout <<tmp<<' '<< st << endl;
        int fir = tmp + st;
        vector<int> idx;
        int a = tmp, b = st / 4;
        while (b >= 4) {
            idx.push_back(a / b);
            a %= b;
            b >>= 2;
        }
        idx.push_back(a);
        // cout << "idx:";
        // for(auto i:idx)
        //     cout << i << ' ';
        // cout << endl;
        // cout<<"tt:";
        // for(auto i:idx)
        //     cout << tt[i] << ' ';
        // cout << endl;
        int c = st;
        // cout << c << endl;
        int sec = (c << 1);
        for (auto i : idx) {
            c >>= 2;
            // cout<<c<<' ';
            sec += tt[i] * c;
        }
        // sec--;
        int trd = fir ^ sec;
        // cout << endl;
        // cout << fir << ' ' << sec << ' ' << trd << endl;
        vector<int> ans;
        ans.push_back(trd);
        ans.push_back(fir);
        ans.push_back(sec);
        cout << ans[n % 3] << endl;
    }
}