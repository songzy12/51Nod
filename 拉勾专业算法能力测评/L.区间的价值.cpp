// http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1564

#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100000;

long long min_[maxn];
long long max_[maxn];
long long num[maxn];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &num[i]);
        min_[i] = max_[i] = num[i];
    }
    for (int k = 0; k < n; ++k) {
        long long temp = 0;
        for (int i = 0; i + k < n; ++i) {
            min_[i] = min(min_[i], num[i+k]);
            max_[i] = max(max_[i], num[i+k]);
            temp = max(temp, min_[i] * max_[i]);
        }
        printf("%lld\n", temp);
    }
    return 0;
}