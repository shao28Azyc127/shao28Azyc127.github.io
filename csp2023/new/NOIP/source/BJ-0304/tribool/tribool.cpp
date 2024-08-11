#include<iostream>
#include<cstdio>
using namespace std;
int c,T,n,m;
int ans=1e9;
struct node{
    int v,a1,a2;
}x[100010];
int a[100010],b[100010];
void work(){
    for(int i=1;i<=n;i++){
        b[i]=a[i];
    }
    for(int i=1;i<=m;i++){
        if(x[i].v==1){
            b[x[i].a1]=1;
        }else if(x[i].v==0){
            b[x[i].a1]=0;
        }else if(x[i].v==2){
            b[x[i].a1]=2;
        }else if(x[i].v==3){
            b[x[i].a1]=b[x[i].a2];
        }else if(x[i].v==4){
            if(b[x[i].a2]==1){
                b[x[i].a1]=0;
            }else if(b[x[i].a2]==0){
                b[x[i].a1]=1;
            }else if(b[x[i].a2]==2){
                b[x[i].a1]=2;
            }
        }
    }
}
bool dfscheck(){
    for(int i=1;i<=n;i++){
        if(a[i]!=b[i]){
            return false;
        }
    }
    return true;
}
void dfs(int x,int ucnt){
    if(x>=n+1){
        work();
        if(dfscheck()==true){
            ans=min(ans,ucnt);
        }
        return;
    }
    if(ucnt>ans){
        return;
    }
    for(int i=0;i<=2;i++){
        if(i!=2){
            a[x]=i;
            dfs(x+1,ucnt);
            a[x]=0;
        }else{
            a[x]=i;
            dfs(x+1,ucnt+1);
            a[x]=0;
        }
    }

}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>T;
    while(T--){
        ans=1e9;
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            char tmp;
            int x1,x2;
            cin>>tmp;
            if(tmp=='T'){
                scanf("%d",&x1);
                x[i].v=1;
                x[i].a1=x1;
            }else if(tmp=='F'){
                scanf("%d",&x1);
                x[i].v=0;
                x[i].a1=x1;
            }else if(tmp=='U'){
                scanf("%d",&x1);
                x[i].v=2;
                x[i].a1=x1;
            }else if(tmp=='+'){
                scanf("%d%d",&x1,&x2);
                x[i].v=3;
                x[i].a1=x1;
                x[i].a2=x2;
            }else if(tmp=='-'){
                scanf("%d%d",&x1,&x2);
                x[i].v=4;
                x[i].a1=x1;
                x[i].a2=x2;
            }
        }
        if(n<=10&&m<=10){
            dfs(1,0);
        }else if(c==3||c==4){
            ans=0;
            for(int i=1;i<=n;i++){
                a[i]=1;
            }
            work();
            for(int i=1;i<=n;i++){
                if(b[i]==2){
                    ans++;
                }
            }
        }else{
            dfs(1,0);
        }


        printf("%d\n",ans);
    }


    return 0;
}
