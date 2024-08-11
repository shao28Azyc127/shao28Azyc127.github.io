#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    long long a[5005],b[5005],c[5005],t,m,d[5005];
    char celta[5005];
    cin>>t>>m;
    long long 
    for(int i=0;i<t;i++){
        cin>>a[i]>>b[i]>>c[i];
        if(b[i]^2-4*a[i]*c[i]<0) cout<<"NO"<<endl;
        else {
            d[i]=b[i]^2-4*a[i]*c[i];
            
        }
    }
    
    return 0;
}
