#include <bits/stdc++.h>
using namespace std;

struct xxx {
    int x, y, c;
};
string ss = "snuke";
int xx[4] = {0, 0, 1, -1};
int yy[4] = {1, -1, 0, 0};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> ve(n + 1, vector<char>(m + 1));
    vector<vector<int>> vis(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> ve[i][j];
        }
    }
    if (ve[1][1] != ss[0]) {
        cout << "No" << endl;
        return 0;
    }
    queue<xxx> q;
    int flag = 0;
    q.push({1, 1, 0});
    vis[1][1] = 1;
    while (!q.empty()) {
        xxx pos = q.front();
        q.pop();
        if (pos.x == n && pos.y == m) {
            flag = 1;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int x = pos.x + xx[i];
            int y = pos.y + yy[i];
            if (x >= 1 && x <= n && y >= 1 && y <= m&&vis[x][y]==0) {
                if (ve[x][y] == ss[(pos.c + 1)%5]){
                    vis[x][y] = 1;
                    q.push({x, y, (pos.c + 1)%5});
                }
            }
        }
    }
    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}