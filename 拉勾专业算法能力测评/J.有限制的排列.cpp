// http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1296

// dp[j]: the valid number which ends with j
// sum[j]: sum of valid number ends with 1 ... j

// state[i]: whether i is larger than i - 1

#include <cstdio>

const int maxn = 5000;
const long long p = 1e9+7;

int n;
int state[maxn+1];
long long sum[maxn+1];
long long dp[maxn+1];

int main() {
    int k, l;
    scanf("%d %d %d", &n, &k, &l);
    for (int i  = 0; i < k; ++i) {
        int t;
        scanf("%d", &t);
        state[t] = -1;
        state[t+1] = 1;
    }
    for (int i  = 0; i < l; ++i) {
        int t;
        scanf("%d", &t);
        state[t] = 1;
        state[t+1] = -1;
    }

    sum[1] = 1;
    for (int i = 2; i <= n; ++i) {
        // answer with first i numbers
        for (int j = 1; j <= i; ++j) {
            dp[0] = 0;
            // dp[j]: ends with j
            if (state[i - 1] == 0)
                dp[j] = sum[i - 1];
            else if (state[i - 1] == 1)
                dp[j] = sum[j - 1];
            else if (state[i - 1] == -1)
                dp[j] = (sum[i - 1] - sum[j - 1] + p) % p; // stupid !
        }

        sum[0] = 0;
        for (int j = 1; j <= i; ++j)
            sum[j] = (sum[j - 1] + dp[j]) % p;
    }
    printf("%lld\n", sum[n]);
    return 0;
}