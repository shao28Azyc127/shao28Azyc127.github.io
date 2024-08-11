#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
const int maxn = 1e5+10;
int n,d,v[maxn],a[maxn],frv[maxn];
int main(){
   freopen("road.in","r",stdin);
   freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i = 1; i < n; i++){
        cin>>v[i];
        frv[i] = frv[i-1] + v[i];
    }
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }

    double last_oil = 0.00;
    int i = 1,ans = 0;
    while(i <= n){
        int j = i+1;
        while(a[j] >= a[i] && j <= n){
            j++;
        }
        if(j > n){
            j = n;
            break;
        }
        last_oil += ceil(1.0 * (frv[j-1] - frv[i-1]) / d);
        last_oil -= 1.0*(frv[j-1] - frv[i-1])/d;
        if(last_oil >= 1){
            ans += ceil(1.0 * (frv[j-1] - frv[i-1]) / d - 1) * a[i];
            last_oil -= 1;
        }else{
            ans += ceil(1.0 * (frv[j-1] - frv[i-1]) / d) * a[i];
        }
//        printf("j:%d i:%d ans:%d last_oil:%.2f,ans+:%d\n",j,i,ans,last_oil,ceil(1.0 * (frv[j-1] - frv[i-1]) / d) * a[i]);

        i = j;
    }
    cout<<ans<<endl;
    return 0;
}
