#include<iostream>
#include<cstdio>
using namespace std;

bool vis[1000100];
bool isq(int n)
{
    for (int i=1;i<=n;i++)
    {
        if(!vis[i]) return 0;
    }
    return 1;
}
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,cur=0,id=0;
    cin >>n;
    while(!isq(n))
    {
        cur++;
        int a=cur;
        while(vis[a]) a++;
        vis[a]=1;
        int cnt=0;
        for (int i=a;i<=n;i++)
        {
            if(!vis[i]) cnt++;
            cnt%=3;
            //cout<<cnt<<" "<<i<<" "<<cur<<endl;
            if(cnt==0) vis[i]=1;
        }
        if(vis[n]&&!id) id=cur;
    }
    cout<<cur<<" "<<id;
    return 0;
}