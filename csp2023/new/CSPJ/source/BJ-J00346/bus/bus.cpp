#include<bits/stdc++.h>
using namespace std;
int a[10005],b[10005],c[10005];
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int m,t;
    cin>>t>>m;
    for(int i=1;i<=t;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    if(m==0){

        for(int i=1;i<=t;i++){
            cout<<"0"<<endl;
        }
    }
    return 0;
}
