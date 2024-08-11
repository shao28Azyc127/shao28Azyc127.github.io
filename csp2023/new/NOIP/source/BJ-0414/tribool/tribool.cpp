#include<bits/stdc++.h>
using namespace std;
struct node{
    int u,v;
}mylet[105];
int T,bian,u,n,m,v,t,ans;
int b[100],tt[100];
char c;
bool pan(){
    for(int i=1;i<=n;i++){
        tt[i]=b[i];
    }
    for(int i=1;i<=t;i++){
        if(mylet[i].u<0){
            if(tt[mylet[i].v]==1){
                tt[-(mylet[i].u)]=2;
            }
            if(tt[mylet[i].v]==2){
                tt[-(mylet[i].u)]=1;
            }
            if(tt[mylet[i].v]==3){
                tt[-(mylet[i].u)]=3;
            }
        }
        else{
            tt[mylet[i].u]=tt[mylet[i].v];
        }
    }

    for(int i=1;i<=n;i++){
        if(tt[i]!=b[i]){
            return 0;
        }
    }
    return 1;
}
void dfs(int ww,int s){
    if(ww==n){
        if(pan()){
            ans=min(ans,s);
            return ;
        }
    }
    else{
        ww++;
        while(b[ww]!=0){
            ww++;
            if(b[ww]==3){
                s++;
            }
        }
        b[ww]=1;
        dfs(ww,s);
        b[ww]=2;
        dfs(ww,s);
        b[ww]=3;
        dfs(ww,s+1);
        b[ww]=0;
    }
}

int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin >> bian >> T;
    while(T--){
        t=0;ans=1e9;b[0]=114;
        for(int i=1;i<=15;i++){
            b[i]=0;
        }
        cin >> n >> m;
        for(int i=1;i<=m;i++){
            cin >> c;
            if(c=='T'){
                cin >> u;
                b[u]=1;
            }
            else if(c=='F'){
                cin >> u;
                b[u]=2;
            }
            else if(c=='U'){
                cin >> u;
                b[u]=3;
            }
            else if(c=='+'){
				cin >> u >> v;
                mylet[++t].u=u;mylet[t].v=v;
            }
            else if(c=='-'){
                cin >> u >> v;
                mylet[++t].u=-u;mylet[t].v=v;
            }
        }
        dfs(0,0);
        cout << ans << endl;
    }
    return 0;
}

