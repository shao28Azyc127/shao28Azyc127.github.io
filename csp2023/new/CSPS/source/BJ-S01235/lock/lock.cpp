#include<bits/stdc++.h>
using namespace std;
int vis[100005],s[155];
int  ans;
int n;
long long cf(long long x)
{
    long long a=1;
    for(int o=1;o<=x;o++)
    {
        a*=10;
    }
    return a;
}
long long qs()
{
    long long a=0;
    for(int y=1;y<=5;y++)
    {
        a=a+((cf(y-1))*s[y]);
        //cout<<((10^i)/10)*s[i]<<" ";
    }    
    return a;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","W",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        
        //memset(s,0,sizeof(s));
        for(int j=1;j<=5;j++)
        {
            int m;
            scanf("%d",&m);
            //cout<<m<<" ";
            //cout<<j;
            s[j]=m;
        }
        
        //qs();
        //cout<<(10*3);
        //cout<<(((10^3)/10)*s[3]);
        //cout<<cf(3);
       // cout<<qs();
        for(int j=1;j<=5;j++)
        {
            for(int k=0;k<=9;k++)
            {
                if(k!=s[j])
                {
                    vis[qs()-cf(j-1)*s[j]+k*cf(j-1)]++;
                   // cout<<(qs()-cf(j-1)*s[j]+k*cf(j-1))<<" ";
                }
                
            }
        }
        //cout<<"*";
        for(int j=1;j<=4;j++)
        {
            for(int k=0;k<=9;k++)
            {
                int a,b;
                if(s[j+1]>s[j])
                {
                    a=k;
                    b=(k+s[j+1]-s[j])%10;
                    b%=10;
                    if(a!=s[j])
                    {
                       // cout<<qs()-cf(j)*s[j+1]+cf(j-1)*a+cf(j)*b<<" ";
                    //cout<<qs()-cf(j-1)*s[j]-cf(j)*s[j+1]<<" ";
                    vis[qs()+cf(j-1)*a+cf(j)*b-cf(j-1)*s[j]-cf(j)*s[j+1]]++;
                    }
                }
                else
                {
                    b=k;
                    a=(k+s[j]-s[j+1])%10;
                    a%=10;
                    if(b!=s[j+1])
                    {
                        //cout<<qs()-cf(j)*s[j+1]+cf(j-1)*a+cf(j)*b<<" ";
                    //cout<<qs()-cf(j-1)*s[j]-cf(j)*s[j+1]<<" ";
                    vis[qs()+cf(j-1)*a+cf(j)*b-cf(j-1)*s[j]-cf(j)*s[j+1]]++;
                    }
                }
                
            }
        }
        //cout<<"*"<<i;
    }
    for(long long i=0;i<=99999;i++)
    {
        if(vis[i]>=n)
        ans++;
    }
    printf("%d",ans);
    return 0;
}