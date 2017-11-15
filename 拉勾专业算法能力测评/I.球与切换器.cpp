// http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1293

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn = 1000;
int box[maxn][maxn];
long long num[maxn+1][maxn+1];

int m, n;
long long k; // 2. data type

void solve(int x, int y) {
    if (x >= n || y >= m)
        return;
    if (box[x][y] == 0)
        return;
 
    long long temp = num[x][y];
    long long less = temp / 2;
    long long more = temp - less;

    if (box[x][y] == -1) {
        int t = x + 1;
        while (t < n && box[t][y] == 0)
            t++;
        num[t][y] += more;
        
        t = y + 1;
        while (t < m && box[x][t] == 0)
            t++;
        num[x][t] += less;
    } else {
        int t = x + 1;
        while (t < n && box[t][y] == 0)
            t++;
        num[t][y] += less;

        t = y + 1;
        while (t < m && box[x][t] == 0)
            t++;
        num[x][t] += more;
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    scanf("%d %d %lld", &m, &n, &k);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%d", &box[i][j]);
    
    memset(num, 0, sizeof num);

    int t = 0;
    while (t < n && box[t][0] == 0) 
        t++;
    num[t][0] = num[t][0] + k * 1L;
  
    for (int l = 0; l < m + n - 1; ++l) { // 1. notice the range of l
        for (int k = 0; k <= l; ++k) {
            solve(l - k, k);
        }
    }
    printf("%lld\n", num[n][m-1]);
}