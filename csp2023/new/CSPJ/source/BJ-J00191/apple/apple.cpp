#include <bits/stdc++.h>
using namespace std;
int n;
int dfs(int x)
{
    if(x==1) return 1;
    if(x==2) return 2;
    if(x==3) return 3;
    if(x%3!=0)
    {
        int i=x/3+1;
        return 1+dfs(x-i);
    }
    else
    {
        int i=x/3;
        return 1+dfs(x-i);
    }
}
int count(int st)
{
    if(st%3==1) return 1;
    else if(st%3==2) return 1+count(st-(st/3+1));
    else return 1+count(st-(st/3));
}
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    cout<<dfs(n)<<" ";
    if(n%3==1)
    {
        cout<<1;
    }
    else
    {
        cout<<count(n);
    }
    return 0;
}