#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
char a[2000010];
bool f[8010][8010];
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)f[i+1][i]=1;
    for(int len=2;len<=n;len++)
    {
        for(int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1;
            if(a[i]==a[j])f[i][j]|=f[i+1][j-1];
            for(int k=i+1;k<j;k++)
            {
                f[i][j]|=f[i][k]&&f[k+1][j];
            }
            if(f[i][j]==1)cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}