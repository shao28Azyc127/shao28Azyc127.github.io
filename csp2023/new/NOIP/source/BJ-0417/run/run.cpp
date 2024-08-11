#include<bits/stdc++.h>
#define rap(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
int c,t,n,m,k,d,ans=-2147483647;
bool b[12093];
struct wb{
    int x,y,v;
}mlx[10021];
bool panding(){
    int liantian=0;
    for(int i=1;i<=n;i++){
        if(b[i]==0)liantian=0;
        if(b[i]==1)++liantian;
        if(liantian>k)return 0;
    }
    return 1;
}int solve(){
    int eng=0;
    for(int i=1;i<=n;i++)if(b[i]==1)eng-=d;
    for(int i=1;i<=m;i++){
        bool suc=1;
        for(int j=mlx[i].x-mlx[i].y+1;j<=mlx[i].x;j++){
            if(b[j]==0){
                suc=0;break;
            }
        }if(suc==1)eng+=mlx[i].v;
    }
    return eng;
}
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        memset(mlx,0,sizeof(mlx));
        ans=-2147483647;
        scanf("%d%d%d%d",&n,&m,&k,&d);
        for(int i=1;i<=m;i++)scanf("%d%d%d",&mlx[i].x,&mlx[i].y,&mlx[i].v);
        rap(a1,1,2){
        rap(a2,1,2){
        rap(a3,1,2){
        rap(a4,1,2){
        rap(a5,1,2){
        rap(a6,1,2){
        rap(a7,1,2){
        rap(a8,1,2){
        rap(a9,1,2){
        rap(a10,1,2){
        rap(a11,1,2){
        rap(a12,1,2){
        rap(a13,1,2){
        rap(a14,1,2){
        rap(a15,1,2){
        rap(a16,1,2){
        rap(a17,1,2){
        rap(a18,1,2){
            b[1]=a1-1,b[2]=a2-1,b[3]=a3-1,b[4]=a4-1,b[5]=a5-1,b[6]=a6-1,b[7]=a7-1,b[8]=a8-1,b[9]=a9-1,b[10]=a10-1,b[11]=a11-1,b[12]=a12-1,b[13]=a13-1,b[14]=a14-1,b[15]=a15-1,b[16]=a16-1,b[17]=a17-1,b[18]=a18-1;
            for(int z11=18;z11>n;z11--)b[z11]=0;
            if(panding()==0)continue;
            ans=max(ans,solve());
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        printf("%d\n",ans);
    }
    return 0;
}
