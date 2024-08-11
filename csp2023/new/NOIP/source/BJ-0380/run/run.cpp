#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
using namespace std;

const int M=1e5+5,N=1e3+5;
int n,m,k,d;
int x[M],y[M],v[M];
long long f[N][N];//f[i][j]表示在第i天已经连续跑了j天取得的能量最大值

struct meal{
    int x,y,v;
    bool operator<(const meal &b)const{
        return x<b.x;
    }
}a[M];

int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>m>>k>>d;
        for(int i=1;i<=m;i++)
            cin>>a[i].x>>a[i].y>>a[i].v;
        sort(a+1,a+1+m);
        memset(f,-0x3f,sizeof(f));
        f[0][0]=0;
        int ml=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=k&&j+1<=i;j++)
                f[i][0]=max(f[i][0],f[i-1][j]);
            for(int j=0;j<k&&j+1<=i;j++)//昨天连续跑了几天
            {
                int day=j+1,ad=0,ml2=ml;
                while(ml2<=m&&a[ml2].x<=i){
                    if(a[ml2].x==i&&a[ml2].y<=day)ad+=a[ml2].v;
                    ml2++;
                }
                f[i][j+1]=f[i-1][j]-d+ad;
            }
            while(ml<=m&&a[ml].x<=i)ml++;
        }
        long long ans=-1e9;
        for(int i=0;i<=k;i++){
            ans=max(ans,f[n][i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
