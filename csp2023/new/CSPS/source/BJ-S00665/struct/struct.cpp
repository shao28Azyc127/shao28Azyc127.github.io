#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=2010;
int n,k,op,lst;string s,t,np;
string mp[MAXN];
signed main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    scanf("%lld",&n);
    while(n--){
        scanf("%lld",&op);
        if(op==1){
            cin>>s;
            scanf("%lld",&k);
            for(int i=1;i<=k;i++){
                cin>>t>>np;
            }
        }
        if(op==2){
            cin>>s>>t;int dq=0;
            if(s=="byte")dq=1;
            if(s=="short")dq=2;
            if(s=="int")dq=4;
            if(s=="long")dq=8;
            for(int i=0;i<dq;i++){
                mp[lst/dq*dq+i]=t;
            }
            lst=lst/dq*dq+dq;
        }
        if(op==3){
            cin>>s;
            for(int i=0;i<=lst;i++){
                if(mp[i]==s){
                    printf("%lld\n",i);
                    break;
                }
            }
        }
        if(op==4){
            int addr;
            scanf("%lld",&addr);
            if(addr>=lst){
                printf("ERR\n");
                continue;
            }
            if(mp[addr]==""){
                printf("ERR\n");
                continue;
            }
            cout<<mp[addr]<<"\n";
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//zycakioi
