#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll ans;
string s;
bool check(int l,int r)
{
    stack<int> st;
    for(int i=l;i<=r;i++)
    {
        if(!st.size() || (st.size() && s[st.top()]!=s[i]))
        {
            st.push(i);
        }
        else
        {
            st.pop();
        }
    }
    return st.size()==0;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s;
    for(int i=0;i<s.length();i++)
    {
        for(int j=i+1;j<s.length();j++)
        {
            if(check(i,j))
            {
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
