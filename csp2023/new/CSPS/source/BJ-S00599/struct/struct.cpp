#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
struct va{
    ll st,ed;
    string ty,nm;
}x[110];
signed main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ll n,pos=1,cnt=0;
    cin>>n;
    while(n--){
        ll op;
        cin>>op;
        if(op==1) cout<<"114514\n";
        if(op==2){
            cnt++;
            string ty,nm;
            cin>>ty>>nm;
            x[cnt].nm=nm;
            if(ty=="byte"){
                x[cnt].st=pos;x[cnt].ed=pos;pos++;
            }
            if(ty=="short"){
                if(pos%2!=0) pos++;
                x[cnt].st=pos;x[cnt].ed=pos+1;pos=x[cnt].ed;
            }
            if(ty=="int"){
                if(pos%4!=0) pos=pos+4-pos%4;
                x[cnt].st=pos;x[cnt].ed=pos+3;pos=x[cnt].ed;
            }
            if(ty=="long"){
                if(pos%8!=0) pos=pos+8-pos%8;
                x[cnt].st=pos;x[cnt].ed=pos+7;pos=x[cnt].ed;
            }
        }
        if(op==3){
            string s;
            cin>>s;
            for(int i=1;i<=cnt;i++) if(x[i].nm==s) cout<<x[i].st<<endl;
        }
        if(op==4){
            int addr,flag=0;
            cin>>addr;
            for(int i=1;i<=cnt;i++){
                if(addr>=x[i].st&&addr<=x[i].ed){
                    cout<<x[i].nm<<endl;
                    flag=1;
                    break;
                }
            }
            if(flag==0) cout<<"ERR\n";
        }
    }
}
//give me 15pts pls pls pls orz
//whoever counts the strange codes in csp can put me in there(