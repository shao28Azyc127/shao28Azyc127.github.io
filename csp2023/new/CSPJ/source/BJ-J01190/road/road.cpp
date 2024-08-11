#include <bits/stdc++.h>
using namespace std;
int n, d, v[100005], a[100005], ans,x=1, y, now=0;
int main(){
     freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for(int i=1;i<n;i++){
        cin >> v[i];
    }
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<n;i+=x){
        x=1;
        while(a[i]<=a[i+x]){
            if((v[i+x-1]-now)%d==0){
                ans=ans+(v[i+x-1]-now)/d*a[i];
                now=0;
                //out << ans << i;
            }else{
                ans=ans+((v[i+x-1]-now)/d+1)*a[i];
                now=v[i+x-1]%d;
                //cout << ans << i;
            }
            x++;
        }
        if((v[i+x-1]-now)%d==0){
                ans=ans+(v[i+x-1]-now)/d*a[i];
                now=0;
                //cout << ans << i;
            }else{
                ans=ans+((v[i+x-1]-now)/d+1)*a[i];
                now=v[i+x-1]%d;
                //cout << ans << i;
            }
    }
    cout << ans;
    return 0;
}