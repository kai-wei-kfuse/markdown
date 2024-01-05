#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        map<int, int> mp;
        vector<int> ve(n + 1);
        for (int i = 1; i <= n;i++){
            cin >> ve[i];
            mp[ve[i]]++;
        }
        ve.erase(unique(ve.begin(), ve.end()));
        int ans = 0;
        
    }
}