#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=5e5+10,MAXM=2010;
int x[MAXN],y[MAXN],X[MAXN],Y[MAXN],mxx[MAXN],miy[MAXN],lx[MAXN],ly[MAXN];
bool fg[MAXM][MAXM];
int read(){
    int num=0,sign=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')num=num*10+ch-'0',ch=getchar();
    return num*sign;
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int tid=read(),n=read(),m=read(),Q=read();
    for(int i=1;i<=n;i++) x[i]=read(),X[i]=x[i];
    for(int i=1;i<=m;i++) y[i]=read(),Y[i]=y[i];
    for(int q=0;q<=Q;q++){
        for(int i=1;i<=n;i++) x[i]=X[i];
        for(int i=1;i<=m;i++) y[i]=Y[i];
        if(q){
            int kx=read(),ky=read(),p,v;
            for(int i=1;i<=kx;i++) p=read(),v=read(),x[p]=v;
            for(int i=1;i<=ky;i++) p=read(),v=read(),y[p]=v;
        }
        if(x[1]==y[1]){printf("0");continue;}
        if(x[1]>y[1]){
            for(int i=1;i<=n;i++) x[i]=-x[i];
            for(int i=1;i<=m;i++) y[i]=-y[i];
        }
        if(tid<=7){
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) fg[i][j]=0;
        fg[1][1]=1;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
            if(!fg[i][j]) continue;
            if(x[i+1]<y[j]) fg[i+1][j]=1;
            if(x[i]<y[j+1]) fg[i][j+1]=1;
        }
        printf("%d",fg[n][m]);
        }
        else if(tid<=14){
        mxx[1]=x[1];for(int i=2;i<=n;i++) mxx[i]=max(mxx[i-1],x[i]);
        miy[1]=y[1];for(int i=2;i<=m;i++) miy[i]=min(miy[i-1],y[i]);
        if(miy[m]<=x[n]||mxx[n]>=y[m]){printf("0");continue;}
        for(int i=1;i<=m;i++) miy[i]=-miy[i];
        for(int i=1;i<=n;i++) lx[i]=lower_bound(miy+1,miy+m+1,-x[i])-miy-1;
        for(int i=1;i<=m;i++) ly[i]=lower_bound(mxx+1,mxx+n+1,y[i])-mxx-1;
        int px=1,py=0,res=0;
        while(1){
            int mx=0,mxp=py;
            for(int i=py+1;i<=lx[px];i++)
                if(ly[i]>mx) mx=ly[i],mxp=i;
            if(mxp==py) break;
            py=mxp;if(px==n||py==m){res=1;break;}
            mx=0,mxp=px;
            for(int i=px+1;i<=ly[py];i++)
                if(lx[i]>mx) mx=lx[i],mxp=i;
            if(mxp==px) break;
            px=mxp;if(px==n||py==m){res=1;break;}
        }
        printf("%d",res);
        }
        else{
            int res=0;
        mxx[1]=x[1];for(int i=2;i<=n;i++) mxx[i]=max(mxx[i-1],x[i]);
        miy[1]=y[1];for(int i=2;i<=m;i++) miy[i]=min(miy[i-1],y[i]);
        int px1=0,px2=0,py1=0,py2=0;
        for(int i=1;i<=n;i++) if(x[i]<miy[m]){px1=i;break;}
        for(int i=1;i<=m;i++) if(y[i]>mxx[n]){py1=i;break;}
        if(!px1||!py1){printf("0");continue;}
        for(int i=1;i<=m;i++) miy[i]=-miy[i];
        for(int i=1;i<=n;i++) lx[i]=lower_bound(miy+1,miy+m+1,-x[i])-miy-1;
        for(int i=1;i<=m;i++) ly[i]=lower_bound(mxx+1,mxx+n+1,y[i])-mxx-1;
        int px=1,py=0;
        while(1){
            int mx=0,mxp=py;
            for(int i=py+1;i<=lx[px];i++)
                if(ly[i]>mx) mx=ly[i],mxp=i;
            if(mxp==py) break;
            py=mxp;if(px>px1||py>py1){res++;break;}
            mx=0,mxp=px;
            for(int i=px+1;i<=ly[py];i++)
                if(lx[i]>mx) mx=lx[i],mxp=i;
            if(mxp==px) break;
            px=mxp;if(px>px1||py>py1){res++;break;}
        }
        for(int i=1;i<=n/2;i++) swap(x[i],x[n-i+1]);
        for(int i=1;i<=m/2;i++) swap(y[i],y[m-i+1]);
        mxx[1]=x[1];for(int i=2;i<=n;i++) mxx[i]=max(mxx[i-1],x[i]);
        miy[1]=y[1];for(int i=2;i<=m;i++) miy[i]=min(miy[i-1],y[i]);
        px1=0,px2=0,py1=0,py2=0;
        for(int i=1;i<=n;i++) if(x[i]<miy[m]){px1=i;break;}
        for(int i=1;i<=m;i++) if(y[i]>mxx[n]){py1=i;break;}
        if(!px1||!py1){printf("0");continue;}
        for(int i=1;i<=m;i++) miy[i]=-miy[i];
        for(int i=1;i<=n;i++) lx[i]=lower_bound(miy+1,miy+m+1,-x[i])-miy-1;
        for(int i=1;i<=m;i++) ly[i]=lower_bound(mxx+1,mxx+n+1,y[i])-mxx-1;
        px=1,py=0;
        while(1){
            int mx=0,mxp=py;
            for(int i=py+1;i<=lx[px];i++)
                if(ly[i]>mx) mx=ly[i],mxp=i;
            if(mxp==py) break;
            py=mxp;if(px>px1||py>py1){res++;break;}
            mx=0,mxp=px;
            for(int i=px+1;i<=ly[py];i++)
                if(lx[i]>mx) mx=lx[i],mxp=i;
            if(mxp==px) break;
            px=mxp;if(px>px1||py>py1){res++;break;}
        }
        printf("%d",(res==2));
        }
    }
    printf("\n");
    return 0;
}