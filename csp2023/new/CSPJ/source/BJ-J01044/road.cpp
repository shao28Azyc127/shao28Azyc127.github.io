#include<bits/stdc++.h>
using namespace std;
int a[100005];
int m[100005];
int main()
{ 
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    for(int i = 1;i <= n - 1;i++)
    {
        cin>>a[i];
    }
    for(int i = 1;i <= m;i++)
    {
        cin>>m[i];
    }
    int minn = 0,sum = 0;
    for(int i = 1;i <= n;i++)
    {
        minn = min(minn,m[i]);
        sum += a[i];
    }
    if(minn == m[1]) cout<<minn * sum / d;
    return 0;
}