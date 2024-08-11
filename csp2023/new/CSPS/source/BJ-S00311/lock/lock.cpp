#include <iostream>
#include <bits/stdc++.h>
#define maxn 9
#define mod 10
#define maxp 10001
using namespace std;
int n,a[maxn][6],ans;
int pool[maxp][6],pcnt;
bool vis[maxp];
void mi(int &x,int y)
{
    x=(x-y+mod)%mod;
    return;
}
void pl(int &x,int y)
{
    x=(x+y)%mod;
    return;
}
void dfs(int ind)
{
    if(ind>n)
    {
        for(int i=1;i<=pcnt;i++)
        {
            if(!vis[i]) ans++;
        }
        return;
    }
    int tmp[6];
    for(int j=1;j<=5;j++)
    {
        tmp[j]=a[ind][j];
    }
    bool t[maxp];
    memset(t,0,sizeof(t));
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=9;j++)
        {
            pl(tmp[i],j);
            if(ind==1)
            {
                ++pcnt;
                for(int k=1;k<=5;k++)
                {
                    pool[pcnt][k]=tmp[k];
                }
            }
            else
            {

                for(int k=1;k<=pcnt;k++)
                {
                    if(!vis[k])
                    {
                        bool tag2=true;
                        for(int s=1;s<=5;s++)
                        {
                            tag2&=(pool[k][s]==tmp[s]);
                        }
                        if(tag2) t[k]=true;
                    }
                }
            }
            mi(tmp[i],j);
        }
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=9;j++)
        {
            pl(tmp[i],j);
            pl(tmp[i+1],j);
            if(ind==1)
            {
                ++pcnt;
                for(int k=1;k<=5;k++)
                {
                    pool[pcnt][k]=tmp[k];
                }
            }
            else{
                for(int k=1;k<=pcnt;k++)
                {
                    if(!vis[k])
                    {
                        bool tag2=true;
                        for(int s=1;s<=5;s++)
                        {
                            tag2&=(pool[k][s]==tmp[s]);
                        }
                        if(tag2) t[k]=true;
                    }
                }
            }
            mi(tmp[i],j);
            mi(tmp[i+1],j);
        }
    }
    if(ind!=1)
    {
        for(int k=1;k<=pcnt;k++)
        {
            if(!t[k]) vis[k]=true;
        }
    }
    dfs(ind+1);
    return;
}
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
        }
    }
    dfs(1);
    cout<<ans;
    return 0;
}
