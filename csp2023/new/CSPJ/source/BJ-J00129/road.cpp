#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int a[10010];
int y[10010];
int miny=999999,cnt=0,maxl;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,o;
    cin>>n>>d;
    o=n;
    for(int i = 1;i <= n-1;i++)
    {
        cin>>a[i];
        maxl+=a[i];
    }
    for(int i = 1;i <= n;i++)
    {
        cin>>y[i];
        miny=min(y[i],miny);
    }
    if(miny==y[1]&&maxl%d==0)
    {
        cnt=maxl/d*miny;
        cout<<cnt;
        return 0;
    }
    else if(miny==y[1]&&maxl%d!=0)
    {
        cnt=maxl/d*(miny+1);
        cout<<cnt;
        return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}