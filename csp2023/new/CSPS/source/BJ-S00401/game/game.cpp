#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll maxx=INT_MIN;
ll minn=INT_MAX;
const ll N=0;
ll n;
int a[999];
bool check1(string s)
{
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!='9')return 1;
    }
    return 0;
}
bool check(string s)
{
    if(s.size()%2==1)return 0;
    if(s.empty())return 0;
    while(check1(s))
    {
        bool f=1;
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i]=='9')continue;
            int k=i+1;
            while(k!=s.size()&&a[k]!='9')
            {
                k++;
            }
            if(s[k]==s[i])s[k]='9',s[i]='9';
        }
    }
    return 1;
}
string s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n;
    cin>>s;
    int ans=0;
    for(int i=0;i<s.size();i++)
    {
        for(int j=i+1;j<s.size();j++)
        {
            string s1;
            int l=0;
            for(int k=i;k<=j;k++)s1[l++]=s[k];
            if(check(s1))
            {
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
/*
8
accabccb
*/
