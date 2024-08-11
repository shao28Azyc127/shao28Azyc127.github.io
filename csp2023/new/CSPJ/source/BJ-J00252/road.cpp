#include<bits/stdc++.h>
using namespace std;

int ds[100005],jg[100005];
long long q=0;
double y=0;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,d;
    cin>>n>>d;
    for(int i=0;i<n-1;i++){
        cin>>ds[i];
    }for(int i=0;i<n;i++){
        cin>>jg[i];
    }
    for(int i=0;i<n-1;i++){
        int j=i;
        long long sm=ds[i];
        for(;j<n-1;j++){
            if(jg[i]>jg[j]){
                break;
            }
            if(j>i){
                sm+=ds[j];
            }
        }double yu=1.0*sm/d;
        y-=yu;
        if(y<0)
        q+=ceil(abs(y))*jg[i];
        y=ceil(abs(y))-abs(y);
        i=j-1;
    }cout<<q;
    return 0;
}

