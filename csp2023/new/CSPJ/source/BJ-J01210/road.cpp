#include<bits/stdc++.h>
using namespace std;
int n,d,v[100000],a[100001],mincost=100000,place=0,cost=0,gas=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=0;i<n-2;i++){
        cin>>v[i];
    }
    for(int i=0;i<n-1;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]<mincost){
            mincost=a[i];
            for(int j=place;j<i;j++){
                gas+=(v[j]/d);
            }
            cost+=(a[place]*gas);
            place=i;
            gas=0;
        }
    }
    cout<<cost;
    return 0;
}
