#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=105;
int n,k;
string s;
int cnt;
string name[N];
int L[N],R[N];
int idx;
int getid_name(string s){
    for(int i=1;i<=cnt;i++){
        if(name[i]==s) return i;
    }
}
int getid_addr(int d){
    for(int i=1;i<=cnt;i++){
        if(L[i]<=d&&d<=R[i])
            return i;
    }
    return -1;

}
signed main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    
    cin>>n;
    while(n--){
            int op;
    cin>>op;
        if(op==2){
            string s;
            cin>>s;
            cnt++;
            if(s=="byte"){
                L[cnt]=idx;
                R[cnt]=idx;
                idx+=1;
            }
             if(s=="short"){
                L[cnt]=idx;
                R[cnt]=idx+1;
                idx+=2;
            }
             if(s=="int"){
                L[cnt]=idx;
                R[cnt]=idx+3;
                idx+=4;
            }
             if(s=="long"){
                L[cnt]=idx;
                R[cnt]=idx+7;
                idx+=8;
            }
            cin>>s;
            name[cnt]=s;
        }
        if(op==3){
            string s;
            cin>>s;
            cout<<L[getid_name(s)]<<endl;
        }
        if(op==4){
            int x;
            cin>>x;
            int t=getid_addr(x);
            if(t==-1){
                puts("ERR");
            }
            else{
                cout<<name[t]<<endl;
            }

        }

    }


    return 0;
}
