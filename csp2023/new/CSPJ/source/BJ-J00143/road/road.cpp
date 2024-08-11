#include<bits/stdc++.h>
using namespace std;
int n, d;
long long dis[100010];
int a[100010];
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>dis[i];
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        dis[i]+=dis[i-1];
    }
    long long loc=0, co=0, k=0;
    while(k!=n-1){
        int gg=k;
        for(int i=gg;i<n;i++){
            if(a[i]<a[k]){
                k=i;
                break;
            }
        }
        if(k==gg){
            k=n-1;
        }
        long long cha=dis[k]-loc;
        int mai=((cha+d-1)/d);
        co+=a[gg]*mai;
        loc+=d*mai;
//        cout<<"loc = "<<loc<<" | co = "<<co<<" | k = "<<k<<"\n";
    }
    cout<<co;
    return 0;
}