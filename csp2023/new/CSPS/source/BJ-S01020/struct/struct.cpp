#include<bits/stdc++.h>
using namespace std;
long long n,op,to=0;
string ty,na;
map<string,long long> mp;
map<string,long long> dz;
map<long long,string> dz2;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    while(n--){
        cin>>op;
        if(op==1){
        }
        else if(op==2){
            cin>>ty>>na;
            if(ty=="byte")mp[na]=1;
            else if(ty=="short")mp[na]=2;
            else if(ty=="int")mp[na]=4;
            else mp[na]=8;
            while(to%mp[na])to++;
            cout<<to<<endl;
            dz[na]=to;
            for(long long i=to;i<=to+mp[na];i++){
                dz2[i]=na;
            }
            to+=mp[na];
        }
        else if(op==3){
            cin>>na;
            cout<<dz[na]<<endl;
        }
        else{
            long long i;
            cin>>i;
            if(dz2[i]!="")cout<<dz2[i]<<endl;
            else cout<<"ERR\n";
        }
    }
    return 0;
}
