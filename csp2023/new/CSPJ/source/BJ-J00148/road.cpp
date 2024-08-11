#include<bits/stdc++.h>
using namespace std;
const long long maxn=1e5+10;  
long long n,d,v,cst,low,pst;
long long dis[maxn];
long long price[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    for(int i = 1;i < n;i++) cin >> dis[i];
    for(int i = 1;i <= n;i++) cin >> price[i];
    low=price[1];
    for(int i = 2;i <= n;i++){
        pst+=dis[i-1];
        if(price[i]<low or i==n){
            long long more;
            cst+=max((pst-v),0ll)/d*low;
            if((pst-v)%d > 0) cst+=low,more=d-(pst-v)%d;
            if(pst<v) v-=pst;
            else v=0;
            v+=more;
            low=price[i];
            pst=0;
        }
    }
    cout << cst;
    return 0;
}