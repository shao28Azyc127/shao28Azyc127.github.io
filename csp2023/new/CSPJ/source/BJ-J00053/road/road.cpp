#include <bits/stdc++.h>
using namespace std;
int sum,ans,top=1,minn[100005],l[100005],a[100005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,x;
    cin >> n >> m;
    for(int i=2;i<=n;i++)
    {
        cin >> x;
        l[i]=l[i-1]+x;
    }
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int i=1;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[i])
            {
                minn[i]=j;
                break;
            }
        }
        if(minn[i]==0)
        {
            break;
        }
    }
    while(top<n)
    {
        if(minn[top])
        {
            if((l[minn[top]]-sum)%m==0)
            {
                ans+=((l[minn[top]]-sum)/m)*a[top];
                sum+=l[minn[top]]-sum;
            }
            else
            {
                ans+=((l[minn[top]]-sum)/m+1)*a[top];
                sum+=((l[minn[top]]-sum)/m+1)*m;
            }
            top=minn[top];
        }
        else
        {
            if((l[n]-sum)%m==0)
            {
                ans+=((l[n]-sum)/m)*a[top];
            }
            else
            {
                ans+=((l[n]-sum)/m+1)*a[top];
            }
            break;
        }
    }
    cout << ans;
    return 0;
}
