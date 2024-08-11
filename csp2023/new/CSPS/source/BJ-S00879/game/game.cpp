#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool chk(string s)
{
    if(s.size()==1) return false;
    ll d=s.size();
    for(ll i=0;i<d;i++)
    {
        if(!s.size())
        {
            return true;
        }
        ll l=s.size();
        for(ll j=0;j<l-1;j++)
        {
            if(s[j]==s[j+1])
                s.erase(j,2);
        }
    }
    return false;
}

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    string s;
    ll ans=0,n;
    cin>>n>>s;
    for(int i=0;i<s.size();i++)
    {
        for(int j=2;j<=s.size()-i;j++)
        {
            string d=s.substr(i,j);
            if(chk(d))
            {
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
