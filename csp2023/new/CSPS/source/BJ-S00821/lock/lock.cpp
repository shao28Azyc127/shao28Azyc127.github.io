#include <bits/stdc++.h>
using namespace std;
unordered_map <string,bool> mp;
unordered_map <string,int> ans;
int cnt,n;
void cnt1(string s)
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<=9;j++)
        {
            if(j==s[i]-'0') continue;
            char t=s[i];
            s[i]=char(j+'0');
            if(!mp[s])
            {
                mp[s]=1;
                ans[s]++;
                if(ans[s]==n) cnt++;
            }
            s[i]=t;
        }
    }
}
void cnt2(string s)
{
    for(int i=1;i<5;i++)
    {
        for(int j=1;j<=9;j++)
        {
            char zuo=s[i-1],you=s[i];
            s[i-1]=char((s[i-1]-'0'+j)%10+'0');
            s[i]=char((s[i]-'0'+j)%10+'0');
            if(!mp[s])
            {
                mp[s]=1;
                ans[s]++;
                if(ans[s]==n) cnt++;
            }
            s[i-1]=zuo,s[i]=you;
        }
    }
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int x;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        string s;
        for(int j=0;j<5;j++)
        {
            scanf("%d",&x);
            s=s+char(x+'0');
        }
        mp.clear();
        mp[s]=1;
        cnt1(s),cnt2(s);
    }
    printf("%d\n",cnt);
    return 0;
}