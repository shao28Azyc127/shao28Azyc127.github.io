#include<bits/stdc++.h>
using namespace std;
int n,f=114514,t=0,minn=114514,zx[100005],ans,s;
int v[100005],a[100005],dp[100005];//zuixiaozhi
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

     int n,d,x,y;
     cin>>n>>d;
     for(int i=1;i<=n-1;i++)
     {
         cin>>x;
         t+=x;
         v[i]=x;
     }
     cin>>x;
     zx[1]=x;
        for(int i=2;i<=n;i++)
     {
         cin>>y;
         f=min(f,y);
         a[i]=y;
         zx[i]=min(zx[i-1],y);
     }
     if(a[1]==f)cout<<t/d*f;
     else
     {
         int m;

        for(int i=1;i<=n-1;i++)
        {
            if(zx[i]==zx[i+1])
            {
                if((v[i]+v[i+1])%d==0)m=(v[i]+v[i+1])/d;
                else m=(v[i]+v[i+1])/d+1;
                ans+=m*zx[i];
                s+=m*zx[i]-v[i]-v[i+1];
                i+=2;
            }
            if(v[i]%d==0)m=v[i]/d;
            else m=v[i]/d+1;
            if(v[i]-(m-1)*d<s)
            {
                m--;
                s-=v[i]-(m-1)*d;
            }
            ans+=m*zx[i];
            s+=m*zx[i]-v[i];
        }
        cout<<ans;
     }

    return 0;
}
