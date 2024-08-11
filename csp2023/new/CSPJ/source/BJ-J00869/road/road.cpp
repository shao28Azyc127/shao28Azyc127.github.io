#include<bits/stdc++.h>
using namespace std;
int a[100010],v[100010];
long long s[100010];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    unsigned long long n,d,ans=0,cnt=0,tmp,x,i=1;
    cin>>n>>d;
    for(int i=1;i<n;i++)
    {
        scanf("%d",&v[i]);
        s[i]=s[i-1]+v[i];
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    while(cnt<s[n-1])
    {
        for(int j=i;j<=n;j++)
        {
            if(a[i]>a[j])
            {
                tmp=j;
                break;
            }
        }
        if((s[tmp-1]-cnt)%d==0)x=(s[tmp-1]-cnt)/d;
        else x=(s[tmp-1]-cnt)/d+1;
        ans+=x*a[i];
        cnt+=x*d;
        i=tmp;
    }
    cout<<ans;
    return 0;
}
