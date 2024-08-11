#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N=2e6+10;
bool a[N];
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ll n,ans=0;
    cin>>n;
    string s;
    cin>>s;
    for(ll i=0;i<n;i++)
    {
        for(ll j=i;j<n;j++)
        {
            memset(a,0,sizeof(a));
            ll l=j-i+1;
            ll cnt=0,res;
            while(cnt<l)
            {
                res=cnt;
                char last='.';
                ll o=-1;
                for(ll k=i;k<=j;k++)
                {
                    if(a[k]==1) continue;
                    else
                    {
                        if(last==s[k])
                        {
                            cnt+=2;
                            a[o]=1;
                            a[k]=1;
                            last='.';
                            o=-1;
                        }
                        else
                        {
                            last=s[k];
                            o=k;
                        }
                    }
                }
                if(cnt==l)
                {
                    ans++;
                    break;
                }
                if(cnt==res) break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
