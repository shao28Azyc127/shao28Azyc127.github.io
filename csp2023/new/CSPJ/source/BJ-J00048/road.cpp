#include<bits/stdc++.h>
using namespace std;
int n,d;
int v[100001],a[100001];
int sum,total,lu,z,cnt=1;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++)
    {
        cin>>v[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<n;i++)
    {
        if(z!=0&&z!=-1)
        {
            i=z;
        }
        if(z==-1)
        {
            break;
        }
        sum=v[i]-lu;
        cnt=0;
        z=-1;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[i])
            {
                z=j;
                break;
            }
            sum+=v[j];
        }
        lu=0;
        while(lu<sum)
        {
            lu+=d;
            cnt++;
        }
        lu=d*cnt-sum;
        total+=a[i]*cnt;
    }
    cout<<total<<endl;
    return 0;
}
