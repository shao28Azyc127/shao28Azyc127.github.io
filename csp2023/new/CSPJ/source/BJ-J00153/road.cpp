#include <cstdio>
#include <algorithm>
#include<iostream>
using namespace std;

int cnt;
struct m
{
    int p,a;
};
m q[100003];
m w[100003];
int v[100003];
int sum=0;
bool cmp(m x,m y)
{
    return x.a<y.a;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    for(int i=1;i<=n-1;i++)
    {
        cin>>v[i];
        sum+=v[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>q[i].a;
        q[i].p=i;
    }
    int l=v[1]/d+1;
    cout<<l*q[1].a;

}
