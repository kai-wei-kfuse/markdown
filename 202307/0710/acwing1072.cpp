#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

struct xx {
    int x, val;
};
vector<xx> edge[N];
vector<int> dist(N);
int maxn = 0;

void dfs(int u, int fa) {
    for (auto i : edge[u]) {
        if (i.x == fa) {
            continue;
        }
        dist[i.x] = dist[u] + i.val;
        if (dist[i.x] > dist[maxn]) {
            maxn = i.x;
        }
        dfs(i.x,u);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y, val;
        cin >> x >> y;  // >> val;
        edge[x].push_back({y, 1});
        edge[y].push_back({x, 1});
    }
    dfs(1, 0);
    int u=maxn;
    dist[u] = 0;
    dfs(u, 0);
    cout << dist[maxn] << endl;
}