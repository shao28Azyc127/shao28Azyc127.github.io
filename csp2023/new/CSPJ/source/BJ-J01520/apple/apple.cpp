#include <bits/stdc++.h>
using namespace std;
long long nxt[1000006],head,tail,pre[1000005];
void adde(long long i)//push i at the bottom
{
    nxt[i]=tail;
    pre[i]=pre[tail];
    nxt[pre[i]]=i;
    pre[tail]=i;
}
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n;
    scanf("%lld",&n);
    head=0;
    tail=n+1;
    for(long long i=1;i<=n;i++)
    {
        adde(i);
    }
    long long x=0,x1=0;
    while(nxt[head]!=tail)
    {
        x++;
        for(long long i=nxt[head];;)
        {
            pre[nxt[i]]=pre[i];
            nxt[pre[i]]=nxt[i];
            if(i==n)
                x1=x;
            i=nxt[i];
            if(i==tail)
                break;
            i=nxt[i];
            if(i==tail)
                break;
            i=nxt[i];
            if(i==tail)
                break;
        }
    }
    printf("%lld %lld",x,x1);
    return 0;
}
