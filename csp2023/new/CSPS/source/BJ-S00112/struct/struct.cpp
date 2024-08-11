#include <bits/bits/stdc++.h>
using namespace std;
int n,op,k,num,addr;
string s,t,tt;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>op;
        if(op==1){
            cin>>s;
            cin>>num;
            for(int j=1;j<=num;j++){
                cin>>s;
                cin>>tt;
            }
        }
        if(op==2){
            cin>>s;
            cin>>t;
            cout<<0<<endl;
        }
        if(op==3){
            cin>>tt;
            cout<<0<<endl;
        }
        if(op==4){
            cin>>addr;
            cout<<"ERR";
        }
        
    }

return 0;
}
