#include <bits/stdc++.h>

using namespace std;

int c,t,kk;

long long n,m,k,d;
long long x[10000],y[10000],v[10000];

int e,rd;
int maxn;

int i,j;

void DFS(int day)
{
    //cout<<"dAY "<<day<<endl;
    //cout<<"rd "<<rd<<endl;
    //cout<<"E "<<e<<endl;

    if(rd==k-1)
    {
        rd=0;
        DFS(day+1);
    }

    for(int i=1;i<=m;++i)
    {
        if(day==x[i]&&rd>=y[i])
        {
            e+=v[i];
        }
    }

    maxn=max(maxn,e);

    if(day>=n)
    {
        return;
    }

    e-=d;
    rd++;
    DFS(day+1);
    e+=d;
    rd--;

    int tmp=rd;
    rd=0;
    DFS(day+1);
    rd=tmp;

    return;
}

int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);

    scanf("%d%d",&c,&t);

    for(kk=1;kk<=t;++kk)
    {
        maxn=-10000000;

        scanf("%lld%lld%lld%lld",&n,&m,&k,&d);

        for(i=1;i<=m;++i)
        {
            scanf("%lld%lld%lld",&x[i],&y[i],&v[i]);
        }

        DFS(1);

        printf("%d\n",maxn);
    }


    return 0;
}
