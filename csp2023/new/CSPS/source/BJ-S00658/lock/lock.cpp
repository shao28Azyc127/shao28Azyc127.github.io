#include <bits/stdc++.h>
using namespace std;
int a[10][10],b[10];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++)
            cin>>a[i][j];
    int ans=0;
    for(b[1]=0;b[1]<=9;b[1]++)
    for(b[2]=0;b[2]<=9;b[2]++)
    for(b[3]=0;b[3]<=9;b[3]++)
    for(b[4]=0;b[4]<=9;b[4]++)
    for(b[5]=0;b[5]<=9;b[5]++)
    {
        bool flag=1;
        for(int i=1;i<=n;i++)
        {
            if(!flag) break;
            bool fl=0;
            int st;
            for(int j=1;j<=5;j++)
            if(a[i][j]!=b[j])
            {
                if(!fl)
                {
                    fl=1;
                    st=j;
                }
                else
                {
                    if(j!=st+1)
                    {
                        flag=0;
                        break;
                    }
                    else if((10+a[i][st]-b[st])%10!=(10+a[i][j]-b[j])%10)
                    {
                        flag=0;
                        break;
                    }
                }
            }
            if(!fl)
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            //cout<<b[1]<<" "<<b[2]<<" "<<b[3]<<" "<<b[4]<<" "<<b[5]<<"\n";
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
