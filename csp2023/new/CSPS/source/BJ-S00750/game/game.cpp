#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
#define int long long
const int N = 805;
int n,ans;
string s,a[N];
bool chk(string k)
{
    k += " ";
    bool flag = 1;
    int tot = 0;
    while(flag)
    {
        tot++;
        if(tot>50) break;
        flag = 0;
        //cout << k.size() << endl;
        for(int i = 0;i<k.size()-1;i++)
            if(k[i]==k[i+1])
            {
                flag = 1;
                k = k.substr(0,i)+k.substr(i+2);
                break;
            }
        if(k==" ")
            return 1;
    }
    return 0;
}
void solve(int len)
{
    int c = 0;
    for(int i = 0;i<s.size();i++)
    {
        string t = "";
        if(i+len-1>=n) break;
        for(int j = i;j<=i+len-1;j++)
            t += s[j];
        a[++c] = t;
    }
    for(int i = 1;i<=c;i++)
        if(chk(a[i]))
            ans++;
}
signed main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s;
    for(int i = 1;i<=s.size();i++)
        solve(i);
    cout << ans << endl;
    return 0;
}
