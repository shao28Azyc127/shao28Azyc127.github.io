#include<iostream>
#include<cstdio>
using namespace std;
int n,a[10];
int cnt[10][10][10][10][10],ans;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
            cin>>a[j];
        for(int j=1;j<=5;j++)
            for(int k=1;k<=9;k++)
            {
                int x=a[j];
                a[j]=(a[j]+k)%10;
                cnt[a[1]][a[2]][a[3]][a[4]][a[5]]++;
                a[j]=x;
            }
        for(int j=1;j<=4;j++)
            for(int k=1;k<=9;k++)
            {
                int x=a[j],y=a[j+1];
                a[j]=(a[j]+k)%10;
                a[j+1]=(a[j+1]+k)%10;
                cnt[a[1]][a[2]][a[3]][a[4]][a[5]]++;
                a[j]=x,a[j+1]=y;
            }
    }
    for(int i=0;i<=9;i++)
    for(int j=0;j<=9;j++)
    for(int k=0;k<=9;k++)
    for(int p=0;p<=9;p++)
    for(int q=0;q<=9;q++)
        if(cnt[i][j][k][p][q]==n)ans++;
    cout<<ans<<endl;
    return 0;
}