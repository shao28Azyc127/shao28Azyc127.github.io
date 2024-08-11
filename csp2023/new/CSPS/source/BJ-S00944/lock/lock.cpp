#include <cstdio>
int a[100][100],n,t[100],ans,ttt;
void dfs(int u){
    if(u==6){
        bool flag=false;
        for(int i=1;i<=n;i++){
            int cnt=0,pl=-1,la=-1;
            for(int j=1;j<=5;j++){
                if(a[i][j]!=t[j]){
                    cnt++;
                    la=pl;
                    pl=j;
                }
            }
            if(cnt==0 || cnt>2) return;
            if(cnt==1){
                ttt++;
                continue;
            }
            if(la!=-1 && (pl!=la+1)) return;
            for(int j=1;j<=5;j++){
                if(a[i][j]!=t[j]){
                    int x=a[i][j],y=t[j];
                    int xx,yy;
                    if(x<y) xx=10-y+x;
                    else xx=x-y;
                    if(y<x) yy=10-x+y;
                    else yy=y-x;
                    if(j!=5 && a[i][j+1]!=t[j+1]){    
                        x=a[i][j+1],y=t[j+1];
                        int xxx,yyy;
                        if(x<y) xxx=10-y+x;
                        else xxx=x-y;
                        if(y<x) yyy=10-x+y;
                        else yyy=y-x;
                        if(xx==xxx || yy==yyy){
                            break;
                        }else return;
                    }
                    break;
                }
            }
        }
        ans++;
        return;
    }
    for(int i=0;i<=9;i++){
        t[u]=i;
        dfs(u+1);
    }
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            scanf("%d",&a[i][j]);
        }
    }
    dfs(1);
    printf("%d",ans);
    return 0;
}