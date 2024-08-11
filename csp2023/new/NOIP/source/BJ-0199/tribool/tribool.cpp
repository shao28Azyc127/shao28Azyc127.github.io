#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,val[100010],f[100010],ans=2e9;
struct node{
    int op,i,j,x;
}op[100010];
bool run(){
    for(int i=1;i<=n;i++){
        f[i]=val[i];
    }for(int i=1;i<=m;i++){
        if(op[i].op==1){
            f[op[i].i]=op[i].x;
        }else{
            if(op[i].op==2){
                f[op[i].i]==f[op[i].j];
            }else{
                if(f[op[i].j]==1||f[op[i].j]==0){
                    f[op[i].i]=!f[op[i].j];
                }else{
                    f[op[i].i]=f[op[i].j];
                }
            }
        }
    }for(int i=1;i<=n;i++){
        if(f[i]!=val[i]){
            return false;
        }
    }return true;
}void dfs(int now,int cnt){
    if(now>n){
        if(run()){
            ans=min(ans,cnt);
        }return;
    }val[now]=1;
    dfs(now+1,cnt);
    val[now]=0;
    dfs(now+1,cnt);
    val[now]=2;
    dfs(now+1,cnt+1);
}int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans=1e9;
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            char ch=getchar();
            while(ch!='T'&&ch!='F'&&ch!='U'&&ch!='+'&&ch!='-'){
                ch=getchar();
            }if(ch=='+'){
                op[i].op=2;
                cin>>op[i].i>>op[i].j;
            }else{
                if(ch=='-'){
                    op[i].op=3;
                    cin>>op[i].i>>op[i].j;
                }else{
                    op[i].op=1;
                    if(ch=='F') op[i].x=0;
                    if(ch=='T') op[i].x=1;
                    if(ch=='U') op[i].x=2;
                    cin>>op[i].i;
                }
            }
        }if(c==1||c==2)dfs(1,0);
        if(c==3||c==4){
            ans=0;
            for(int i=1;i<=m;i++){
                f[op[i].i]=op[i].x;
            }for(int i=1;i<=n;i++){
                if(op[i].x==2) ans++;
            }
        }
        cout<<ans<<'\n';
    }return 0;
}