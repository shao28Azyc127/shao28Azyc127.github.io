#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const ll N=1e6;
ll n,cnt,head=1,ans,res;
struct Node
{
    ll id,pre,nex;
}sz[N+5];
void Delete(ll i)
{
    if(i==head)
    {
        head=sz[i].nex;
    }
    sz[sz[i].pre].nex=sz[i].nex;
    sz[sz[i].nex].pre=sz[i].pre;
    cnt++;
}
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
    {
        sz[i].id=i,sz[i].pre=i-1,sz[i].nex=i+1;
    }
    while(cnt<n)
    {
        ans++;//cout<<ans<<endl;
        for(ll i=head;i!=n+1;)
        {
            if(sz[i].id==n) res=ans;//,cout<<ans<<endl;
            Delete(i);
            //cout<<i<<" ";
            if(sz[i].nex!=n+1)
                i=sz[i].nex;
            else break;
            if(sz[i].nex!=n+1)
                i=sz[i].nex;
            else break;
            if(sz[i].nex!=n+1)
                i=sz[i].nex;
            else break;
        }//cout<<ans<<" "<<cnt<<endl;
        //cout<<endl;
    }
    printf("%lld %lld",ans,res);
    return 0;
}
