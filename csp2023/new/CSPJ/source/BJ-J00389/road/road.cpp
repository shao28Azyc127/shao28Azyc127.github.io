#include<iostream>
#include<stdio.h>
using namespace std;
int n,d,sum;
double shengyou=0;
struct lu
{
    int a;
    int v;
    int nxtmin;
}site[100001];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++)
    {
        int b;
        cin>>b;
        site[i+1].v=site[i].v+b;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>site[i].a;
    }
    int num=1;
    for(int i=2;i<=n;i++)
    {
        if((site[i].a<site[num].a)||(i==n))
        {
            int dis=site[i].v-site[num].v;
            int you=int((dis*1.0)/d+0.9999999-shengyou);
            shengyou=you+shengyou-dis*1.0/d;
            sum+=you*site[num].a;
            num=i;
        }
    }
    cout<<sum<<endl;
    return 0;
}
