#include<bits/stdc++.h>
using namespace std;
int main(){
    int last=0;
    int flag = 0;
    for (int i = 1; i <= 8; i++){
        int tmp;
        cin >> tmp;
        if (last>tmp){
            flag = 1;
            break;
        }
        if(tmp%25!=0){
            flag = 1;
            break;
        }
        if(tmp<100||tmp>675){
            flag = 1;
            break;
        }
        last = tmp;
    }
    if(flag){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
}