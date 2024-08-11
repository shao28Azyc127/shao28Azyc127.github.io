#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
int ju[100005],jia[100005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,k,s=0,i,ans=0;
    cin>>n>>k;
    for (i=1;i<n;i++)
        cin>>ju[i];
    for (i=1;i<=n;i++)
        cin>>jia[i];
    for (i=1;i<n;i++)
        s+=ju[i];
    cout<<s/k*jia[1]<<endl;
    return 0;
}
