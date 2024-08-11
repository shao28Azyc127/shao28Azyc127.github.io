#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,d,v[100005],a[100005];
bool sub_a=true;
long long totv,ans;
double t;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
        totv+=v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[1]){
            sub_a=false;
        }
    }
    if(sub_a){
        cout<<(ceil(1.0*totv/d)*a[1])<<endl;
        return 0;
    }
    for(int i=1;i<n;){
        int j;
        long long s=0;
        for(j=i+1;j<=n;j++){
            s+=v[j-1];
            if(a[j]<a[i]){
                break;
            }
        }
        ans+=ceil(1.0*s/d-t)*a[i];
        t=ceil(1.0*s/d-t)-(1.0*s/d-t);
        i=j;
    }
    cout<<ans<<endl;
    return 0;
}