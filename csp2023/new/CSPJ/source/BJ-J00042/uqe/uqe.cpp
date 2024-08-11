#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","r",stdout);
    int t,m,a[5005],b[5005],c[5005],tmp,x;
    cin>>t>>m;
    for(int i=1;i<=t;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<=t;i++){
        tmp=pow(b[i])-4*a*c;
        if(tmp<0){
            cout<<"NO"<<endl;
        }else{
            x=max((-b+sqrt(tmp))/(2.0*a),(-b-sqrt(tmp))/(2.0*a));
            cout<<x;
        }
    }
    return 0;
}