#include<bits/stdc++.h>
using namespace std;
int n,op,k;string str,x;
struct bian {
    int type_bitt;
    int type_bits;
    string name;
}type[100005];int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;int idx=0;
    type[0].type_bits=-1;
    for(int asdf=1;asdf<=n;asdf++){
        cin>>op;
        if(op==2){
            cin>>str>>x;type[++idx].name=x;
            int sime=type[idx-1].type_bits;
            type[idx].type_bitt=sime+1;
            if(str=="long"){
                type[idx].type_bits=sime+8;
            }else if(str=="short"){
                type[idx].type_bits=sime+2;
            }else if(str=="byte"){
                type[idx].type_bits=sime+1;
            }else if(str=="int"){
                type[idx].type_bits=sime+4;
            }
        }else if(op==4){
            cin>>k;
            if(type[idx].type_bits<k){
                cout<<"ERR"<<endl;
            }else{
                for(int i=1;i<=idx;i++){
                    if(type[i].type_bitt<=k&&type[i].type_bits>=k){
                        cout<<type[i].name<<endl;
                        break;
                    }
                }
            }
        }else if(op==3){
            cin>>str;
            for(int i=1;i<=idx;i++){
                if(type[i].name==str){
                    cout<<type[i].type_bitt<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}
