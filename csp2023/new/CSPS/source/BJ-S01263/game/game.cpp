#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define per(i,a,b) for (int i=(a);i>=(b);i--)

#define N int(2e6+10)

int n;
char s[N];
ll ans[N];
int nxt[N];
void work(int l)
{
    if (~ans[l]) return;
    stack<char> sk;
    rep (i,l,n)
    {
        if (sk.size()&&sk.top()==s[i]) sk.pop();
        else sk.push(s[i]);
        if (sk.empty())
        {
            nxt[l]=i;
            break;
        }
    }
    if (nxt[l]) 
    {
        work(nxt[l]+1);
        ans[l]=ans[nxt[l]+1]+1;
    }
    else ans[l]=0;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n>>(s+1);
    memset(ans,-1,sizeof ans);
    ll res=0;
    rep (i,1,n) 
    {
        work(i);
        //cerr<<i<<": "<<ans[i]<<'\n';
        res+=ans[i];
    }
    cout<<res;
    return 0;
}