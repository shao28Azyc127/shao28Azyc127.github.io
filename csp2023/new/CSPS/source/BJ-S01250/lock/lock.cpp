#include<bits/stdc++.h>
using namespace std;
struct node{
    int a[6];
}tt[10];
int now[6];
int ans=0;
int n;
bool check(int key)
{
    int flag=0,id=0;
    for(int i=1;i<=5;i++)
    {
        if(now[i]==tt[key].a[i])
        {
            continue;
        }
        if(id==0)
        {
            flag=(tt[key].a[i]+10-now[i])%10;
            id=i;
            continue;
        }
        if(id!=i-1)
        {
            return false;
        }
        if(flag==(tt[key].a[i]+10-now[i])%10)
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    if(id==0)
    {
        return false;
    }
    return true;
}
void dfs(int len)
{
    if(len==6)
    {
        for(int i=1;i<=n;i++)
        {
            if(check(i)==false)
            {
                return;
            }
        }
        ans++;
        return;
    }
    for(int i=0;i<=9;i++)
    {
        now[len]=i;
        dfs(len+1);
    }
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cin>>tt[i].a[j];
        }
    }
    dfs(1);
    cout<<ans;
    return 0;
}
