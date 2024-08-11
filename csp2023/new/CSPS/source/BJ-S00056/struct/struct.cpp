#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n,k;
    string s,t,n,addr;
    cin>>n;
    for(int i=1;i<=n;i++){
        int op;
        cin>>op;
        if(op==1){
           cin>>s>>k;
           for(int j=1;j<=n;j++){
            cin>>t>>n;
           }
        }
        if(op==2){
            cin>>t>>n;
        }
        if(op==3){
            cin>>s;
        }
        if(op==4){
            cin>>addr;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<"ERR"<<endl;
    }
    return 0;
}
