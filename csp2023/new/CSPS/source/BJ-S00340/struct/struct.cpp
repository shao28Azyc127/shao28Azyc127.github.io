#include<bits/stdc++.h>
using namespace std;
int n,cnt,maxn,vis=-1;
int opt;
int val[1010];
string a[110],s,na;
map<string, int> top;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    a[0]="ERR";
    ios::sync_with_stdio(0);
    cin>>n;
    while(n--){
        cin>>opt;
        if(opt==2){
            cin>>s>>na;
            a[++cnt]=na;
            top[na]=vis+1;
            cout<<vis+1<<endl;
            if(s=="byte"){
                val[++vis]=cnt;
                for(int i=1;i<=maxn-1;i++){
                    val[++vis]=0;
                }
            }
            if(s=="short"){
                maxn=max(maxn,2);
                for(int i=1;i<=2;i++){
                    val[++vis]=cnt;
                }
                for(int i=1;i<=maxn-2;i++){
                    val[++vis]=0;
                }
            }
            if(s=="int"){
                maxn=max(maxn,4);
                for(int i=1;i<=4;i++){
                    val[++vis]=cnt;
                }
                for(int i=1;i<=maxn-4;i++){
                    val[++vis]=0;
                }
            }
            if(s=="long"){
                maxn=max(maxn,8);
                for(int i=1;i<=8;i++){
                    val[++vis]=cnt;
                }
                for(int i=1;i<=maxn-8;i++){
                    val[++vis]=0;
                }
            }
        }
        if(opt==3){
            cin>>na;
            cout<<top[na]<<endl;
        }
        if(opt==4){
            int pos;
            cin>>pos;
            cout<<a[val[pos]]<<endl;
        }
    }
    return 0;
}
