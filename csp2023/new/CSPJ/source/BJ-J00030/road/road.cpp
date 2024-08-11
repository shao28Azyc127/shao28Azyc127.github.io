#include<bits/stdc++.h>
using namespace std;
int read()
{
    int x=0;char ch=' ';
    while(!isdigit(ch))
        ch=getchar();
    while(isdigit(ch))
    {
        x=x*10+ch-48;
        ch=getchar();
    }
    return x;
}
int way[100005],p[100005];
int dist[100005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n=read(),d=read();
    for(int i=1;i<n;++i)
        way[i]=read();
    for(int i=1;i<n;++i)
        dist[i+1]=dist[i]+way[i];
    for(int i=1;i<=n;++i)
        p[i]=read();
    if(n==1){cout<<0;return 0;}
    if(n==2)
    {
        long long rett;
        if(way[1]%d)
            rett=(way[1]/d+1)*p[1];
        else rett=way[1]/d*p[1];
        cout<<rett;return 0;
    }
    int node=1;
    long long ans=0;
    long long rem=0;
    for(int i=2;i<=n;++i)
    {
        if(p[i]<p[node])
        {
            long long spend;
            if((dist[i]-dist[node])%d)
            {
                spend=p[node]*((dist[i]-dist[node])/d+1);
                rem+=spend/p[node]*d-(dist[i]-dist[node]);
            }
            else spend=p[node]*((dist[i]-dist[node])/d);
            ans+=spend-rem/d*p[node];rem%=d;
            node=i;
        }
    }
    long long sp;
    if((dist[n]-dist[node])%d)
    {
        sp=p[node]*((dist[n]-dist[node])/d+1);
        rem+=sp/p[node]*d-(dist[n]-dist[node]);
    }
    else sp=p[node]*((dist[n]-dist[node])/d);
    ans+=sp-rem/d*p[node];cout<<ans;
    fclose(stdin);fclose(stdout);
    return 0;
}
