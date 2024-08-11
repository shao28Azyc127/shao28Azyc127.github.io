#include<bits/stdc++.h>
using namespace std;

int fa[114514];
vector<int>bian[114514];
long long t[114514];
long long a[114514];
long long b[114514];
long long c[114514];

int book[114514];
int bk[114514];
long long dep[114514];
long long be[114514];
    int n;


void dfs(int i,int f)
{
    fa[i]=f;
    dep[i]=book[i]?0:dep[f]+1;
    for(auto v:bian[i])
        if(v!=f)
            dfs(v,i);
}

int tim=0;

void update(int a)
{
    if(book[a])return;
    book[a]=1;
    be[a]=tim+dep[a];
    update(fa[a]);
}

void work1()
{
    for(int i=1;i<=n;i++)t[i]=(long long)(ceil(a[i]*1.0/b[i]));

    dfs(1,0);
    
    for(int i=1;i<=n;i++)
    {

        int maxn=0,maxi;
        for(int i=1;i<=n;i++)  
            if(bk[i]==0&&maxn>t[i]+dep[i])
                maxn=t[i]+dep[i],maxi=i;
        if(maxn==0)break;
        update(maxi);
        tim+=dep[maxi];
        dfs(1,0);
        bk[maxi]=1;
    }
    long long ans=0;
    
    for(int i=1;i<=n;i++)ans=max(ans,be[i]+t[i]);
    cout<<ans<<'\n';
}

int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];

    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        bian[x].push_back(y);
        bian[y].push_back(x);
    }
    
    if(n<1000)work1();
    //else work2();
}
/*
死了
要AFO了
祝我们的WCK大佬AKIOI


T4的BC没搞出来啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊
114514
1919810


**** ***！

要是一等了我表白！！！
希望奇葩代码大赏带我进去。

biiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii

//freopen

*/