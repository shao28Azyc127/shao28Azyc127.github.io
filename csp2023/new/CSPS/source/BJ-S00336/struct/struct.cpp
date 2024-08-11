#include <bits/stdc++.h>
using namespace std;
int n,op;
struct node{
    string name;
    int len;
}d[1000];
void chl();
void chl(){
    int i=-1000000;
    while(i<=100000){
            i++;
    }
    return ;
}
int ope=0;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    while(n--){
        int dz=0;
        cin>>op;
        if(op==1){
        if(op==1){
            string s;
            int k,length=0;
            cin>>s>>k;
            for(int i=1;i<=k;i++){
                int o=0;
                string t;
                cin>>t>>d[o++].name;
                if(t=="byte"){
                    length=max(length,1);
                    d[o++].len=1;
                }
                if(t=="short"){
                    length=max(length,2);
                    d[o++].len=2;
                }
                if(t=="int"){
                    length=max(length,4);
                    d[o++].len=4;
                }
                if(t=="long"){
                    length=8;
                    d[o++].len=8;
                }
                cout<<k*length<<" "<<length;
                chl();
                ope=o;
            }
            if(op==2){
                string t,n;
                cin>>t>>n;
                //fen'pei'di'zhi
                int zdz=d[ope].len*length;
            }
        }
    }
}
return 0;
}

