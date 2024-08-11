#include<bits/stdc++.h>
using namespace std;
const int N=10010;
double n,d;
double ab[N],money[N];
int find(int now)
{

    for(int i=now+1;;i++)
    {
        if(i>=n)return n-1;
        if(money[i]<money[now])return i;
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++)cin>>ab[i];
    for(int i=0;i<n;i++)cin>>money[i];
    int now=0,ans=0;
    double len=0;
    for(int a=0;a<n;a++)
    {
        int next=find(now);
        for(int i=now+1;i<=next;i++)len+=ab[i];
        ans=ans+(len/d)*money[now];
        len=0;
        now=next;
        if(now>=n)break;
    }
    cout<<ans;
    return 0;
}
