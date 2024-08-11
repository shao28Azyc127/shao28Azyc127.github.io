#include <iostream>
using namespace std;
int n,dis,dises[100005],pries[100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>dis;
    for(int i=1;i<n;i++){
        cin>>dises[i];
    }
    for(int i=1;i<=n;i++){
        cin>>pries[i];
    }
    int disduo=0;
    long long ans=0;
    for(int i=1;i<n;){
        int tos=n,dishe=0-disduo;
        for(int j=i+1;j<=n;j++){
            dishe+=dises[j-1];
            if(pries[j]<pries[i]){
                tos=j;
                break;
            }
        }
        int gos=dishe/dis;
        if(dishe>dis*gos){
            gos++;
            disduo=dis*gos-dishe;
        }
        ans+=gos*pries[i];
        i=tos;
    }
    cout<<ans;
    return 0;
}
