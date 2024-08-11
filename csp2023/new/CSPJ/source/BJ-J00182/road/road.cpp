#include<bits/stdc++.h>
using namespace std;
long long u[1000005],a[1000005];
int main(){
    long long n,d,jsq=0,z=1,t=0;
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>u[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    while(z!=n){
        long long w=z+1,l=u[z];
        while(a[z]<=a[w]&&w<=n){
                w++;
                l+=u[w-1];
        }
        if(l%d==0){
            jsq+=a[z]*(l/d);
        }
        else{
            if(d*(l/d)+t>=l){
                jsq+=a[z]*(l/d);
                t-=l-d*(l/d);
            }
            else{
                jsq+=a[z]*(l/d+1);
                t+=d*(l/d+1)-l;
            }
        }
        z=w;
        //cout<<jsq<<endl;
    }
    cout<<jsq<<endl;
    return 0;
}
