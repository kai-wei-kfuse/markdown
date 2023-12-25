#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n;
vector<int> sz(N), maxs(N), edge[N];
vector<int> ctr;
void dfs(int u, int fa) {
    sz[u] = 1;
    maxs[u] = 0;
    for (auto i : edge[u]) {
        if (i == fa)
            continue;
        dfs(i, u);
        sz[u] += sz[i];
        maxs[u] = max(maxs[u], sz[i]);
    }
    maxs[u] = max(maxs[u], n - sz[u]);
    //cout<<u<<' '<<maxs[u]<<' '<<sz[u]<<' '<<n<<endl;
    if (maxs[u] <= n / 2)
        ctr.push_back(u);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int leafx, leafy;
        for (int i = 1; i < n; i++) {
            int x, y;
            cin >> x >> y;
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        if (n & 1) {
            cout << 1 << ' ' << edge[1][0] << endl;
            cout << 1 << ' ' << edge[1][0] << endl;
        } else {
            dfs(1, 0);
            if (ctr.size() == 1) {
                cout << 1 << ' ' << edge[1][0] << endl;
                cout << 1 << ' ' << edge[1][0] << endl;
            } else {
                int tmp;
                for(auto i:edge[ctr[0]]){
                    if(i!=ctr[1]){
                        tmp=i;
                        break;
                    }
                }
                cout << ctr[0] << ' ' << tmp << endl;
                cout << ctr[1] << ' ' << tmp << endl;
            }
        }
        for (int i = 1; i <= n; i++) {
            edge[i].clear();
        }
        ctr.clear();
    }
}