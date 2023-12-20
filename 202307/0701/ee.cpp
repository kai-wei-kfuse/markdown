#include<bits/stdc++.h>
using namespace std;

#define int long long

int mexn[4][4][4];

int mex(int i,int j,int k){
    for (int x = 0; x <= 3;x++){
        if(x!=i&&x!=j&&x!=k){
            return x;
        }
    }
    return 3;
}

void init(){
    for (int i = 0; i <= 2;i++){
        for (int j = 0; j <= 2;j++){
            for (int k = 0; k <= 2;k++){
                //cout<<i<<" "<<j<<" "<<k<<" "<<mex(i,j,k)<<endl;
                mexn[i][j][k] = mex(i,j,k);
            }
        }
    }
}

signed main(){
    int n;
    cin >> n;
    init();
    vector<int > v(n+1);
    string s;
    for (int i = 1;i<=n;i++){
        cin>>v[i];
    }
    cin >> s;
    vector<map<int,int> >pre(n+2),suf(n+2);
   // cout << "xx" << endl;
    for (int i = 1; i <=n ;i++){
       // cout<<i<<endl;
        pre[i] = pre[i - 1];
        if(s[i-1]=='M'){
            pre[i][v[i]]++;
        }
    }
    for (int i = n; i >=1 ;i--){
        suf[i] = suf[i + 1];
        if(s[i-1]=='X'){
            suf[i][v[i]]++;
        }
    }
    //cout << "yy" << endl;
    int ans = 0;
    for (int i = 1; i < n-1;i++){
        if(s[i]=='E'){
            for(int j=0;j<=2;j++){
                for(int k=0;k<=2;k++){
                    ans+=pre[i][j]*suf[i+1][k]*mexn[j][k][v[i+1]];
                }
            }
        }
    }
    cout << ans << endl;
}