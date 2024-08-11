#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int v[1e5+5],a[1e5+5];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,res=0;
    float rem=0,dis=0,d;
    cin>>n>>d;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int min_=a[0];
    for(int i=0;i<n-1;i++)
    {
        dis+=v[i];
        if(a[i]<min_)
        {
            min_=a[i];
            res+=max(0,ceil(dis/d-rem));
            if(rem*d>dis){rem=(rem*d-dis)/d;}
            else rem=(rem*d-dis+ceil(dis/d-rem)*d)/d;
            dis=0;
        }
    }
    res+=ceil(dis/d-rem);
    cout<<res;
    return 0;
}