// http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1288

#include<cstdio>
#include<stack>
#include<algorithm>
using namespace std;

const int maxn = 1e5;

long long D[maxn], P[maxn], t;
int n;

bool check() {
    for (int i = 0; i < n; ++i)
        if (D[i] > t)
            return false;
    return true;
}

long long prefix[maxn+1];
int until[maxn];

void init() {
    prefix[0] = 0;
    for (int i = 0; i < n; ++i)
        prefix[i + 1] = prefix[i] + D[i];

    stack<int> v;
    for (int i = 0; i < n; ++i) {
        if (v.empty()) {
            v.push(i);
            continue;
        }
        while (!v.empty() && P[v.top()] > P[i]) {
           until[v.top()] = i;
           v.pop();
        }
        v.push(i);
    }
    while (!v.empty()) {
        until[v.top()] = n;
        v.pop();
    }
    
    return ;
}

long long solve() {
    if (!check())    
        return -1;

    long long ans = 0;

    int i = 0;
    long long left = 0;
    while (i < n) {
        int j = until[i];
        long long total = prefix[j] - prefix[i];        
        long long need = min(t - left, total - left);
        need = max(need, 0LL);
        ans += P[i] * need;
        left += need;
        left -= D[i];
        i++;
    }
    return ans;
}

// 能否到达：假设每次都灌满
// 枚举当前的城市，计算当前的城市的油价一直到后面哪个城市都是最小的
// 设这个数为y，当前城市为x，那么从x到y+1中间的道路消耗的油都应该尽量在x加

int main() {
    scanf("%d %d", &n, &t);
    for (int i  =0;i <n; ++i)
        scanf("%lld %lld", &D[i], &P[i]);
    init();
    printf("%lld\n", solve());
    return 0;
}