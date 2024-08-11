#include <bits/stdc++.h>
using namespace std;

long long n,d,j,k=1e9,cnt;
struct bus{
    long long dis;
    long long  price;
    long long l;
}st[10010];
long long road(long long  t,long long  w,long long middle){
    long long sq,m=1e9,n=0;
    st[middle].l = (w-st[middle].dis) / d;
    for(int i = 0;i <= middle;i++){
        if(st[i].price < m){
            m = st[i].price;
            middle = i;
        }
    }
    if(st[middle].price == st[0].price){
        return st[0].l = w / d;
    }
    else{
        return road(0,w - (st[middle].l *d),middle);
    }
}


int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    st[0].dis = 0;
    for(int i = 1;i < n;i++){
        long long dis;
        cin >> dis;
        st[i].dis = st[i-1].dis + dis;
    }
    for(int i = 0;i < n;i++){
        cin >>st[i].price;
        if(st[i].price < k && i != n-1){
            j = i;
            k = min(k,st[i].price);
        }
    }
    road(0,st[n-1].dis,j);
    for(int i = 0;i < n;i++){
        cnt += st[i].l * st[i].price;
        cout << i << " "<< st[i].l << endl;
    }
    cout << cnt;
    return 0;
}