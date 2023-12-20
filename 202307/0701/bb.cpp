#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n, m;
    cin >> n >> m;
    vector<string > s(n + 1),ss(m+1);
    map<string, int> mp;
    for (int i = 1; i <= n;i++){
        cin >> s[i];
    }
    for (int i = 1; i <= m;i++){
        cin >> ss[i];
    }
    int p0;
    cin >> p0;
    for (int i = 1; i <= m;i++){
        int tmp;
        cin >> tmp;
        mp[ss[i]] = tmp;
    }
    int ans = 0;
    for (int i = 1; i <= n;i++){
        if(mp[s[i]]==0){
            ans+=p0;
        }
        ans += mp[s[i]];
    }
    cout << ans << endl;
}