#include<bits/stdc++.h>
using namespace std;
int n,m;
struct option{
    int bfzs,fzs;
    char op;
}a[100005];
char fzq[15];
char fz[15];
char rfz[15];
int ans=0x3f3f3f3f;
void dfs(int now,int cntu){
    if(now==n+1){
        for(int i=1;i<=n;i++){
            rfz[i]=fz[i];
        }
        for(int i=1;i<=m;i++){
            if(a[i].op=='+'){
                rfz[a[i].bfzs]=rfz[a[i].fzs];
            }else if(a[i].op=='-'){
                if(rfz[a[i].fzs]=='T'){
                    rfz[a[i].bfzs]='F';
                }else if(rfz[a[i].fzs]=='F'){
                    rfz[a[i].bfzs]='T';
                }else{
                    rfz[a[i].bfzs]='U';
                }
                //if(fz[1]=='T'&&fz[2]=='T'&&fz[3]=='F')cout<<i<<" "<<rfz[a[i].bfzs]<<" "<<rfz[a[i].fzs]<<endl;
            }else{
                rfz[a[i].bfzs]=fzq[a[i].bfzs];
            }
            //cout<<a[i].op<<" "<<rfz[a[i].bfzs]<<" "<<fz[a[i].bfzs]<<endl;
        }
        bool bb=0;
        for(int i=1;i<=n;i++){
            if(rfz[i]!=fz[i]){
                bb=1;
            }
        }
        if(!bb){
            ans=min(ans,cntu);
        }
        return;
    }
    fz[now]='T';rfz[now]='T';
    dfs(now+1,cntu);
    fz[now]='F';rfz[now]='F';
    dfs(now+1,cntu);
    fz[now]='U';rfz[now]='U';
    dfs(now+1,cntu+1);
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        int cntu=0;
        for(int i=1;i<=n;i++){
            fz[i]=' ';rfz[i]=' ';
        }
        for(int i=1;i<=m;i++){
            char v;
            cin>>v;
            if(v=='U'){
                cntu++;
                //cout<<"aa"<<endl;
            }
            a[i].op=v;
            if(v!='+'&&v!='-'){
                cin>>a[i].bfzs;
                fzq[a[i].bfzs]=v;
            }else{
                cin>>a[i].bfzs>>a[i].fzs;
            }
        }
        if(c==1||c==2){
            ans=0x3f3f3f3f;
            dfs(1,0);
            cout<<ans<<endl;
        }
        if(c==3||c==4){
            cout<<cntu<<endl;
        }
    }
    return 0;
}
