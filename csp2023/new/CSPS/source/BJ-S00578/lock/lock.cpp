#include<bits/stdc++.h>
using namespace std;
int n,a[10][10];
int t[11][5];
int ans1,ans2;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    ans1=ans2=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cin>>a[i][j];
            t[a[i][j]][j]=1;
        }
    }
    for(int i=1;i<=5;i++)
    {
        int cnt=0;
        for(int j=0;j<10;j++)
        {
            cnt+=!t[j][i];
        }
        ans1+=cnt;
    }
    for(int i=1;i<5;i++)
    {
        int cnt=0;
        for(int j=0;j<10;j++)
        {
            cnt+=!t[j][i];
        }
        ans2+=cnt;
    }
    cout<<ans1+ans2<<endl;
    return 0;
}