#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<vector<char> > ve(4, vector<char>(4));
        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                cin >> ve[i][j];
            }
        }
        char tmp;
        int flag = 0;
        for (int i = 1; i <= 3; i++) {
            if (ve[i][1] == ve[i][2] && ve[i][2] == ve[i][3]) {
                tmp = ve[i][1];
                flag = 1;
            }
        }
        for (int i = 1; i <= 3; i++) {
            if (ve[1][i] == ve[2][i] && ve[2][i] == ve[3][i]) {
                tmp = ve[1][i];
                flag = 1;
            }
        }
        if (ve[1][1] == ve[2][2] && ve[2][2] == ve[3][3]) {
            tmp = ve[1][1];
            flag = 1;
        }
        if (ve[1][3] == ve[2][2] && ve[3][1] == ve[2][2]) {
            tmp = ve[2][2];
            flag = 1;
        }
        if (flag && tmp != '.') {
            cout << tmp << endl;
        } else {
            cout << "DRAW" << endl;
        }
    }
}