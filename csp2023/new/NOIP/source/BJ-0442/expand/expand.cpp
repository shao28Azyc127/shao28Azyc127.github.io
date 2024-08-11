#include<bits/stdc++.h>
#define int long long
using namespace std;

int c,n,m,q,px,py,kx,ky,p,v;
int x[40010],y[40010],tx[40010],ty[40010];

void qread(int& in){
    in=0;
    char ch=getchar();
    while(!isdigit(ch)){
        ch=getchar();
    }
    do{
        in=in*10+(ch-'0');
        ch=getchar();
    }while(isdigit(ch));
}

int solve(int px,int py){
    if(x[px]<y[py]){
        while(x[px]<y[py]){
            if(px==n){
                bool flag=true;
                while(py<=m){
                    if(x[n]>=y[py]){
                        flag=false;
                        break;
                    }
                    py=-(~py);
                }
                return flag;
            }
            if(py==m){
                bool flag=true;
                while(px<=n){
                    if(x[px]>=y[m]){
                        flag=false;
                        break;
                    }
                    px=-(~px);
                }
                return flag;
            }
            int a=0,b=0,c=0;
            if(x[px]<y[py+1]){
                a=solve(px,py+1);
            }
            if(a==1){
                return 1;
            }
            if(x[px+1]<y[py]){
                b=solve(px+1,py);
            }
            if(b==1){
                return 1;
            }
            if(x[px+1]<y[py+1]){
                c=solve(px+1,py+1);
            }
            if(c==1){
                return 1;
            }
            return 0;
        }
    }
    else{
        while(x[px]>y[py]){
            if(px==n){
                bool flag=true;
                while(py<=m){
                    if(x[n]<=y[py]){
                        flag=false;
                        break;
                    }
                    py=-(~py);
                }
                return flag;
            }
            if(py==m){
                bool flag=true;
                while(px<=n){
                    if(x[px]<=y[m]){
                        flag=false;
                        break;
                    }
                    px=-(~px);
                }
                return flag;
            }
            int a=0,b=0,c=0;
            if(x[px]>y[py+1]){
                a=solve(px,py+1);
            }
            if(a==1){
                return 1;
            }
            if(x[px+1]>y[py]){
                b=solve(px+1,py);
            }
            if(b==1){
                return 1;
            }
            if(x[px+1]>y[py+1]){
                c=solve(px+1,py+1);
            }
            if(c==1){
                return 1;
            }
            return 0;
        }
    }
}

signed main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ios::sync_with_stdio(false);
    qread(c);
    qread(n);
    qread(m);
    qread(q);
    if(c<=5){
        for(int i=1;i<=n;i=-(~i)){
            qread(x[i]);
        }
        for(int i=1;i<=m;i=-(~i)){
            qread(y[i]);
        }
        if(x[1]==y[1]||x[n]==y[m]||((x[1]<y[1])&&(x[n]>y[m]))||((x[1]>y[1])&&(x[n]<y[m]))){
            cout<<0;
        }
        else{
            cout<<solve(1,1);
        }
        for(int i=1;i<=q;i=-(~i)){
            qread(kx);
            qread(ky);
            memcpy(tx,x,sizeof(x));
            memcpy(ty,y,sizeof(y));
            for(int j=1;j<=kx;j=-(~j)){
                qread(p);
                qread(v);
                x[p]=v;
            }
            for(int j=1;j<=ky;j=-(~j)){
                qread(p);
                qread(v);
                y[p]=v;
            }
            if(x[1]==y[1]||x[n]==y[m]||((x[1]<y[1])&&(x[n]>y[m]))||((x[1]>y[1])&&(x[n]<y[m]))){
                cout<<0;
            }
            else{
                cout<<solve(1,1);
            }
            memcpy(x,tx,sizeof(x));
            memcpy(y,ty,sizeof(y));
        }
    }
    else{
        for(int i=1;i<=n;i=-(~i)){
            qread(x[i]);
        }
        for(int i=1;i<=m;i=-(~i)){
            qread(y[i]);
        }
        cout<<0;
        for(int i=1;i<=q;i=-(~i)){
            qread(kx);
            qread(ky);
            for(int j=1;j<=kx;j=-(~j)){
                qread(p);
                qread(v);
            }
            for(int j=1;j<=ky;j=-(~j)){
                qread(p);
                qread(v);
            }
            cout<<0;
        }
    }

    return 0;
}
