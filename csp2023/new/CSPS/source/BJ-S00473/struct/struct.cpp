#include<bits/stdc++.h>
using namespace std;

int n;
int op,st[400],dq[400];

int main(){
    int h,addr,k;string s,t;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>op;
        if(op==1){
                int sh=0,lg=0,in=0,bt=0;
            cin>>s>>k;
            for(int j=1;j<=k;j++){
                cin>>t>>n;
                 if(t=="short"){
                    sh++;
                }
                else if(t=="long"){
                    lg++;
                }
                else if(t=="int"){
                    in++;
                }
                else if(t=="byte"){
                    bt++;
                }
                else {
                   for(int i=1;i<=256;i++){
                        if(t[0]==i){
                            st[t[0]]+=st[i];
                            break;
                        }
                   }
                }

            }
               if(lg!=0){
                    st[t[0]]+=(lg+in+sh+bt)*8;
                    dq[t[0]]=8;
                }

                else if(in!=0){
                    st[t[0]]+=(lg+in+sh+bt)*4;
                    dq[t[0]]=4;
                }
                else if(sh!=0){
                    st[t[0]]+=(lg+in+sh+bt)*2;
                    dq[t[0]]=2;
                }
                else{
                    st[t[0]]+=bt;
                    dq[t[0]]=1;
                }
                cout<<st[t[0]]<<" "<<dq[t[0]];

        }
        else if(op==2){
            cin>>t>>h;
        }
        else if(op==3){
            cin>>s;
        }
        else if(op==4){
            cin>>addr;
        }
    }
    return 0;
}
