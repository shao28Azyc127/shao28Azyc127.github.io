#include <bits/stdc++.h>
using namespace std;
int a[15][10];
bool is_use[15][11];
int ans=1;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cin>>a[i][j];
        }
    }
    int temans;
    if(n==1)
    {
        cout<<81<<endl;
        return 0;
    }
    else
    {
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=n;j++)
            {
                is_use[i][a[j][i]]=true;
            }
        }
        for(int i=1;i<=5;i++)
        {
            temans=0;
            for(int j=0;j<=9;j++)
            {
                if(is_use[i][j]==false)
                {
                    temans++;
                }
            }
            cout<<temans<<endl;
            ans*=temans;
        }
        cout<<ans;
    }
    return 0;
}
