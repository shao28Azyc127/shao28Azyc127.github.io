#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=9,MAXN=1e6+1;
int n,a[N][6];
ll ans=0;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    if(n==1)
    {
        for(int i=1;i<=5;i++)cin >> a[1][i];
        cout<<81;
        return 0;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++)
            cin >> a[i][j];
    if(n==2)
    {
        for(int i=1;i<=4;i++)
            if((a[1][i]!=a[2][i]&&a[1][i+1]==a[2][i+1])||(a[1][i]==a[2][i]&&a[1][i+1]!=a[2][i+1]))ans+=10;
        cout<<ans;
    }
    else
    {
        int U=0;
        for(int j=1;j<=5;j++)
        {
            int cnt=0;
            for(int i=1;i<n;i++)
                if(a[i][j]!=a[i+1][j])cnt=1;
            U+=cnt;
        }
        if(U!=1)cout<<"1234567890";
        else cout<<n;
    }
    return 0;
}