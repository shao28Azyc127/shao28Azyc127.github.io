#include<bits/stdc++.h>
using namespace std;
/*struct edge{
    int v,next;
    bool c;
} e[100001];
int h[100001],cnt=0;
void addedge(int u,int v,bool c){
    e[++cnt].v=v;
    e[cnt].c=c;
    e[cnt].next=h[u];
    h[u]=cnt;
    return;
}
int n,m,dfn[100001],dfncnt=0;
bool mark[100001];
int dfs(int now,int nowdfn){
    if(dfn[now])
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        memset(e,0,sizeof(e));
        dfncnt=0;
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            char op;
            int i,j;
            cin>>op>>i;
            if(op=='+'){
                cin>>j;
                addedge(j,i,0);
            }else if(op=='-'){
                cin>>j;
                addedge(j,i,1);
            }else{
                if(op=='U'){

                }
            }
        }
    }
    
    return 0;
}*/
int n,m,res=2147483647,now[100001],enda[100001],op[100001],opi[100001],opj[100001],c;
int opp(int x){
    if(x==1) return 0;
    if(x==0) return 1;
    if(x==2) return 2;
}
void solve(){
    for(int i=1;i<=n;i++){
        enda[i]=now[i];
    }
    for(int i=1;i<=m;i++){
        if(op[i]==0){
            enda[opi[i]]=enda[opj[i]];
        }else if(op[i]==1){
            enda[opi[i]]=opp(enda[opj[i]]);
        }else{
            enda[opj[i]]=opi[i];
        }
    }
    return;
}
void dfs(int step){
    if(step==n+1){
        solve();
        bool flag=1;
        for(int i=1;i<=n;i++){
            if(now[i]!=enda[i]){
                flag=0;
                break;
            }
        }
        if(flag){
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(now[i]==2){
                    cnt++;
                }
            }
            res=min(res,cnt);
        }
        return;
    }
    now[step]=0,dfs(step+1);
    now[step]=1,dfs(step+1);
    now[step]=2,dfs(step+1);
    return;
}
int main(){
    int T;
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>c>>T;
    if(c==1 or c==2){
        while(T--){
            res=2147483647;
            cin>>n>>m;
            for(int i=1;i<=m;i++){
                char tempop;
                cin>>tempop;
                if(tempop=='+'){
                    op[i]=0;
                    cin>>opi[i]>>opj[i];
                }else if(tempop=='-'){
                    op[i]=1;
                    cin>>opi[i]>>opj[i];
                }else{
                    cin>>opj[i];
                    if(tempop=='U'){
                        op[i]=2;
                        opi[i]=2;
                    }else if(tempop=='T'){
                        op[i]=2;
                        opi[i]=1;
                    }else{
                        op[i]=2;
                        opi[i]=0;
                    }
                }
            }
            dfs(1);
            cout<<res<<"\n";
        }
    }else if(c==3 or c==4){
        while(T--){
            bool a[100001]={0};
            cin>>n>>m;
            for(int i=1;i<=m;i++){
                char tempop;
                cin>>tempop;
                if(tempop=='+'){
                    op[i]=0;
                    cin>>opi[i]>>opj[i];
                }else if(tempop=='-'){
                    op[i]=1;
                    cin>>opi[i]>>opj[i];
                }else{
                    cin>>opj[i];
                    if(tempop=='U'){
                        a[opj[i]]=1;
                    }else{
                        a[opj[i]]=0;
                    }
                }
            }
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(a[i]) cnt++;
            }
            cout<<cnt<<"\n";
        }
    }else if(c==9 or c==10){
        cout<<"lxy loves Chotholly forever!";
    }
    return 0;
}