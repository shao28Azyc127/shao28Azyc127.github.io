#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
int v[100005],a[100005];
long long n,d;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    for(long long i = 0;i<n-1;i++){
        cin >> v[i];
    }
    for(long long i = 0;i<n;i++){
        cin >> a[i];
    }
    long long juli = 0,ans = 0,yx = 0;
    for(long long i = 0;i<n;i++){
        long long k = n-1;
        juli = 0;
        for(long long j = i+1;j<n-1;j++){
            if(a[j]<a[i]){
                k = j;
                break;
            }
        }
        for(long long j = i;j<k;j++){
            juli += v[j];
        }
        if(juli == 0)break;
        if((juli-yx)%d != 0){
            ans += ((juli-yx)/d+1)*a[i];
            yx = (juli-yx)%d;
        }else{
            ans += (juli-yx)/d*a[i];
            yx = (juli-yx)%d;
        }
        i = k-1;
    }
    cout<<ans;
    return 0;
}

