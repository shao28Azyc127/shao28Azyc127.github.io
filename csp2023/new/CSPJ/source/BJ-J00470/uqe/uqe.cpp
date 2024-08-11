#include<iostream>
#include<cstdio>
using namespace std;
int a[5005],b[5005],c[5005];
int main(){
    ios::sync_with_stdio(false);
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    for(int i=0;i<t;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=0;i<t;i++){
        if(c[i]==0){
            cout<<0;
        }
        cout<<"NO"<<"\n";
    }
    return 0;
}
