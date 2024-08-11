#include<bits/stdc++.h>
using namespace std;
int mp[10][10][10][10][10][10],n,a[10][10];
long long ans;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cin>>a[i][j];
        }mp[i][a[i][1]][a[i][2]][a[i][3]][a[i][4]][a[i][5]]=-1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            for(int k=1;k<=9;k++)
            {
                int tmp[6]={0,a[i][1],a[i][2],a[i][3],a[i][4],a[i][5]};
                tmp[j]+=k;
                if(tmp[j]>9)tmp[j]-=10;
                mp[i][tmp[1]][tmp[2]][tmp[3]][tmp[4]][tmp[5]]=1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=4;j++)
        {
            for(int k=1;k<=9;k++)
            {
                int tmp[6]={0,a[i][1],a[i][2],a[i][3],a[i][4],a[i][5]};
                tmp[j]+=k;
                tmp[j+1]+=k;
                if(tmp[j]>9)tmp[j]-=10;
                if(tmp[j+1]>9)tmp[j+1]-=10;
                mp[i][tmp[1]][tmp[2]][tmp[3]][tmp[4]][tmp[5]]=1;
            }
        }
    }
    for(int i1=0;i1<=9;i1++)
        for(int i2=0;i2<=9;i2++)
            for(int i3=0;i3<=9;i3++)
                for(int i4=0;i4<=9;i4++)
                    for(int i5=0;i5<=9;i5++)
    {
        int fl=1;
        for(int j=1;j<=n;j++)
        {
            if(mp[j][i1][i2][i3][i4][i5]<=0)
            {
                fl=0;
                break;
            }
        }
        if(fl==1)ans++;
    }
    cout<<ans;
return 0;
}
