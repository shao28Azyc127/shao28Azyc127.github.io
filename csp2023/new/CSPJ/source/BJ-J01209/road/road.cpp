#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
long long n,d,v[100005],a[100005],sv[100005],sum;
bool flag[100005];
long long ans;
struct node{
    int a,id;
}x[100005];
bool cmp(node s,node t)
{
    if(s.a!=t.a) return s.a<t.a;
    return s.id<t.id;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long minn=9e18;
    cin>>n>>d;
    for(int i=1;i<n;i++)
    {
        cin>>v[i];
        sum+=v[i];
    }
    for(int i=1;i<n;i++) sv[i+1]=sv[i]+v[i];
    for(int i=1;i<=n;i++)
    {
        cin>>x[i].a;
        x[i].id=i;
        minn=min(minn,x[i].a);
    }
    if(minn==x[1].a)
    {
        cout<<ceil(1.0*sum/d)*x[1].a<<endl;
        return 0;
    }
    sort(x+1,x+n+1,cmp);
    int k=1;
    while(true)
    {
        if(k>n) break;
        int p=x[k].a;
        while(x[k+1].a==p)
        {
            flag[k+1]=true;
            k++;

        }
        k++;

    }
    int pos;
    for(int i=1;i<=n;i++)
    {

        if(x[i].id==1)
        {
            pos=i;
            break;
        }
    }
    double left=0;
    int i=pos;
    while(i>=1)
    {
        int pos2;
        if(i==1)
        {
            ans+=ceil(1.0*(sv[n]-sv[x[i].id]-left)/d)*x[i].a;
        }
        int j=i-1;

        while(true)
        {
            if(!flag[j])
            {
                pos2=j;
                break;
            }
        }
        while(sv[x[pos2].id]-sv[x[i].id]<=0)
        {
            i=pos2;
            j=i-1;
            while(true)
            {
                if(!flag[j])
                {
                    pos2=j;
                    break;
                }
            }

        }
        if(ceil(1.0*(sv[x[pos2].id]-sv[x[i].id]-left)/d)*x[i].a<0)
        {
            continue;
        }

        ans+=ceil(1.0*(sv[x[pos2].id]-sv[x[i].id]-left)/d)*x[i].a;
        left=(ceil(1.0*(sv[x[pos2].id]-sv[x[i].id]-left)/d)*d)-(1.0*(sv[x[pos2].id]-sv[x[i].id]-left));
        i=pos2;
    }
    cout<<ans<<endl;
    return 0;
}
