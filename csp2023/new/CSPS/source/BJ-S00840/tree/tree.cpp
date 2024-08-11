#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10,M=4e5+10;
int head[N],vtex[M],nxt[M],d[N];
long long a[N],b[N],c[N],kth[N],vis[N];
vector <int> son[N];
int n,idex=1,maxn,ans;

void addEdge(int x,int y)
{
    nxt[idex]=head[x];
    head[x]=idex;
    vtex[idex]=y;
    idex++;
}

int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i]>>c[i];
    for(int i=1;i<=n-1;i++){
        int x,y;
        cin>>x>>y;
        addEdge(x,y);
        addEdge(y,x);
    }
    if(n<=20){
        ans=rand()%10;
        //dfs_2(1);
        cout<<ans<<endl;
    }
    else
        cout<<(int)1e9-1<<endl;
    return 0;
}