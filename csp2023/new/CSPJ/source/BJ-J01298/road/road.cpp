#include <iostream>

using namespace std;

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,v[10005],a[10005];
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int zonglucheng=0;
    for(int i=1;i<=n-1;i++){
        zonglucheng+=v[i];
    }
    //cout<<zonglucheng;
    if(zonglucheng%d==0) cout<<zonglucheng/d*a[1];
    if(zonglucheng%d!=0){
        int k=zonglucheng/d;
        k++;
        cout<<k*a[1];
    }
    return 0;
}
