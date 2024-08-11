#include<bits/stdc++.h>
using namespace std;
int a[2000086];
bool f[8001][8001];
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n;
    string a;
    cin>>a;
    a=" "+a;
    for(int i=1;i<=n;i++)
    {
        f[0][i]=1;
    }
    int ans=0;
    for(int i=1;i<=n/2;i++)
    {
        for(int j=1;j+2*i-1<=n;j++)
        {
            if(f[i-1][j+1]&&(a[j]==a[j+2*i-1]))
            {
                f[i][j]=1;
            }
            else{
                for(int k=1;k<i;k++)
                {
                    if(f[k][j]&&f[i-k][j+2*k])
                    {
                        f[i][j]=1;
                        break;
                    }
                }
            }
            ans+=f[i][j];
        }
    }
    cout<<ans;
    return 0;
}
