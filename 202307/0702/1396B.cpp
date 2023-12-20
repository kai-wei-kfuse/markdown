#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        int flag = 0;
        cin >> n;
        if (n == 1) flag = 1;
        vector<int> ve(n + 1);
        int maxn = 0;
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
            maxn = max(maxn, ve[i]);
        }
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += ve[i];
        }
        sum -= maxn;
        
        if (maxn > sum) {
            flag = 1;
        }
        else{
            sum+=maxn;
            if(sum%2==1) flag=1;
        }
        if (flag == 1)
            cout << "T" << endl;
        else
            cout << "HL" << endl;
    }
}