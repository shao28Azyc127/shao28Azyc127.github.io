#include<bits/stdc++.h>
using namespace std;
int a[10020],b[10020],sum=0;
int main(){
    int n,m;
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n-1;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    for(int i=1;i<=sum;i++)
    {
        if(m*i>=sum)
        {
            int t=i*b[1];
            cout<<t;
            break;
        }
    }
    return 0;
}