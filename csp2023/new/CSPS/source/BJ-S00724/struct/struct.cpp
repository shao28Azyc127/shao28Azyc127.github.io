#include<bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define ull unsigned long long
using namespace std;
int q,op,k,typ[105],tp;
ll sp[105],addr;
string t,n,s,nam[105];
map<string,int>mp;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>q;
    sp[1]=0;
    while(q--){
        cin>>op;
        if(op==1){
            cin>>s>>k;
            for(int i=1;i<=k;i++)cin>>t>>n;
            cout<<"ai¡«\n";
        }
        if(op==2){
            tp++;
            cin>>t>>n;
            mp[n]=tp;
            nam[tp]=n;
            if(t=="byte"){
                typ[tp]=1;
                sp[tp+1]=sp[tp]+1;
            }
            if(t=="short"){
                typ[tp]=2;
                sp[tp+1]=sp[tp]+2;
            }
            if(t=="int"){
                typ[tp]=3;
                sp[tp+1]=sp[tp]+4;
            }
            if(t=="long"){
                typ[tp]=4;
                sp[tp+1]=sp[tp]+8;
            }
            cout<<sp[tp]<<"\n";
        }
        if(op==3){
            cin>>n;
            cout<<sp[mp[n]]<<"\n";
        }
        if(op==4){
            cin>>addr;
            int flag=0;
            for(int i=1;i<=tp;i++){
                if(addr>=sp[i]&&addr<sp[i+1]){
                    cout<<nam[i]<<"\n";
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                cout<<"ERR\n";
            }
        }
    }
    return 0;
}