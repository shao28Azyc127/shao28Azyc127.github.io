#include<bits/stdc++.h>
using namespace std;
int n,bt;
map<int,string> mp;
map<string,string> f;
void ainsert(){
        string a,b;cin>>a>>b;
        if(a=="byte") {
            for(int i=bt;i<bt+1;i++) mp[i]=b;
            bt++;
        }
        if(a=="short") {
            if(bt%2!=0) bt=(bt+1)/2*2;
            for(int i=bt;i<bt+2;i++) mp[i]=b;
            bt+=2;
        }
        if(a=="int") {
            if(bt%4!=0) bt=(bt+3)/4*4;
            for(int i=bt;i<bt+4;i++) mp[i]=b;
            bt+=4;
        }
        if(a=="long") {
            if(bt%8!=0) bt=(bt+7)/8*8;
            for(int i=bt;i<bt+8;i++) mp[i]=b;
            bt+=8;
        }
}
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    while(n--){
        int op;cin>>op;
        if(op==2){
            ainsert();
        }
        if(op==4){
            long long k;cin>>k;
            if(mp[k]=="") cout<<"ERR\n";
            else cout<<mp[k]<<endl;
        }
    }
}

