#include<bits/stdc++.h>
using namespace std;

//T 1,F -1,U 0;

const int MAXN=100000+10;
const int MAXM=100000+10;
int C,T;
struct Var{
    bool Type;
    int Source;
    bool Flip;
    void cpVar(Var b){
        Type=b.Type;
        Source=b.Source;
        Flip=b.Flip;
    }
    void cpNVar(Var b){
        Type=b.Type;
        Source=b.Source;
        Flip=!b.Flip;
    }
    void setVar(int var){
        Type=true;
        Source=var;
        Flip=false;
    }
    void init(int i){
        Type=false;
        Source=i;
        Flip=false;
    }
} var[MAXN];

namespace small{
    int initvar[MAXN];
    int ans=0x3f3f3f3f;

    int check(int N){
        // printf("check if \n");
        // for(int i=1;i<=N;i++){
            // printf("var[%d]=%d\n",i,initvar[i]);
        // }
        int cnt=0;
        for(int i=1;i<=N;i++){
            int tmp;
            if(var[i].Type && var[i].Flip) tmp=-var[i].Source;
            if(var[i].Type && !var[i].Flip) tmp=var[i].Source;
            if(!var[i].Type && var[i].Flip) tmp=-initvar[var[i].Source];
            if(!var[i].Type && !var[i].Flip) tmp=initvar[var[i].Source];
            if(initvar[i]==0) cnt++;
            if(tmp!=initvar[i]) return 0x3f3f3f3f;
        }
            // printf("YES,%d\n",cnt);
        return cnt;
    }
    void work(int N,int now){
        if(now>N){
            ans=min(ans,check(N));
            return;
        }
        if(now==1){
            ans=0x3f3f3f3f;
        }
        initvar[now]=-1;
        work(N,now+1);
        initvar[now]=0;
        work(N,now+1);
        initvar[now]=1;
        work(N,now+1);
        if(now==1){
            printf("%d\n",ans);
        }
    }
};

int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d",&C,&T);
    while(T--){
        int N,M;
        scanf("%d%d",&N,&M);
        //printf("%d%d\n",N,M);
        for(int i=1;i<=N;i++) var[i].init(i);
        for(int i=1;i<=M;i++){
            char v;int x,y;
            scanf("%c",&v);
            while(v!='T'&&v!='F'&&v!='U'&&v!='+'&&v!='-') scanf("%c",&v);
            //printf("%c\n",v);
            if(v=='T'){
                scanf("%d",&x);
                var[x].setVar(1);
                continue;
            }
            if(v=='F'){
                scanf("%d",&x);
                var[x].setVar(-1);
                continue;
            }
            if(v=='U'){
                scanf("%d",&x);
                var[x].setVar(0);
                continue;
            }
            if(v=='+'){
                scanf("%d%d",&x,&y);
                var[x].cpVar(var[y]);
                continue;
            }
            if(v=='-'){
                scanf("%d%d",&x,&y);
                var[x].cpNVar(var[y]);
                continue;
            }
        }
        if(C<3){
            small::work(N,1);
            continue;
        }
        if(C>=3 && C<=6){
            int cnt=0;
            bool initvar[MAXN],flag=true;
            for(int i=1;i<=N;i++) if(var[i].Type && var[i].Source==0) initvar[i]=1;
            while(flag){
                flag=false;
                for(int i=1;i<=N;i++) if(!var[i].Type && initvar[var[i].Source]) initvar[i]=1,flag=true;
            }
            for(int i=1;i<=N;i++) if(initvar[i]) cnt++;
            printf("%d\n",cnt);
            continue;
        }
    }
    return 0;
}

