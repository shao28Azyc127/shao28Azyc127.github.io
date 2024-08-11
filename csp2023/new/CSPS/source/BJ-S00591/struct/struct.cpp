#include<bits/stdc++.h>
#define int long long
using namespace std;
map<string,int> mp;
string s[1000];
signed main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int T,op,addr,cnt=0;
    string t,n,err="ERR";
    cin>>T;
    for(int i=0;i<1000;i++) s[i]=err;
    for(int i=1;i<=T;i++){
        cin>>op;
        if(op==2){
            cin>>t>>n;
            if(t=="byte"){
                mp[n]=cnt;
                s[cnt]=n;
                cnt++;
            } else if(t=="short"){
                cnt=(cnt+1)/2*2;
                mp[n]=cnt;
                s[cnt]=s[cnt+1]=2;
                cnt+=2;
            } else if(t=="int"){
                cnt=(cnt+3)/4*4;
                mp[n]=cnt;
                s[cnt]=s[cnt+1]=s[cnt+2]=s[cnt+3]=n;
                cnt+=4;
            } else {
                cnt=(cnt+7)/8*8;
                mp[n]=cnt;
                s[cnt]=s[cnt+1]=s[cnt+2]=s[cnt+3]=s[cnt+4]=s[cnt+5]=s[cnt+6]=s[cnt+7]=n;
                cnt+=8;
            }
        } else if(op==3){
            cin>>t;
            cout<<mp[t]<<endl;
        } else {
            cin>>addr;
            cout<<s[addr]<<endl;
        }
    }
    return 0;
}