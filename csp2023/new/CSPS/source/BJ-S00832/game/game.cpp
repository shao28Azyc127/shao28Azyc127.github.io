#include<bits/stdc++.h>
using namespace std;
int n; string s;
int a[2000010];
stack<int> st;
int qzh[2000010];
map<int,int> vis;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s; s=' '+s;
    for(int i=1; i<=n; ++i) a[i]=s[i]-'a';
    if(n<=8000)
    {
        long long ans=0;
        for(int i=1; i<=n; ++i)
        {
            while(!st.empty()) st.pop();
            for(int j=i; j<=n; ++j)
            {
                if(!st.empty() && a[st.top()]==a[j]) st.pop();
                else st.push(j);
                ans+=st.empty();
            }
        }
        cout<<ans;
    }
    else
    {
        int len=min(500,n);
        long long ans=0;
        for(int i=1; i<=n; ++i)
        {
            while(!st.empty()) st.pop();
            for(int j=i; j<=min(i+len-1,n); ++j)
            {
                if(!st.empty() && a[st.top()]==a[j]) st.pop();
                else st.push(j);
                ans+=st.empty();
            }
        }
        for(int i=1; i<=n; ++i) qzh[i]=qzh[i-1]^(1<<a[i]);
        for(int i=1; i<=n; ++i)
        {
            if(i-len-1>=0) ++vis[qzh[i-len-1]];
            ans+=vis[qzh[i]];
        }
        cout<<ans;
    }
    return 0;
}
