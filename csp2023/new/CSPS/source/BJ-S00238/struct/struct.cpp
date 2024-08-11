#include <bits/stdc++.h>
using namespace std;
int N,cnt,now;
struct node{
    string name;
    long long addr;
}e[105];
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>N;
    for(int i=1;i<=N;i++){
        int op;
        cin>>op;
        if(op==2){
            string t,n;
            cin>>t>>n;
            e[++cnt].name=n;
            if(t=="byte"){
                e[cnt].addr=now;
                now+=1;
            }
            if(t=="short"){
                e[cnt].addr=now;
                now+=2;
            }
            if(t=="int"){
                e[cnt].addr=now;
                now+=4;
            }
            if(t=="long"){
                e[cnt].addr=now;
                now+=8;
            }
            cout<<e[cnt].addr<<'\n';
        }
        if(op==3){
            string s;
            cin>>s;
            for(int i=1;i<=cnt;i++){
                if(e[i].name==s){
                    cout<<e[i].addr<<'\n';
                }
            }
        }
        if(op==4){
            int adr;
            cin>>adr;
            bool fl=false;
            for(int i=1;i<=cnt;i++){
                if(e[i].addr==adr){
                    fl=true;
                    cout<<e[i].name<<'\n';
                }
            }
            if(!fl){
                cout<<"ERR";
            }

        }
    }
    return 0;
}
