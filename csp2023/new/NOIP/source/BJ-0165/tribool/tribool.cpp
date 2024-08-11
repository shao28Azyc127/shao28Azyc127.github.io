#include<bits/stdc++.h>
using namespace std;
struct IO{
    IO(){
        freopen("tribool.in","r",stdin);
        freopen("tribool.out","w",stdout);
    }
    ~IO(){
        fclose(stdin);
        fclose(stdout);
    }
}io;
const int N=1e5+7;
int c,t;//obvious "divide and conquer testcase"
int n,m;
char op;
int stat[N],fin[N],x,y,ans;//T=1 F=0 U=2
struct query{
    char op;
    int x,y;
}q[17];
int main(){
    scanf("%d%d",&c,&t);
    if(c==3||c==4){
        while(t--){
            ans=0;
            scanf("%d%d",&n,&m);
            for(int i=1;i<=n;i++){
                stat[i]=-1;
            }
            for(int i=1;i<=m;i++){
                scanf("%c",&op);
                if(op=='U'){
                    scanf("%d",&x);
                    stat[x]=2;
                }else if(op=='T'){
                    scanf("%d",&x);
                    stat[x]=1;
                }else if(op=='F'){
                    scanf("%d",&x);
                    stat[x]=0;
                }
            }
            for(int i=1;i<=n;i++){
                if(stat[i]==2){
                    ans++;
                }
            }
            printf("%d\n",ans);
        }
    }else if(c==1||c==2){
        srand(time(0));
        while(t--){
            ans=0x3f3f3f3f;
            scanf("%d%d",&n,&m);
            for(int i=1;i<=m;i++){
                scanf("%c",&q[i].op);
                if(q[i].op=='U'){
                    scanf("%d",&q[i].x);
                }else if(q[i].op=='T'){
                    scanf("%d",&q[i].x);
                }else if(q[i].op=='F'){
                    scanf("%d",&q[i].x);
                }else{
                    scanf("%d%d",&q[i].x,&q[i].y);
                }
            }
            int cnt=400000;
            while(cnt--){
                for(int i=1;i<=n;i++){
                    stat[i]=(abs(rand())%3);
                    fin[i]=stat[i];
                }
                for(int i=1;i<=m;i++){
                    if(q[i].op=='U'){
                        fin[q[i].x]=2;
                    }else if(q[i].op=='T'){
                        fin[q[i].x]=1;
                    }else if(q[i].op=='F'){
                        fin[q[i].x]=0;
                    }else if(q[i].op=='+'){
                        fin[q[i].x]=fin[q[i].y];
                    }else{
                        if(fin[q[i].y]==2){
                            fin[q[i].x]=2;
                        }else if(fin[q[i].y]==1){
                            fin[q[i].x]=0;
                        }else{
                            fin[q[i].x]=1;
                        }
                    }
                }
                int curans=0;
                for(int i=1;i<=n;i++){
                    if(stat[i]!=fin[i]){
                        curans=0x3f3f3f3f;
                        break;
                    }else{
                        if(stat[i]==2){
                            curans++;
                        }
                    }
                }
                ans=min(ans,curans);
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
