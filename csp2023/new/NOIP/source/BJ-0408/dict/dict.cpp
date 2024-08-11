#include <bits/stdc++.h>
using namespace std;
string a[4005];
int sum[4005][50];
char minz[4005],maxz[4005];
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m;
    cin>>n>>m;
    memset(maxz,0,sizeof(minz));
    for(int i=0;i<=n;i++)
    {
        minz[i]='z';
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        for(int j=0;j<m;j++)
        {
            sum[i][a[i][j]-'a'+1]++;
            minz[i]=min(minz[i],a[i][j]);
            maxz[i]=max(maxz[i],a[i][j]);
        }
    }

    if(n==1)
    {
        cout<<1;
        return 0;
    }
    bool flag=1;
    if(m==1)
    {
        for(int i=1;i<=n;i++)
        {
            flag=1;
            for(int j=1;j<=n;j++)
            {
                if(i==j) continue;
                if(a[i][0]>a[j][0])
                {
                    flag=0;
                    break;
                }
            }
            if(flag==0)
            {
                cout<<0;
            }
            else
            {
                cout<<1;
            }
        }
        return 0;
    }
    bool you=0;
    for(int i=1;i<=n;i++)
    {
        flag=0;
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            you=0;

            if(minz[i]>=maxz[j])
            {
                flag=1;
            }
        }
        if(flag==1)
        {
            cout<<0;
        }
        else{
            cout<<1;
        }
    }
    return 0;
}
