#include<bits/stdc++.h>
using namespace std;
int n,d,a[10010];
long long gl=0,zj=0;
int minn=1e9;
int k;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        minn=min(minn,k);
        int t=0;
        while(d*t+gl<a[i])
        {
            t++;
        }
        zj+=t*minn;
        gl=(d*t+gl)-a[i];
    }
    cout<<zj;
    return 0;
}


/*
5 4
10 10 10 10
9 8 9 6 5
*/
