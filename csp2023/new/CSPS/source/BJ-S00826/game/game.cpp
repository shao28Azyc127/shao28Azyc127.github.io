#include <bits/stdc++.h>
using namespace std;
bool f[8001][80001];
char a[2000001];
int ans,n;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>a+1;
    for(int i=1;i<n;i++)
    {
        if(a[i]==a[i+1]){
            f[i][i+1]=1;
            ans++;
        }

    }
    for(int k=2;k<=n;k++)
    {
        for(int i=1;i<=n-k;i++)
        {
            int j=i+k;
            if(a[i]==a[j]&&f[i+1][j-1])
            {
                f[i][j]=1;
                ans++;
                continue;
            }
            for(int m=i;m<j;m++)
            {
                if(f[i][m]&&f[m+1][j])
                {
                    f[i][j]=1;
                    ans++;
                    break;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
