#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans=0;
char s[2000010];
stack<char> st;
bool check(ll l,ll r)
{
    while(!st.empty()) st.pop();
    for(ll i=l;i<=r;i++)
    {
        if(st.empty())
        {
            st.push(s[i]);
            continue;
        }
        if(st.top()==s[i]) st.pop();
        else st.push(s[i]);
    }
    if(st.empty()) return true;
    return false;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%lld%s",&n,s+1);
    for(ll i=1;i<=n;i++)
    {
        for(ll j=i-1;j>=1;j-=2)
            if(check(j,i)) ans++;
    }
    printf("%lld",ans);
    return 0;
}
