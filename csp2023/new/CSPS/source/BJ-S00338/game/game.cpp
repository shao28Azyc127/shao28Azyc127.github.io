#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
int n,ans;
string s;
stack<char> t;
inline bool ifclear(int x,int y)
{
    if(x>=y)
        return 0;
    while(!t.empty())
        t.pop();
    for(register int i=x;i<=y;i++)
    {
        if(!t.empty() && t.top()==s[i])
            t.pop();
        else
            t.push(s[i]);
    }
    return t.empty();
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >> n >> s;
    s='$'+s;
    for(register int i=1;i<=n;i++)
        for(register int j=i+1;j<=n;j+=2)
            if(ifclear(i,j))
                ans++;
    cout << ans << endl;
    return 0;
}
