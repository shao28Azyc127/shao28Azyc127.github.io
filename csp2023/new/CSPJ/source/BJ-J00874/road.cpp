#include <iostream>
using namespace std;
int v[100001],a[100001];
long long cnt,ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    for(int i=1;i<=n;i++){cin>>v[i];cnt+=v[i];}
    cnt-=v[i];
    for(int i=1;i<=n;i++)cin>>a[i];
    if(cnt%d==0) cnt=cnt/d;
    else cnt=cnt/d+1;
    ans=cnt*a[1];
    cout<<ans<<endl;
    return 0;
}
