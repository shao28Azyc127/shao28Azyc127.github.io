#include<bits/stdc++.h>
using namespace std;
int n;
char c[2000005];
bool check(int s,int t)
{
    stack<char> stk;
    for(int i=s;i<=t;i++)
    {
        if(stk.empty())
        {
            stk.push(c[i]);
            continue;
        }
        else if(stk.top()==c[i])
            stk.pop();
        else
            stk.push(c[i]);
    }
    if(stk.empty())
        return true;
    else
        return false;
}
int cle[2000005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    int ans=0;
    if(n<=800)
    {
        for(int len=2;len<=n;len+=2)
        {
            for(int s=1;s<=n-len+1;s++)
            {
                int t=s+len-1;
                ans+=check(s,t);
            }
        }
        cout<<ans;
        return 0;
    }
    stack<char> stk;
    for(int i=1;i<=n;i++)
    {
        if(stk.empty())
        {
            stk.push(c[i]);
            continue;
        }
        else if(stk.top()==c[i])
        {
            stk.pop();
            int k=stk.size();
            ans+=(cle[k+1]+1)*(cle[k+1])/2;
            cle[k+1]=0;
            cle[k]++;
        }
        else
            stk.push(c[i]);
    }
    for(int i=0;i<=n;i++)
        ans+=(cle[i])*(cle[i]+1)/2;
    cout<<ans;
    return 0;
}
