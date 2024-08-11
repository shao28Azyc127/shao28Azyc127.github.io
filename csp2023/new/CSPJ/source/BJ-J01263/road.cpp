#include <iostream>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    int a[10005]={},b[10005]={};
    for(int i=0;i<n-1;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    int s=0;
    for(int i=0;i<n-1;i++) s+=a[i];
    int m=0,o=0;
    while(true)
    {
        m+=b[0];
        o+=d;
        if(o>=s) break;
    }
    cout<<m;
    return 0;
}