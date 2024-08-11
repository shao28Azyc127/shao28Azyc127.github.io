#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
string s;
int n;
struct node
{
    int l,r;
    bool operator< (const node &a)
    const{
        if(l!=a.l)return l<a.l;
        return r<=a.r;
    }
};
vector<node> p;
set<long long> check;
vector<int> l[maxn],r[maxn];
queue<int> q;
int tot=0;
void work()
{
    for(int i=1;i<n;++i)
    {
        if(s[i]==s[i+1])
        {
            check.insert((long long)i*n+i+1);
            p.push_back({i,i+1});
            l[i].push_back(tot);
            r[i+1].push_back(tot);
            q.push(tot);
            tot++;
        }
    }
    while(!q.empty())
    {
        node k=p[q.front()];
        q.pop();
        for(int i=0;i<l[k.r+1].size();++i)
        {
            int ls=k.l,rs=p[l[k.r+1][i]].r;
            if(!check.count((long long)ls*n+rs))
            {
                check.insert((long long)ls*n+rs);
                p.push_back({ls,rs});
                l[ls].push_back(tot);
                r[rs].push_back(tot);
                q.push(tot);
                tot++;
            }
        }
        int ls=k.l,rs=k.r;
        while(s[ls-1]==s[rs+1])
        {
            ls--,rs++;
            if(!check.count((long long)ls*n+rs))
            {
                check.insert((long long)ls*n+rs);
                p.push_back({ls,rs});
                l[ls].push_back(tot);
                r[rs].push_back(tot);
                q.push(tot);
                tot++;
            }
        }
    }
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>s;
    s=' '+s;
    work();
    cout<<check.size();
    return 0;
}
