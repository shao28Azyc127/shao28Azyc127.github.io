#include <bits/stdc++.h>

using namespace std;
map <string,int> mp;
int n,ts;
string tt,tc;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    tt.resize(6);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<5;j++)
            cin>>ts,tt[j]=(char)ts+'0';
        tc=tt;
        for(int j=0;j<5;j++)
        {
            char tp=tt[j];
            for(int k=0;k<=9;k++)
                if(k!=tp-'0')
                {
                    tt[j]=(char)k+'0',mp[tt]++;
                }
            tt=tc;
        }
        for(int j=0;j<4;j++)
        {
            int t1=tt[j]-'0',t2=tt[j+1]-'0';
            for(int k=1;k<=9;k++)
            {
                char tx=(t1+k)%10,ty=(t2+k)%10;
                tt[j]=tx+'0',tt[j+1]=ty+'0';
                mp[tt]++;
            }
            tt=tc;
        }
    }
    int ans=0;
    for(auto it:mp)
        if(it.second==n) ans++;
    cout<<ans;
    return 0;
}
