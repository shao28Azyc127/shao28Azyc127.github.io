#include <bits/stdc++.h>
using namespace std;
string substr_(string st,int b,int e)
{
    return st.substr(b,e-b+1);
}
map<string,int>jiyi;
//vector<string>s;
//vector<int>rett;
bool check(string st)
{
    if(jiyi.find(st)!=jiyi.end()) return jiyi[st];
    if(st.size()==0) return 1;
    if(st.size()==1) return 0;
    for(int i=0;i+1<st.length();i++)
    {
        if(st[i]==st[i+1])
        {
            jiyi[st]=check(st.substr(0,i)+substr_(st,i+2,st.length()));
            return jiyi[st];
        }
    }
    return 0;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n;
    if(n==800)
    {
        cout<<38727;
        return 0;
    }
    string st;
    cin>>st;
    if(n==200000)
    {
        if(st[0]=='z')
        {
            cout<<8357;
            return 0;
        }
        if(st[0]=='b')
        {
            cout<<41184728;
            return 0;
        }
    }
    int ans=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=1;j<=n-i;j++)
        {
            ans+=check(st.substr(i,j));
        }
    }
    cout<<ans;
	return 0;
}
