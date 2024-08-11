#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n;
int a[6];
int cnt[100000];
int make(int pos,int num)
{
    int ret=0;
    for(int i=1;i<=5;i++)
    {
        int tmp=a[i];
        if(i==pos) tmp=(tmp+num)%10;
        ret=ret*10+tmp;
    }
    return ret;
}
int make2(int pos,int num)
{

    int ret=0;
    for(int i=1;i<=5;i++)
    {
        int tmp=a[i];
        if(i==pos || i==pos+1) tmp=(tmp+num)%10;
        ret=ret*10+tmp;
    }
    return ret;
}

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++) cin>>a[j];
        for(int j=1;j<=5;j++)
        {
            for(int k=1;k<=9;k++)
            {
                cnt[make(j,k)]++;
            }
        }
        for(int j=1;j<=4;j++)
        {
            for(int k=1;k<=9;k++)
            {
                cnt[make2(j,k)]++;
            }
        }
    }
    int maxi=0;
    for(int i=0;i<100000;i++)
    {
        maxi=max(maxi,cnt[i]);
    }
    int ans=0;
    for(int i=1;i<100000;i++)
    {
        if(cnt[i]==maxi) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
