#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,C,T,a[N],b[N];
int tf(int x){
    if(x==3) return 3;
    if(!x) return 0;
    return 3-x;
}
int gettyp(char s){
    if(s=='T') return 2;
    else if(s=='F') return 3;
    else return 4;
}
struct query{
    int op,x,y;
}q[N];
bool chk(int x,int y){
    if(!x) return 1;
    return x==y;
}
bool modify(int id){
    if(!id){
        for(int i=1;i<=m;i++){
            int op=q[i].op,x=q[i].x,y=q[i].y;
            if(!op)  a[x]=a[y];
            else if(op==1) a[x]=tf(a[y]);
            else{
                if(op==2) a[x]=1;
                else if(op==3) a[x]=2;
                else a[x]=3;
            }
        }
    }
    else{
        for(int i=1;i<=m;i++){
            int op=q[i].op,x=q[i].x,y=q[i].y;
            if(!op) b[x]=b[y];
            else if(op==1) b[x]=tf(b[y]);
            else b[x]=op-1;
        }
        //for(int i=1;i<=n;i++)
        //    if(a[i]&&a[i]!=b[i]) return 0;
        if(b[id]!=1) return 0;
    }
    return 1;
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d",&C,&T);
    if(C==3||C==4){
        while(T--){
            memset(a,0,sizeof(a));
            scanf("%d%d",&n,&m);
            char op[2];int x,y;
            while(m--){
                scanf("%s",op);
                scanf("%d",&x);
                if(*op=='U') a[x]=1;
                else a[x]=0;
            }
            int cnt=0;
            for(int i=1;i<=n;i++)
                cnt+=a[i];
            printf("%d\n",cnt);
        }
        return 0;
    }
    while(T--){
        memset(a,0,sizeof(a));
        scanf("%d%d",&n,&m);
        char op[2];int x,y;
        for(int i=1;i<=m;i++){
            scanf("%s",op);
            if(*op=='+'){
                scanf("%d%d",&x,&y);
                q[i]={0,x,y};
                a[x]=a[y];
            }
            else if(*op=='-'){
                scanf("%d%d",&x,&y);
                q[i]={1,x,y};
                a[x]=tf(a[y]);
            }
            else{
                scanf("%d",&x);
                q[i]={gettyp(*op),x,0};
                if(*op=='T') a[x]=1;
                else if(*op=='F') a[x]=2;
                else a[x]=3;
            }
        }
        bool t=modify(0);
        for(int i=1;i<=m;i++){
            int op=q[i].op,x=q[i].x,y=q[i].y;
            if(op>1) continue;
            if(!a[y]){
                for(int j=1;j<=n;j++)
                    b[j]=a[j];
                b[y]=1;
                t=modify(y);
                if(!t){
                    a[y]=3;
                    t=modify(0);
                }
                else{
                    for(int j=1;j<=n;j++) a[j]=b[j];
                    modify(0);
                }
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(a[i]==3) cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}
/*
1 1
10 5
U 1
T 1
U 2
U 3
U 4
*/
