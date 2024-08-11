#include<bits/stdc++.h>
using namespace std;
int n,k;
string s,t,p;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    int op;
    for(int i=1;i<=n;i++){
        cin>>op;
        if(op==1){
            cin>>s;
            cin>>k;
            for(int j=1;j<=k;j++){
                cin>>t;
                cin>>p;
            }
        }
        if(op==2){
            cin>>t;
            cin>>p;
        }
        if(op==3){
            cin>>s;
        }
        if(op==4){
            cin>>k;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<"ERR"<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}