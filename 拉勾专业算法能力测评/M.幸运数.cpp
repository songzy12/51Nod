// http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1230

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

int tot,prime[1500],a[20];
bool not_prime[1500];
LL f[20][170][1460]; // 前 i 位，和为 j，平方和为 k

void get_prime(int n)
{
    not_prime[1]=1;
    for (int i=2;i<=n;i++)
    {
        if (!not_prime[i]) prime[++tot]=i;
        for (int j=1;j<=tot&&i*prime[j]<=n;j++)
        {
            not_prime[i*prime[j]]=1;
            if (i%prime[j]==0) break;
        }
    }
}

LL dfs(int x,int y,int z,int lim)
{
	// here we compute whether it is a lucky number 
    if (x==1) 
		return !not_prime[y]&&!not_prime[z]?1:0;
	
    if (!lim&&f[x][y][z]) 
		return f[x][y][z];
    int t=lim?a[x-1]-1:9;
	LL ans=0;
    if (lim) 
		ans+=dfs(x-1,y+a[x-1],z+a[x-1]*a[x-1],lim);
	// here t is a[x-1] - 1 or 9
    for (int i=0;i<=t;i++) 
		ans+=dfs(x-1,y+i,z+i*i,0);
    if (!lim) 
		f[x][y][z]=ans;
    return ans;
}

LL solve(LL n)
{
    int a1=0;
    while (n) a[++a1]=n%10,n/=10;
    return dfs(a1+1,0,0,1);
}

int main()
{
    get_prime(1458);
    int T;
    scanf("%d",&T);
    while (T--)
    {
        LL x,y;
        scanf("%lld%lld",&x,&y);
        printf("%lld\n",solve(y)-solve(x-1));
    }
    return 0;
}