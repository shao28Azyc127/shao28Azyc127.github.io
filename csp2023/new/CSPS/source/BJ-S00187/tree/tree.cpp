#include<bits/stdc++.h>
using namespace std;
int n;
long long a[10005],b[10005],c[10005];
long long tall[10005];
int g[10005];
int t[10005];
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<=n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a]=b;
    }
    long long maxn=0;
    long long mod=1;
    for(int i=1;i<=n;i++){
        int x1=a[i];
        int x=1;
        while(x1>0){
            x1-=max(b[i]+x*c[i],mod);
            x++;
        }
        tall[i]=x;
    }
    t[1]=1;
    for(int i=2;i<=n;i++){
        t[i]=g[t[i-1]];
    }
    for(int i=1;i<=n;i++){
        tall[i]+=t[i];
        maxn=max(maxn,tall[i]);
    }
    cout<<maxn;
    return 0;
}
