#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

struct xx {
    int v, val;
};
vector<xx> edge[N];
int maxn=-1e9;
vector<int> d1(N), d2(N);

void dfs(int u, int fa) {
    d1[u] = 0;
    d2[u] = 0;
    for (auto i : edge[u]) {
        if (i.v == fa) {
            continue;
        }
        dfs(i.v, u);
        int tmp = d1[i.v] + i.val;
        if (tmp > d1[u]) {
            d2[u] = d1[u];
            d1[u] = tmp;
        } else if (tmp > d2[u]) {
            d2[u] = tmp;
        } 
    }
    maxn = max(maxn, d1[u] + d2[u]);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y, val;
        cin >> x >> y >> val;
        edge[x].push_back({y, val});
        edge[y].push_back({x, val});
    }
    dfs(1, 0);
    cout << maxn << endl;
}