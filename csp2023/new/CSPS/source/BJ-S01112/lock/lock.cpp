#include<iostream>
using namespace std;
int d[100000],n,q[10],ans;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    ans=0;
    for(int i=0;i<=99999;i++)
    {
        d[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>q[1]>>q[2]>>q[3]>>q[4]>>q[5];
        for(int j=1;j<=9;j++)
        {
            int w=(q[1]+j)%10;
            int f=w*10000+q[2]*1000+q[3]*100+q[4]*10+q[5];
            if(d[f]<i) d[f]++;
        }
         for(int j=1;j<=9;j++)
        {
            int w=(q[2]+j)%10;
            int f=q[1]*10000+w*1000+q[3]*100+q[4]*10+q[5];
            if(d[f]<i) d[f]++;
        }
        for(int j=1;j<=9;j++)
        {
            int w=(q[3]+j)%10;
            int f=q[1]*10000+q[2]*1000+w*100+q[4]*10+q[5];
            if(d[f]<i) d[f]++;
        }
         for(int j=1;j<=9;j++)
        {
            int w=(q[4]+j)%10;
            int f=q[1]*10000+q[2]*1000+q[3]*100+w*10+q[5];
            if(d[f]<i) d[f]++;
        }
         for(int j=1;j<=9;j++)
        {
            int w=(q[5]+j)%10;
            int f=q[1]*10000+q[2]*1000+q[3]*100+q[4]*10+w;
            if(d[f]<i) d[f]++;
        }
         for(int j=1;j<=9;j++)
        {
            int w1=(q[1]+j)%10;
            int w2=(q[2]+j)%10;
            int f=w1*10000+w2*1000+q[3]*100+q[4]*10+q[5];
            if(d[f]<i) d[f]++;
        }
        for(int j=1;j<=9;j++)
        {
            int w1=(q[2]+j)%10;
            int w2=(q[3]+j)%10;
            int f=q[1]*10000+w1*1000+w2*100+q[4]*10+q[5];
            if(d[f]<i) d[f]++;
        }
        for(int j=1;j<=9;j++)
        {
            int w1=(q[3]+j)%10;
            int w2=(q[4]+j)%10;
            int f=q[1]*10000+q[2]*1000+w1*100+w2*10+q[5];
            if(d[f]<i) d[f]++;
        }
        for(int j=1;j<=9;j++)
        {
            int w1=(q[4]+j)%10;
            int w2=(q[5]+j)%10;
            int f=q[1]*10000+q[2]*1000+q[3]*100+w1*10+w2;
            if(d[f]<i) d[f]++;
        }
    }
    for(int i=0;i<=99999;i++)
    {
        if(d[i]==n)
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
