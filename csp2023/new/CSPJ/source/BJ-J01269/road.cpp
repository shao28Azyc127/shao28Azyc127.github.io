#include<iostream>
#include<cstdio>
using namespace std;
long long arr[100010];
int up(double a)
{
    int b=a;;
    if(a>b)
    {
        return b+1;
    }
    return b;
}
int main()
{
    long long s=0                       ;
    long long a,zuixiao=1e17,q;
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,d,he=0,far,now=1;
    cin>>n>>d;
    arr[1]=0;
    for(int i=2;i<=n;i++)
    {
        cin>>arr[i];
        arr[i]=arr[i-1]+arr[i];
    }
    cin>>zuixiao;
    for(int i=2;i<n;i++)
    {
        cin>>a;
        if(a<zuixiao)
        {

            q+=up(((arr[i]-arr[now]-s)*1.0)/d)*zuixiao;
            s=(arr[i]-arr[now]-s)%d;
            zuixiao=a;
            now=i;


        }
    }
    q+=up(((arr[n]-arr[now]-s)*1.0)/d)*zuixiao;
    cin>>a;
    cout<<q;
    return 0;
}
