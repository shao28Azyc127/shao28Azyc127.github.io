#include<bits/stdc++.h>
using namespace std;

int n ;
long long ans;
bool f[8010][8010];
char a[8010];

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >> n ;
    cin >> a+1 ;
    for(int i=2;i<=n;i++)
        if(a[i]==a[i-1])
            f[i-1][i]=1;
    for(int l=4;l<=n;l+=2)
    {
        for(int i=1;i<=n-l+1;i++)
        {
            if(f[i+1][i+l-2]&&a[i]==a[i+l-1])
                f[i][i+l-1]=1;
            for(int k=i+1;k<i+l-1;k++)
                if(f[i][k]&&f[k+1][i+l-1])
                    f[i][i+l-1]=1;
        }
    }
    //for(int l=2;l<=n;l++)
    //{
    //    for(int i=1;i<=n-l+1;i++)
    //    {
    //        for(int k=i;k<i+l-1;k++)
    //            ans[i][i+l-1]=max(ans[i][i+l-1],ans[i][k]+ans[k][i+l-1]);
    //        if(f[i][i+l-1])
    //            ans[i][i+l-1]+=1;
    //    }
    //}
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(f[i][j])
                ans++;
    cout << ans << endl ;
    return 0 ;
}
