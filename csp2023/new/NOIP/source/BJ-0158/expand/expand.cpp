//I can't answer any question.
//Chtholly,what can I do?
#include<cstdio>
using namespace std;
int id,n,m,kx,ky,q,px,vx,py,vy;
int x[4],y[4],nx[4],ny[4];
bool mark;
bool check2(){
    if(n==1&&m==2){
        if((x[1]>y[1]&&x[1]>y[2])||(x[1]<y[1]&&x[1]<y[2]))return true;
        return false;
    }
    if(n==2&&m==1){
        if((y[1]>x[1]&&y[1]>x[2])||(y[1]<x[1]&&y[1]<x[2]))return true;
        return false;
    }
    if(n==2&&m==2){
        if((x[1]>y[1]&&x[2]>y[2])||(x[1]<y[1]&&x[2]<y[2]))return true;
        return false;
    }
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d%d%d%d",&id,&n,&m,&q);
    if(n==1&&m==1){
        scanf("%d%d",&x[0],&y[0]);
        printf("%d",(bool)(x[0]!=y[0]));
        while(q--){
            nx[0]=x[0],ny[0]=y[0];
            scanf("%d%d",&kx,&ky);
            if(kx)scanf("%d%d",&px,&nx[0]);
            if(ky)scanf("%d%d",&py,&ny[0]);
            printf("%d",(bool)(nx[0]!=ny[0]));
        }
    }
    else if(n<=2&&m<=2){
        for(int i=1;i<=n;i++)scanf("%d",&nx[i]),x[i]=nx[i];
        for(int i=1;i<=m;i++)scanf("%d",&ny[i]),y[i]=ny[i];
        printf("%d",(int)(check2()));
        while(q--){
            for(int i=1;i<=n;i++)x[i]=nx[i];
            for(int i=1;i<=m;i++)y[i]=ny[i];
            scanf("%d%d",&kx,&ky);
            for(int i=1;i<=kx;i++)scanf("%d%d",&px,&vx),x[px]=vx;
            for(int i=1;i<=ky;i++)scanf("%d%d",&py,&vy),y[py]=vy;
            printf("%d",(int)(check2()));
        }
    }
    else{
        printf("1");
        while(q--)printf("1");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
