#include<bits/stdc++.h>
using namespace std;
int a[100005],v[100005],n,d;
int ans=0,l=0,len[100005],ll=0;
void dfs(int start)
{
    int e=-1;
    for(int i=start;i<n;i++)
    {
        if(a[i]<a[start])
        {
            e=i;
            break;
        }
    }
    if(e==-1)
    {
        int num=(l+d-1)/d;
        ans+=num*a[start];
        //cout<<ans<<endl;
        return ;
    }else
    {
        int l1=0;
        for(int i=start+1;i<=e;i++)
        {
            l1+=v[i];
        }
        int num=(l1+d-1-(ll-len[start]))/d;
        ans+=min(num*a[start],(l+d-1)/d*a[start]);
        l-=num*d;
        ll+=num*d;
        //cout<<ans<<endl;
        dfs(e);
    }
    return ;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++)
    {
        cin>>v[i];
        l+=v[i];
        len[i]=l;
    }
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    dfs(0);
    cout<<ans;
    return 0;
}
