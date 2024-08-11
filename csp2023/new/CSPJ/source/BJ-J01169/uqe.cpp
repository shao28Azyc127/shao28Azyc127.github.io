#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    long long t,m,a[1005],b[1005],c[1005],x;
    cin>>t>>m;
    for(int i=1;i<=t;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<=t;i++){
        if(b[i]*b[i]-4*a[i]*c[i]<0){
            cout<<"no"<<endl;
        }else if(b==0&&c==0){
            cout<<"0"<<endl;
        }else{
            cout<<"1"<<endl;
        }
    }
    return 0;
}
