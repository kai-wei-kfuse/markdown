#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> edge[N + 1];
vector<int> ins(N + 1);
int flag = 0;

void dfs(int u, int dep, int fa) {
    if (flag) {
        return;
    }
    if (ins[u] == 1&&fa!=0) {
        if ((dep ) & 1) {
        } else{
            cout << 3 << " ";
            flag = 1;
        }
        return;
    }
    for (auto v : edge[u]) {
        if (v == fa) continue;
        dfs(v, dep + 1, u);
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
        ins[u]++;
        ins[v]++;
    }
    int root = 0;
    int fa = 0, son = 0;
    for (int i = 1; i <= n; i++) {
        if (ins[i] == 1) {
            root = i;
        } else {
            fa++;
        }
    }

    dfs(root, 1, 0);
    if (!flag) {
        cout << 1 << " ";
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (auto j : edge[i]) {
            if (ins[j] == 1) {
                cnt++;
                break;
            }
        }
    }
    cout << fa - 1 + cnt << endl;
}