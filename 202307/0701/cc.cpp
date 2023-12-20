#include <bits/stdc++.h>
using namespace std;

#define int long long

struct xx {
    int a, b, id;
};

bool cmp(xx i, xx j) {
    if (i.a * j.b == i.b * j.a) {
        return i.id < j.id;
    } else
        return i.a * j.b > i.b * j.a;
}

signed main() {
    int n;
    cin >> n;
    vector<xx> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i].a >> v[i].b;
        v[i].id = i;
    }
    sort(v.begin() + 1, v.end(), cmp);
    for (int i = 1; i <= n; i++) {
        cout << v[i].id << " ";
    }
}