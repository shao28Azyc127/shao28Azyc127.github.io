#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
const int MAX=3e4+5;

char r;
int n,m,cnt[MAX][30];

bool check(int x)
{
    for(int i=1;i<=n;i++)
    {
        if(i!=x)
        {
            bool flag=false;
            for(int j=1;j<=26;j++)
            {
                if(cnt[x][j]!=0)
                {
                    for(int k=26;k>=1;k--)
                    {
                        if(cnt[i][k]!=0)
                        {
                            if(j>k)
                            {
                                return false;
                            }
                            else if(j<k)
                            {
                                flag=true;
                            }
                            else
                            {
                                return false;
                            }
                            if(flag)
                            {
                                break;
                            }
                        }
                    }
                }
                if(flag)
                {
                    break;
                }
            }
        }
    }
    return true;
}

int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>r;
            cnt[i][r-'a'+1]++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(check(i))
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
    }
    return 0;
}

