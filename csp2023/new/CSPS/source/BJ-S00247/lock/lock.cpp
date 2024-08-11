#include<bits/stdc++.h>
using namespace std;
int n,ans;
vector<int>v[10];
map<vector<int>,int>s;
void solve()
{
    for(int i=1;i<=n;i++)
    {
        vector<int>tmp=v[i];
        for(int j=0;j<5;j++)
        {
            for(int k=1;k<=9;k++)
            {
                tmp[j]+=k,tmp[j]%=10;
                s[tmp]++;
                if(s[tmp]==n)ans++;
                tmp[j]=v[i][j];
            }
        }
        for(int j=0;j<4;j++)
        {
            for(int k=1;k<=9;k++)
            {
                tmp[j]+=k,tmp[j]%=10;
                tmp[j+1]+=k,tmp[j+1]%=10;
                s[tmp]++;
                if(s[tmp]==n)ans++;
                tmp[j]=v[i][j],tmp[j+1]=v[i][j+1];
            }
        }
    }
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1,x;j<=5;j++)
        {
            cin>>x;
            v[i].push_back(x);
        }
    }
    solve();
    cout<<ans<<'\n';
    return 0;
}
