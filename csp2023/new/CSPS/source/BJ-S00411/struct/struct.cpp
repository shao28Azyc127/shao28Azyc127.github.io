#include<bits/stdc++.h>
using namespace std;
unordered_map<int,string> ma;
unordered_map<string,int> mb;
unordered_map<string,int> mc;
int n,addrs;
int r(){
    int ans=0,w=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-'){
            w=-1;
        }
        ch=getchar();
    }
    while(ch<='9'&&ch>='0'){
        ans=(ans<<3)+(ans<<1)+(ch^48);
        ch=getchar();
    }
    return ans*w;
}
int main(){
    cin.tie(0);
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    mc["byte"]=1;
    mc["short"]=2;
    mc["int"]=4;
    mc["long"]=8;
    n=r();
    for(int i=1;i<=n;i++){
        char op;
        cin>>op;
        if(op=='1'){
            continue;
        }else if(op=='2'){
            string t;
            string na;
            cin>>t>>na;
            while(!(addrs%mc[t]==0)){
                addrs++;
            }
            for(int j=addrs;j<=addrs-1+mc[t];j++){
                ma[j]=na;//a-->name
            }
            mb[na]=addrs;//b-->address
            cout<<addrs<<"\n";
            addrs+=mc[t];
        }else if(op=='3'){
            string s;
            cin>>s;
            cout<<mb[s]<<"\n";
        }else if(op=='4'){
            int addr;
            addr=r();
            string x=ma[addr];
            int xl=x.length();
            if(xl==0){
                cout<<"ERR"<<"\n";
            }else{
                cout<<ma[addr]<<"\n";
            }
        }
    }
    return 0;
}
