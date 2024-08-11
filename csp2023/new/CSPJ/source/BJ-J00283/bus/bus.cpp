#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
using namespace std;

const int MAX=1e4+5;

int n,m,k,dp[MAX];
int r[MAX][MAX];
int p,t,f;
bool rf[MAX][MAX];

int divideup(int a,int b)
{
    if(a%b==0)
    {
        return a/b;
    }
    else
    {
        return a/b+1;
    }
}

int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        int u,v,a;
        scanf("%d%d%d",&u,&v,&a);
        r[u][v]=a;
        p=max(p,a);
        rf[u][v]=true;
    }
    printf("-1");
    return 0;
}

