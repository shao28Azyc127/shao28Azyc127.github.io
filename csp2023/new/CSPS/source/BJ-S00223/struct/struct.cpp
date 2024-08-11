#include<bits/stdc++.h>
using namespace std;
map<string,int> a;
map<int,string> b;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    a["byte"]=1;a["short"]=2;a["int"]=4;a["long"]=8;
    int n;
    cin>>n;
    int now=0;
    for(int i=1;i<=n;i++){
        int op;
        cin>>op;
        if(op==1){
            cout<<"I am very vegetable,I don't know how to do it"<<endl;
        }
        if(op==2){
            string t,nn;
            cin>>t>>nn;
            for(int i=now;i<now+a[t];i++){
                b[i]=nn;
            }
            a[nn]=now;
            now+=a[t];
        }
        if(op==3){
            string nn;
            cin>>nn;
            cout<<a[nn]<<endl;
        }
        if(op==4){
            int addr;
            cin>>addr;
            if(b[addr]==""){
                cout<<"ERR"<<endl;
                continue;
            }
            cout<<b[addr]<<endl;
        }
    }
    return 0;
}
