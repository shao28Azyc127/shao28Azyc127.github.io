#include<bits/stdc++.h>
using namespace std;
struct OP{
    int type;//1 set;2 +;3 -
    int num;
    OP(){}
    OP(int type,int num):type(type),num(num){}
};
vector<OP> x[100005];
int c,t;
int n,m;
int ch2i(char c){
    if(c=='T') return 1;
    if(c=='F') return 2;
    return 3;
}
int y[100005];
bool vis[100005];
int inv(int x){
    if(x==1) return 2;
    if(x==2) return 1;
    return 3;
}
OP getans(int type,int i){
    // printf("%d %d\n",type,i);
    if(y[i]!=-1){
        if(type==2) return OP(1,y[i]);
        else return OP(1,inv(y[i]));
    }
    if(vis[i]){
        return OP(type,i);
    }
    vis[i]=1;
    OP t;
    if(type==2) t=getans(x[i].back().type,x[i][0].num);
    else{
        if(x[i].back().type==3) t=getans(2,x[i][0].num);
        else t=getans(3,x[i][0].num);
    }
    vis[i]=0;
    // printf(" %d %d\n",t.type,t.num);
    if(t.type!=1&&t.num==i&&t.type!=type){
        y[i]=3;
        return OP(1,3);
    }
    else if(t.type!=1&&t.num==i){
        y[i]=1;
        return OP(1,1);
    }
    if(t.type!=1) return t;
    y[i]=y[x[i][0].num];
    if(x[i].back().type==3) y[i]=inv(y[i]);
    if(type==3) return OP(1,inv(y[i]));
    return OP(1,y[i]);
}
int main(){
    #ifndef JZQ
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    #endif
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            x[i].clear();
            x[i].push_back(OP(2,i));
        }
        memset(y,-1,sizeof(y));
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=m;i++){
            char v;
            while(v=getchar()){
                if(v=='T'||v=='F'||v=='U'||v=='+'||v=='-') break;
            }
            if(v=='+'||v=='-'){
                int i,j;
                scanf("%d%d",&i,&j);
                if(v=='+'){
                    x[i]=x[j];
                    if(y[j]!=-1){
                        y[i]=y[j];
                        x[i].clear();
                        x[i].push_back(OP(1,y[i]));
                    }
                    else y[i]=-1;
                }
                else{
                    x[i]=x[j];
                    if(x[i].back().type==3) x[i].pop_back();
                    else x[i].push_back(OP(3,0));
                    if(y[j]!=-1){
                        y[i]=inv(y[j]);
                        x[i].clear();
                        x[i].push_back(OP(1,y[i]));
                    }
                    else y[i]=-1;
                }
            }
            else{
                int i;
                scanf("%d",&i);
                x[i].clear();
                x[i].push_back(OP(1,ch2i(v)));
                y[i]=ch2i(v);
            }
            // for(int i=1;i<=m;i++){
            //     printf("%d\n",i);
            //     for(auto op:x[i]) printf("%d %d\n",op.type,op.num);
            // }
            // printf("\n");
        }
        // for(int i=1;i<=n;i++){
        //     for(auto op:x[i]) printf("(%d,%d) ",op.type,op.num);
        //     printf("\n");
        // }
        int ans=0;
        for(int i=1;i<=n;i++){
            // printf("%d\n",i);
            // for(auto op:x[i]) printf("%d %d\n",op.type,op.num);
            if(y[i]==-1){
                getans(2,i);
        // for(int i=1;i<=n;i++) printf("%d ",y[i]);
        // printf("\n");
            }
            // printf("%d ",y[i]);
            if(y[i]==3) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}