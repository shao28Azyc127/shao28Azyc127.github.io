#include <iostream>
using namespace std;
int main(){
    int n,d,v[10005],a[10005];
    freopen("road.in","r",stdin);
    freopen("road.ans","w",stdout);
    cin>>n>>d;
    int l=0,m=0;
    for(int i=1;i<n;i++){
        cin>>v[i];
        l+=v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int cnt=0;
    int ans=(v[1]/d)*a[1]/1;
    m=v[1]/d/1;
    for(int i=2;i<=n;i++){
        l=l-m;
        if(l<v[n]){
            ans+=(l/d)*a[i]/1;
            break;
        }
        if(a[i]<=a[i+1]){
            cnt+=a[i];
            for(int j=i;j<=n;j++){
                if(a[j+1]>=a[j]){
                    cnt+=v[j+1];
                }
                else{
                    break;
                }
            }
            ans+=(cnt/d)*a[i]/1;
            m=cnt/d/1;
        }
        else{
            ans+=(v[i]/d)*a[i]/1;
            m=v[i]/d/1;
        }
    }
    cout<<ans;
    return 0;
}
