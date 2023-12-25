#include <bits/stdc++.h>
using namespace std;

int tt[] = {0, 2, 3, 1};

int main() {
    vector<int> vis(1e6);
    for (int i = 1; i <= 10000; i++) {
        if (vis[i] == 0) {
            for (int j = i + 1; j <= 10000; j++) {
                int flag = 0;
                for (int k = j + 1; k <= 10000; k++) {
                    if (vis[j] == 0 && vis[k] == 0 && ((i ^ j ^ k) == 0)) {
                        vis[i] = 1;
                        vis[j] = 1;
                        vis[k] = 1;
                        flag = 1;
                        //cout << i << endl<< j << endl<< k << endl;
                        cout << i << " "<< j << " "<< k << endl;
                        break;
                    }
                }
                if (flag)
                    break;
            }
        }
    }
}