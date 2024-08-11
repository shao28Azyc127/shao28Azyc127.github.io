#include <bits/stdc++.h>
using namespace std;
const int N = 2*1e5+5;
string a;
int n,f,ans;
int nx[N],ny[N];
void dfs(int x,int y)
{
    if(a[x] == a[y]&&x>=1&&y<n-1)
    {
        ans++;
        nx[x]++;
        ny[y]++;
        ans+=nx[x-1];
        ans+=ny[y+1];
        dfs(x-1,y+1);

    }
    else return;
}
void work(int x,int y)
{
    int t = y+1-x,tans;
    tans+=(t-1);
    t--;
    while(t>1)
    {
        tans+=(t-2);
        t-=2;
    }
    ans+=tans;
    nx[x]+=tans;
    ny[y]+=tans;
    if((x-y)%2 == 0)dfs(x-1,y+1);
}

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >> n >> a;
    f = a[0];
    int j = 1;
    for(int i = 1;i<n;i++)
    {
        if(a[i]!=f)
        {
            f = a[i];
            if(j>1) work(i-j,i-1);
            j = 1;
        }
        else j++;

    }
    cout << ans;
    return 0;
}
