#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
vector<int> edge[N];
vector<int> vis(N, 0), col(N, -1);
vector<int> ans;
void dfs(int u) {
    if (col[u] == -1) {
        col[u] = 1;
        ans.push_back(u);
        for (auto i : edge[u]) {
            col[i] = 0;
        }
    }
    for (auto i : edge[u]) {
        if (vis[i] == 0) {
            vis[i] = 1;
            dfs(i);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= m; i++) {
            int x, y;
            cin >> x >> y;
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        vis[1] = 1;
        ans.clear();
        dfs(1);
        int flag = 0;
        for (int i = 1; i <= n;i++){
            col[i] = -1;
            if(vis[i]==0){
                flag = 1;
            }
            vis[i] = 0;
            edge[i].clear();
        }
        if(flag==0){
            cout << "YES" << endl;
            cout << ans.size() << endl;
            for (auto i : ans) {
                cout << i << " ";
            }
            cout << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}