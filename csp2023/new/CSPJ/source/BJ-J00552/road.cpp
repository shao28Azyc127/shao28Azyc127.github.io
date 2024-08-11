#include <iostream>
#include <cstdio>
using namespace std;
int n;
long long d,v[100005]={0},a[100005]={0},sy=0,ans=0,mina=10000000000;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    for(int i = 1;i < n;i++){
        cin >> v[i];
    }
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(i==n){
            break;
        }
        mina=min(mina,a[i]);
        ans+=(v[i]-sy+d-1)/d*mina;
        sy+=(v[i]-sy+d-1)/d*d;
        sy-=v[i];
    }
    cout << ans;
    return 0;
}
