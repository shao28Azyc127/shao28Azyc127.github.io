#include<bits/stdc++.h>
#define int long long
using namespace std;
long long n,op,m;
string s,s1,s2;
map<string,long long> mp;
signed main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ios::sync_with_stdio(0);

    cin>>n;
    s="long";mp[s]=8;
    s="int";mp[s]=4;
    s="short";mp[s]=2;
    s="byte";mp[s]=1;
    for(int i=1;i<=n;i++)
    {
        cin>>op>>s>>m;
        int num=0,mx=0;
        for(int j=1;j<=m;j++)
        {
            cin>>s1>>s2;
            num+=mp[s1];
            mx=max(mx,mp[s1]);
        }
        if(num%mx!=0) num=(num/mx+1)*mx;
        mp[s]=num;
        cout<<num<<" "<<mx<<"\n";
    }

    cout<<endl;
    return 0;
}
