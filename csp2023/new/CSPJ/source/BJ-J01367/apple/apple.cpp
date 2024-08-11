#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
queue<int>q;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,cnt=0,res,i;
    cin>>n;
    for(i=1;i<=n;i++)
        q.push(i);
    i=1;
    while(!q.empty())
    {
        int p,f;
        p=q.front();
        q.pop();
        if((i-1)%3==0&&p==n)
            res=cnt;
        f=q.front();
        if((i-1)%3!=0)
            q.push(p);
        if(f<p)cnt++;
        i++;
    }
    cout<<cnt<<res;
    return 0;
}