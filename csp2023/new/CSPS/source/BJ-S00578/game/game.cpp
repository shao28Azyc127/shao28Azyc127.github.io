#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool check(string s)
{
    bool flag=0;
    while(s.size())
    {
        flag=0;
        for(int i=0;i<s.size();i++)
        {
            if(i+1!=s.size() &&  s[i]==s[i+1])
            {
                flag=1;
                s.erase(i,2);
                i-=2;
            }
        }
        if(!flag) return 0;
    }
    return 1;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ll n,ans=0;
    string s,ss;
    cin>>n>>s;
    for(int i=0;i<n;i++)
    {
        ss=s[i];
        for(int j=i+1;j<n;j++)
        {
            ss+=s[j];
            if(check(ss)) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}