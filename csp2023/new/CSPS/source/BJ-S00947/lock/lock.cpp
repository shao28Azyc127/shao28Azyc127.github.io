#include<cstdio>
int a[5];
inline int f()
{
    int res=0;
    for(int i=0;i<5;++i) res=res*10+a[i];
    return res;
}
int vis[100010];
inline void Add(int &x,int y){x=(x+y)%10;}
inline void Sub(int &x,int y){x=(x+10-y)%10;}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int t=0;t<n;++t)
    {
        for(int i=0;i<5;++i) scanf("%d",&a[i]);
        for(int i=0;i<5;++i)
            for(int j=1;j<=9;++j) Add(a[i],j),vis[f()]|=1<<t,Sub(a[i],j);
        for(int i=0;i<4;++i)
            for(int j=1;j<=9;++j)
                Add(a[i],j),Add(a[i+1],j),vis[f()]|=1<<t,Sub(a[i],j),Sub(a[i+1],j);
    }
    int ans=0;
    for(int i=0;i<100000;++i) if(vis[i]==((1<<n)-1)) ++ans;
    printf("%d\n",ans);
    return 0;
}
