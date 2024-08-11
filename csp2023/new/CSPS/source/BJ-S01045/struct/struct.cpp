#include<bits/stdc++.h>
using namespace std;
int n,op;
string s;
int k;
string t,u;
int maxn,sum,addr;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>op;
        if(op==1){
            cin>>s>>k;
            for(int j=1;j<=k;j++){
                cin>>t>>u;
                if(t=="byte"){
                    maxn=max(maxn,1);
                }
                else if(t=="short"){
                    maxn=max(maxn,2);
                }
                else if(t=="int"){
                    maxn=max(maxn,4);
                }
                else{
                    maxn=max(maxn,8);
                }
            }
            cout<<maxn*k<<" "<<maxn;
            cout<<endl;
        }
        else if(op==2){
            cin>>t>>u;
            cout<<0<<endl;
        }
        else if(op==3){
            cin>>s;
            cout<<0<<endl;
        }
        else if(op==4){
            cin>>addr;
            cout<<"ERR"<<endl;
        }
    }
    return 0;
}
