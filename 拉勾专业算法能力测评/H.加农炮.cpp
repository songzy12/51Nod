// http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1287

// segment tree: maximum height of a scope

#include<iostream>
using namespace std;

const int maxn = 50000;
int h[maxn+5];
int b[maxn+5];

int m, n;

void solve() {
    for (int i = 0; i < n; ++i) {
        int j = 0;
        while (j < m && h[j] < b[i])
            j++;
        if (j == 0 || j == m)
            continue;
        h[j-1]++;
    }
    for (int j = 0; j < m; ++j)
        printf("%d\n", h[j]);
    return;
}

int main() {
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; ++i)
        scanf("%d", &h[i]);
    for (int i = 0; i < n; ++i)
        scanf("%d", &b[i]);
    solve();
    return 0;
}