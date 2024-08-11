#include <bits/stdc++.h>;
using namespace std;
double n,d,a[10005],v[10005],k;
double dis,s;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>a[i];
        dis+=a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>v[i];
        if(v[i]>v[i-1]&&i!=1){
            v[i]=v[i-1];
            k++;
        }
    }
    cout<<ceil(dis/d)*v[1];
    return 0;
}
