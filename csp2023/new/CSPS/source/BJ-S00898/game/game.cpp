#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
string s;
int n;
long long sum;
//int nxt[2000005];
int top;
bool can(string s)
{
string stk="";
    for(int i=1;i<=s.size();i++)
        if(stk==""||stk[stk.size()-1]!=s[i-1])
            stk+=s[i-1];
        else
            stk=stk.substr(0,stk.size()-1);
    return stk=="";
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin>>n>>s;
    s='@'+s+'#';
    for(int i=2;i<=n;i+=2)
        for(int j=1;j+i-1<=n;j++)
            sum+=can(s.substr(j,i));
    cout<<sum;
    return 0;
}
