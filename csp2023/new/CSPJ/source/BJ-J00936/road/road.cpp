#include <bits/stdc++.h>
#define N 100005
using namespace std;
int n,d;
int v[N],a[N];
int dp[N];
int s[N]{INT_MAX};//dandiaoxing
int sv[N];//qianzhuihe
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    int k=0;
    for(int i=1;i<=n-1;i++)
    {
        cin>>v[i];
        k+=v[i];
    }
    int l=INT_MAX;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        l=l<a[i]?l:a[i];
    }
    if(a[1]==l)
    {
        cout<<ceil(k/d)*a[1]<<endl;
    }
    return 0;
}
