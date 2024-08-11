#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
using namespace std;
map<string,int> vis;//1->yes;-1->no
int n,cnt;
string s;
bool dfs(string t)
{
    int m=t.size();
    if(m%2!=0) return false;
    if(m==2&&t[0]==t[1]) return true;
    if(vis[t]==1) return true;
    if(vis[t]==-1) return false;
    bool flag=false;
    if(t[0]==t[1]) flag|=dfs(t.substr(2));
    for(int i=1;i<=m-3;i++)
    {
        if(t[i]==t[i+1]) flag|=dfs(t.substr(0,i)+t.substr(i+2));
    }
    if(t[m-2]==t[m-1]) flag|=dfs(t.substr(0,m-2));
    if(flag) vis[t]=1;
    else vis[t]=-1;
    return flag;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>s;
    if(n%2!=0)
    {
        cout<<0<<endl;
        return 0;
    }
    vis[""]=1;
    for(int i=0;i<=n-1;i++)
        for(int j=1;j<=n-i;j++)
            cnt+=dfs(s.substr(i,j));
    cout<<cnt<<endl;
    return 0;
}
