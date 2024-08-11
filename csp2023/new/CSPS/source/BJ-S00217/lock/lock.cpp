#include<bits/stdc++.h>
using namespace std;
map<int,int>m;
int n,sum=0;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x=0;
        for(int j=1;j<=5;j++)
        {
            int shuru;
            cin>>shuru;
            for(int a=1;a<j;a++)shuru*=10;
            x+=shuru;
        }
        for(int j=1;j<=5;j++)
        {
            int y=x;
            int l=0,r=0;
            for(int a=1;a<j;a++)
            {
                int zs=y%10;
                for(int b=1;b<a;b++)zs*=10;
                r+=zs;
                y/=10;
            }
            int nz=y%10;
            l=y/10;
            for(int a=1;a<=j;a++)l*=10;
            for(int a=1;a<=9;a++)
            {
                int ge=nz;
                ge+=a;
                ge%=10;
                for(int b=1;b<j;b++)ge*=10;
                int z=l+ge+r;
                m[z]++;
            }
        }
        for(int j=1;j<=4;j++)
        {
            int y=x;
            int l=0,r=0;
            for(int a=1;a<j;a++)
            {
                int zs=y%10;
                for(int b=1;b<a;b++)zs*=10;
                r+=zs;
                y/=10;
            }
            int nz=y%100;
            l=y/100;
            for(int a=1;a<=j+1;a++)l*=10;
            for(int a=1;a<=9;a++)
            {
                int shi=nz/10,ge=nz%10;
                shi+=a;
                ge+=a;
                shi%=10;
                ge%=10;
                int gs=shi*10+ge;
                for(int b=1;b<j;b++)gs*=10;
                int z=l+gs+r;
                m[z]++;
            }
        }
    }
    for(int i=0;i<=99999;i++)
    {
        if(m[i]>=n)sum++;
    }
    cout<<sum;
    return 0;
}
