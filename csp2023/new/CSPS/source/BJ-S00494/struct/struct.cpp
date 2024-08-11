#include <bits/stdc++.h>
using namespace std;
long long n,addr[105],pre[105],ad,k;
string sname[105],type[105][105],name[105][105],t[105],x[105];
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    while(n-k){
        int op;
        k++;
        cin>>op;
        if(op==1){
            cin>>sname[n];
            int x;
            pre[n]=1;
            cin>>x;
            for(int i=1;i<=x;i++){
                cin>>type[n][i]>>name[n][i];
                if(type[n][i]=="byte"){
                    addr[n]+=pre[n];
                }else if(type[n][i]=="short"){
                    if(pre[n]<=2){
                        pre[n]=2;
                    }
                }else if(type[n][i]=="long"){
                    if(pre[n]<=8){
                        pre[n]=8;
                    }
                    for(int j=1;j<=i;j++){
                         addr[n]+=pre[n];
                    }
                }else if(type[n][i]=="int"){
                    if(pre[n]<=4){
                        pre[n]=4;
                    }
                    for(int j=1;j<=i;j++){
                        addr[n]+=pre[n];
                    }
               }else{
                    for(int j=n;j>=1;j--){
                        if(sname[j]==type[n][j]){
                            pre[n]=pre[j];
                        }
                    }
               }
            }
            addr[n]=x*pre[n];
            cout<<addr[n]<<" "<<pre[n]<<endl;
        }else if(op==2){
            cin>>t[n]>>x[n];
            cout<<ad<<endl;
            for(int i=n;i>=1;i--){
                if(sname[i]==t[n]){
                    ad+=addr[i];
                }
            }
        }else{
            cout<<"ERR"<<endl;
        }
    }
    return 0;
}
