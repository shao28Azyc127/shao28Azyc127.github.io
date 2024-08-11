#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

const int MAX=4e4+6e3+3e2+3e1+6;
int n;
long long ans;
long long l[MAX];

bool flag[MAX][MAX];

const long long P=107374122433554436,D=13331;



long long ti(int f)
{
    return l[f]-(l[f-1]*D)%P;
}

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    string m;
    cin>>m;
    m="#"+m;
    for(int i=1;i<=n;i++)
    {
        l[i]=((l[i-1]*D)%P+m[i])%P;
    }
    for(int i=1;i<=n-1;i++)
    {
        //j'-j=i
        for(int j=1;j<=n-i;j++)
        {
            if(!flag[j][j+i])
            {
                if(i==1)
                {
                    if(ti(j)==ti(i+j))
                    {
                        flag[j][i+j]=true;
                        ans++;
                    }
                }
                else
                {
                    if(j>2)
                    {
                        if(flag[j][j+1]&&flag[j+2][i+j]&&!flag[j][j+i])
                        {
                            flag[j][i+j]=true;
                            ans++;
                        }
                    }
                    if(i+j+2<n)
                    {
                        if(flag[j][i+j-2]&&flag[i+j-1][i+j]&&!flag[j][j+i])
                        {
                            flag[j][i+j]=true;
                            ans++;
                        }
                    }
                    if(j>1&&j+i+1<n)
                    {
                        if(ti(j)==ti(i+j)&&flag[j+1][i+j-1]&&!flag[j][j+i])
                        {
                            flag[j][i+j]=true;
                            ans++;
                            printf("&&&");
                        }
                    }
                }
            }
        }

    }
    cout<<ans;
    return 0;
}
