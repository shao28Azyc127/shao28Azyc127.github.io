#include<bits/stdc++.h>
using namespace std;
int a[10][10][10][10][10],b[10],ans=0;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
            cin>>b[j];
        for(int j=1;j<=5;j++)
        {
            int c=b[j],d=b[j+1];
            for(int q=1;q<=9;q++)
            {
                b[j]=(c+q)%10;
                a[b[1]][b[2]][b[3]][b[4]][b[5]]++;
                if(j==5)
                {
                    b[j]=c;
                    continue;
                }
                b[j+1]=(d+q)%10;
                a[b[1]][b[2]][b[3]][b[4]][b[5]]++;
                b[j]=c;
                b[j+1]=d;
            }
        }
    }
    for(int i=0;i<=9;i++)
        for(int j=0;j<=9;j++)
            for(int q=0;q<=9;q++)
                for(int r=0;r<=9;r++)
                    for(int l=0;l<=9;l++)
                    {
                        if(a[i][j][q][r][l]==n)
                            ans++;
                    }
    cout<<ans<<endl;
    return 0;
}
