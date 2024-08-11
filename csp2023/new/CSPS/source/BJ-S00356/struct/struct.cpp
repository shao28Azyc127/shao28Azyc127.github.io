#include<bits/stdc++.h>
using namespace std;
int n,cnt=0;
string na[20000];
long long d=0,q[20000],h[20000];
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    scanf("%d",&n);
    while(n--){
        int op;scanf("%d ",&op);
        if(op==1){
            int z;z=1;
        }else if(op==2){
            string a,b;
            cin>>a>>b;
            na[++cnt]=b;
            if(a=="byte"){
                q[cnt]=d;
                h[cnt]=d;
                d++;
            }else if(a=="short"){
                q[cnt]=d+d%2;
                h[cnt]=d+d%2+1;
                d=d+d%2+2;
            }else if(a=="int"){
                q[cnt]=d+d%4;
                h[cnt]=d+d%4+3;
                d=d+d%4+4;
            }else if(a=="long"){
                q[cnt]=d+d%8;
                h[cnt]=d+d%8+7;
                d=d+d%8+8;
            }
            printf("%lld\n",q[cnt]);
        }else if(op==3){
            string s;
            cin>>s;
            for(int i=1;i<=cnt;i++)
                if(na[i]==s){
                    printf("%lld\n",q[i]);
                    break;
                }
        }else{
            long long s;
            cin>>s;
            for(int i=1;i<=cnt;i++){
                if(h[i]<s)continue;
                if(q[i]>s){
                    puts("ERR");
                    break;
                }
                cout<<na[i]<<'\n';
            }
        }
    }
    return 0;
}
