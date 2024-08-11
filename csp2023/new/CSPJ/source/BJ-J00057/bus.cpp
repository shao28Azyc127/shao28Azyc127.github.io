#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int n,m,k,jg,u[20005],v[20005],a[20005],ans=0,ti=0;

int main(){
    freopen ("bus.in","r",stdin);
    freopen ("bus.out","w",stdout);
    cin >> n >> m >> k;
    for (int i=1;i<=m;i++){
        cin >> u[i] >> v[i] >> a[i];
    }
    for (int i=1;i<=m;i++){
        if (u[i]==1){
            int p=v[i];
            for (int j=1;j<=m;j++){
                if (u[j]==p && a[j]>=ti) p=u[j],ti++;
            }
            ti+=ti%k;
        }
        ans=min(ans,ti);
    }
    cout << ans;
}
