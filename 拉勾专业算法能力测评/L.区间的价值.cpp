// http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1564

#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX = 1e5 + 10;
typedef long long LL;
LL a[MAX],l[MAX],r[MAX],z[MAX];
int main()
{
    int n,x;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
        scanf("%lld",&a[i]);
    for(int i = 1; i <= n; i++){
        int o = i - 1;
        while(o && a[o] >= a[i]) o = l[o]; // 找到左边第一个小于 a[i] 的数的位置
        l[i] = o;
    }
    for(int i = n; i >= 1; i--){
        int o = i + 1;
        while(o <= n && a[o] >= a[i]) o = r[o]; // 找到右边第一个小于 a[i] 的数的位置
        r[i] = o;
    }
    for(int i = 1; i <= n; i++){
        int o = i;
        while(o){
            int nl = r[o] - l[o] - 1; // 没有把l[i],r[i]包含在内，实际上 a[i] 是区间内最小的数
            z[nl] = max(z[nl],a[i] * a[o]);
            o = l[o];
        }
        o = r[i];
        while(o <= n){
            int nl = r[o] - l[o] - 1;
            z[nl] = max(z[nl],a[i] * a[o]);
            o = r[o];
        }
    }
    for(int i = n - 1; i >= 1; i--) {
        z[i] = max(z[i],z[i + 1]);
	}
	
    for(int i = 1; i <= n; i++) {
        printf("%lld\n",z[i]);			
	}
    return 0;
} 