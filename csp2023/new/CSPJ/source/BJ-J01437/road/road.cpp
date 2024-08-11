#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    int v[n+5],a[n+5],money = 0,yy = 0,cnt = 0,qwertyuiop;
    for(int i = 1;i < n;i++)
    {
        cin>>v[i];
        cnt += v[i];
    }
    for(int i = 1;i < n;i++)
    {

        cin>>a[i];
    }
    cin>>qwertyuiop;
    if(cnt%d != 0) money = d;
    money += cnt/d*a[1];
    cout<<money;
    return 0;
}
