#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1e5+5;
int a[maxn],v[maxn],f[maxn],m[maxn][2];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin >> n>> d;
    for(int i = 2;i <= n;i++){
        cin >> v[i];
        f[i] = f[i-1]+v[i];
    }
    m[0][0] = 1e9;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(m[i-1][0] > a[i]){
            m[i][0] = a[i];
            m[i][1] = i;
        }else m[i][0] = m[i-1][0],m[i][1] = m[i-1][1];
    }
    int chp = n;
    int ans = 0;
    while(chp != 1){
        int tmp= chp;
        chp = m[chp-1][1];
        double abc = double(f[tmp]-f[chp])/d;
        if(abc>(int)abc) abc++;
        ans += (int)abc*a[chp];
    }
    cout << ans;
    return 0;
}
