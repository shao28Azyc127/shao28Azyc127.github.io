#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<iomanip>
#include<cstdio>
#include<set>
#include<map>
#include<algorithm>
#include<functional>
#include<cstring>
#include<climits>
using namespace std;
int a[8][6],n,ans[6],ahs;
bool di[8][6];
int dif[8];
void dfs(int x)
{

    if(x==6)
    {
        ahs++;
        return;
    }
    /*for(int i=1;i<=n;i++)
    {
        cout<<dif[i]<<' ';
    }
    cout<<'\n';*/
    for(int i=0;i<=9;i++)
    {
        ans[x]=i;
        bool fff=0;
        for(int j=1;j<=n;j++)
        {
            //if(di[j][x]==1&&a[j][x]==i)
            //    dif[j]--;
            //cout<<dif[j]<<'\n';
            di[j][x]=0;
            if(a[j][x]!=i)
            {
                di[j][x]=1;
                dif[j]++;
            }
            if(dif[j]>2)
            {
                fff=1;
                //if(x==1&&i==1)
                    //cout<<"jsjsjs"<<'\n';
                break;
            }
            if(a[j][x]!=i&&dif[j]==2&&di[j][x-1]==0)
            {
                fff=1;
                //if(x==1&&i==1)
                    //cout<<"asasas"<<'\n';
                break;
            }
            if(a[j][x]!=i&&dif[j]==2)
            {
                if((i-a[j][x]+10)%10!=(ans[x-1]-a[j][x-1]+10)%10/*&&!(i==9&&a[j][x]==0&&ans[x-1]-a[j][x]==-1)*/)
                {
                    //if(x==1&&i==1)
                        //cout<<"ahahah"<<'\n';
                    //cout<<"ahahah"<<' '<<x<<' '<<i<<' '<<a[j][x]<<' '<<ans[x-1]<<' '<<a[j][x-1]<<'\n';
                    fff=1;
                    break;
                }
            }
        }
        if(fff)
        {
            for(int j=1;j<=n;j++)
            {
                if(di[j][x]==1)
                    di[j][x]=0,dif[j]--;
            }
            continue;
        }
        ans[x]=i;
        dfs(x+1);
        for(int j=1;j<=n;j++)
        {
            if(di[j][x]==1)
                di[j][x]=0,dif[j]--;
        }
    }
    return;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cin>>a[i][j];
        }

    }
    dfs(1);
    cout<<ahs-n;
    return 0;
}
