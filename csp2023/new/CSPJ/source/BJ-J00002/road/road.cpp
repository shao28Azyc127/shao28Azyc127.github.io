#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int n,d,a[100005],minn = 2e9,lu,ans,q[100005];

struct node
{
    int id,v;
}b[100005];
bool cmp(node x,node y)
{
    if(x.v  != y.v)return x.v > y.v;
    return x.id <= y.id;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >>n >>d;
    for(int i = 1;i <= n - 1;i++)
    {
        cin >> a[i];
    }

    for(int i = 1;i <= n;i++)
    {
        cin>>b[i].v;
        b[i].id = i;
    }
    for(int i = 1;i <= n;i++)
    {
        if(b[i].v < minn)
        {
            minn = b[i].v;
        };
        lu += (a[i] + d - 1) / d * d;
        ans += (a[i] + d - 1) / d * minn;

    }
    cout <<ans << endl;
}
