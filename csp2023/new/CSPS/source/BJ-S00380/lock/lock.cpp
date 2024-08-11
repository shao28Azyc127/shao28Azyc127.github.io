#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int a[15][15],n,i,j,k,ans=81,used[81]={},build[90][15]={},s,b[15]={};
    cin >> n;
    for (i=1;i<=n;i++)
    {
        cin >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4] >> a[i][5];
    }
    if (n==1)
    {
        cout << 81;
    }
    else
    {
        for (i=1;i<=81;i++)
        {
            if (i<=45)
            {
                if (i%9!=0)
                {
                    build[i][i/9+1]=(a[1][i/9+1]+i%9)%10;
                }
                else
                {
                    build[i][i/9]=(a[1][i/9]+9)%10;
                }
            }
            else
            {
                if (i%9!=0)
                {
                    build[i][(i-45)/9+1]=(a[1][(i-45)/9+1]+i%9)%10;
                    build[i][(i-45)/9+2]=(a[1][(i-45)/9+2]+i%9)%10;
                }
                else
                {
                    build[i][(i-45)/9]=(a[1][(i-45)/9]+9)%10;
                    build[i][(i-45)/9+1]=(a[1][(i-45)/9+1]+9)%10;
                }
            }
            for (j=1;j<=5;j++)
            {
                if (build[i][j]==0)
                {
                    build[i][j]=a[1][j];
                }
            }
        }
        for (i=2;i<=n;i++)
        {
            for (j=1;j<=81;j++)
            {
                s=0;
                for (k=1;k<=5;k++)
                {
                    if (build[j][k]!=a[i][k])
                    {
                        s++;
                        b[s]=k;
                    }
                }
                if (s>=3 && !used[j])
                {
                    ans--;
                    used[j]=1;
                }
                if (s==2)
                {
                    if (b[1]+1!=b[2] && !used[j])
                    {
                        ans--;
                        used[j]=1;
                    }
                    if (build[j][b[1]]-a[i][b[1]]!=build[j][b[2]]-a[i][b[2]] && !used[j])
                    {
                        ans--;
                        used[j]=1;
                    }
                }
                if (s==0 && !used[j])
                {
                    ans--;
                    used[j]=1;
                }
            }
        }
        cout << ans;
    }
    return 0;
}
