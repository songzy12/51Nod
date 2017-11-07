#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cassert>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

const int maxn = 10000;

// 斜率最大的情况出现在相邻的两点
// 可以使用反证法证明以上结论

struct Point{
    double x, y;
    int index;
};

Point p[maxn];

bool compare(Point p0, Point p1) {
    return p0.x < p1.x;
}

int main() {
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>p[i].x>>p[i].y;
        p[i].index = i + 1;
    }
    sort(p, p+n, compare);

    double ans = (p[1].y - p[0].y)/(p[1].x - p[0].x);
    for (int i = 1; i < n - 1; ++i) {
        ans = max(ans, (p[i+1].y - p[i].y) / (p[i+1].x - p[i].x));
    }
    for (int i = 0; i < n - 1; ++i) {
        double temp =  (p[i+1].y - p[i].y) / (p[i+1].x - p[i].x);
        if (temp == ans) {
            cout<<p[i].index<<" "<<p[i+1].index;
        }
    }
    cout<<endl;
    return 0;
}