#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,v[100010],a[100010],d,minn=1e9,tot;
int f[100010],s[100010];
void dfs(int step,int sum,int res)
{
    if(sum>minn) return;
    if(step==n)
    {
        minn=min(minn,sum);
        return;
    }
    for (int i=max((v[step]-res)/d,0);i<=tot/d+1;i++)
    {
        if(res+i*d<v[step]) continue;
        dfs(step+1,sum+i*a[step],res+i*d-v[step]);
    }
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >>n>>d;
    int minnn=1e9,minid=0;
    bool flag=1;
    for (int i=1;i<n;i++){
            cin >>v[i],tot+=v[i];
            if(v[i]%d!=0) flag=0;
            s[i]=s[i-1]+v[i];
    }
    for (int i=1;i<=n;i++) {
        cin >>a[i];
        if(a[i]<minnn)
        {
            minnn=a[i];
            minid=i;
        }
    }
    f[1]=a[1];
    for (int i=2;i<=n;i++)
    {
        f[i]=min(f[i-1],a[i]);
        //cout<<f[i]<<" ";
    }

    if(minid==1)
    {
        cout<<(tot+d-1)/d*a[1];
        return 0;
    }
    if(flag==1)
    {

        int sum=0;
        for (int i=1;i<n;i++)
        {
            sum+=f[i]*v[i]/d;
        }
        cout<<sum;
        return 0;
    }
    int res=0,sum=0;
    for (int i=1;i<n;i++)
    {
        sum+=(v[i]-res+d-1)/d*f[i];

        res=(v[i]-res+d-1)/d*f[i]/f[i]*d+res-v[i];

    }
    cout<<sum;
    return 0;
}
