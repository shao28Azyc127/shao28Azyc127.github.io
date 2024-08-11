#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int mp[100010];
int a[20][20];
int x[20];
void solve()
{
    int s[10];
    for(int i=1;i<=5;i++)s[i]=x[i];
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=9;j++)
        {
            for(int k=1;k<=5;k++)s[k]=x[k];
            s[i]=(s[i]+j)%10;
            mp[s[1]*10000+s[2]*1000+s[3]*100+s[4]*10+s[5]]++;
        }
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=9;j++)
        {
            for(int k=1;k<=5;k++)s[k]=x[k];
            s[i]=(s[i]+j)%10;
            s[i+1]=(s[i+1]+j)%10;
            mp[s[1]*10000+s[2]*1000+s[3]*100+s[4]*10+s[5]]++;
        }
    }
}
int n;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)x[j]=a[i][j];
        solve();
    }
    int cnt=0;
    for(int num=0;num<100000;num++)
    {
        if(mp[num]==n)cnt++;
    }
    cout<<cnt;
    return 0;
}