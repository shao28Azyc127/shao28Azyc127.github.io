#include <iostream>
using namespace std;
int n,d,v[100010],a[100010],ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    for (int i = 1;i <= n;i++){
        cin >> v[i];
        ans+=v[i];
    }
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    cout << ((ans-1)/d+1)*a[1];
    return 0;
}
