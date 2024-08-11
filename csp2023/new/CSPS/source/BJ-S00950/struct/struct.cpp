#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#define ll long long
#define ldb long double
using namespace std;
int t,op;
// bitset<10000> mem;
int nx=0;
// map<string,int> reg;
map<ll,string> mem; // memory
map<string,int> tps; // types length/space
map<string,map<int,string> > ord; // order of a type (name)
map<string,string > stp2; // start of a type (type)
map<string,map<string,string> > stp3;
map<string,ll> stp; // start pos(s) in mem
void init(){
    tps["byte"]=1;
    tps["short"]=2;
    tps["int"]=4;
    tps["long"]=8;
}
void work1(string s,int k){
    string ty,nm;
    int beg=0,mx,sz;
    // bitset<1000> b;
    for(int i=1;i<=k;i++){
        cin>>ty>>nm;
        // for(int i=beg;i<=beg+tps[ty]-1;i++){
        //     b[i]=1;
        // }
        int las=beg;
        if((beg+tps[ty])%4==0) beg=beg+tps[ty];
        else{
            beg=(beg+tps[ty])/4*4+4;
        }
        for(int i=las;i<=beg-1;i++){
            // cout<<"!";
            ord[s][i]=nm;
        }
        // cout<<"!";
        // stp2[s][las]=ty;
        stp2[nm]=
        stp3[s][nm]=ty;
        mx=max(tps[ty],mx);
    }
    sz=beg;
    tps[s]=sz;
    // cout<<"OK";
    cout<<sz<<" "<<mx<<endl;
    return;
}
void work2(string t,string n){
    int sz=tps[t];
    for(int i=nx;i<=nx+sz-1;i++){
        mem[i]=t;
    }
    stp[n]=nx;
    cout<<nx<<endl;
    if((nx+sz)%4==0) nx=nx+sz;
    else{
        nx=(nx+sz)/4*4+4;
    }
    stp2[n]=t;
    return;
}
void work3(string s){
    string ss[10005];
    int cur=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='.'){
            cur++;
            continue;
        }
        ss[cur].push_back(s[i]);
    }
    ll start=stp[ss[0]];
    for(int i=1;i<=cur;i++){
        // cout<<tps[ss[i-1]];
        for(int j=0;j<tps[stp3[ss[i-1]][ss[i]]];j++){
            // cout<<j<<endl;
            if(ord[ss[i-1]][j]==ss[i]){
                start=start+j;
                break;
            }
        }
    }
    cout<<start<<endl;
    return;
}
void work4(ll addr){
    string s=mem[addr];
    if(s==""){cout<<"ERR"<<endl;return;}
    ll i=stp[s];
    cout<<s;
    cout<<ord[s][addr-i];
    // while(mem[addr]==mem[i]) i--;
    // i++;
    // ll dis=addr-i;
    // cout<<
    return;
}
int main(){
    ios::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    init();
    cin>>t;
    while(t--){
        cin>>op;
        if(op==1){
            string s;
            int k;
            cin>>s>>k;
            work1(s,k);
        }else if(op==2){
            string t,n;
            cin>>t>>n;
            work2(t,n);
        }else if(op==3){
            string s;
            cin>>s;
            work3(s);
        }else{
            ll addr;
            cin>>addr;
            work4(addr);
        }
    }
    return 0;
}