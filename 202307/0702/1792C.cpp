#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<int >pos(n + 1);
        for (int i = 1; i <= n;i++){
            int tmp;
            cin >> tmp;
            pos[tmp] = i;
        }
        int ans = n/2;
        for (int i = n/2; i >=1;i--){
            if(pos[n-i+1]-pos[i]>=n-i+1-i&&pos[n-i]<pos[n-i+1]&&pos[i]<pos[i+1]){
                ans--;
            }else{
                break;
            }
        }
        cout << ans << endl;
    }
}