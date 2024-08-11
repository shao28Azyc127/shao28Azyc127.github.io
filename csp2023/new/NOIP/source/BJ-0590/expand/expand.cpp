#include <iostream>
#include <cstdio>
using namespace std;
const int N=5*1e5+2;
int x[N],y[N];
struct zzz{
int p,b;
}xk[N],yk[N];
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int c,n,m,q;
    cin >>c>>n>>m>>q;
    for(int i=1;i<=n;i++)
    {
        cin >>x[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin >>y[i];
    }

    int zx=1,zy=1;bool f=1;
    if(x[1]>y[1])
    {
        while(1)
        {
            if(zx<n&&zy<m)
            {
                if(x[zx+1]>y[zy+1]){zx++;zy++;}
                else if(x[zx]>y[zy+1]){zy++;}
                else if(x[zx+1]>y[zy]){zx++;}
                else{f=0;break;}
            }
            else if(zx<n&&zy==m){
                if(x[zx+1]>y[zy]){zx++;}
                else{f=0;break;}
            }
            else if(zx==n&&zy<m)
            {
                if(x[zx]>y[zy+1]){zy++;}
                else{f=0;break;}
            }
            if(zx>=n&&zy>=m){break;}
        }
    }
    else if(x[1]<y[1])
    {
        while(zx<=n&&zy<=m)
        {
            if(zx<n&&zy<m)
            {
                if(x[zx+1]<y[zy+1]){zx++;zy++;}
                else if(x[zx]<y[zy+1]){zy++;}
                else if(x[zx+1]<y[zy]){zx++;}
                else{f=0;break;}
            }
            else if(zx<n&&zy==m){
                if(x[zx+1]<y[zy]){zx++;}
                else{f=0;break;}
            }
            else if(zx==n&&zy<m)
            {
                if(x[zx]<y[zy+1]){zy++;}
                else{f=0;break;}
            }
            else if(zx>=n&&zy>=m){break;}
        }
    }
    else if(x[1]==y[1]){f=0;}
    if(f){cout <<1;}
    else{cout <<0;}
    int kx,ky;
    while(q--)
    {
        cin >>kx>>ky;
        for(int i=1;i<=kx;i++)
        {
            int xv;
            cin >>xk[i].p>>xv;
            xk[i].b=x[xk[i].p];
            x[xk[i].p]=xv;
        }
        for(int i=1;i<=ky;i++)
        {
            int yv;
            cin >>yk[i].p>>yv;
            yk[i].b=y[yk[i].p];
            y[yk[i].p]=yv;
        }
        
        int zx=1,zy=1;bool f=1;
        if(x[1]>y[1])
        {
            while(zx<=n&&zy<=m)
            {
                if(zx<n&&zy<m)
                {
                    if(x[zx+1]>y[zy+1]){zx++;zy++;}
                    else if(x[zx]>y[zy+1]){zy++;}
                    else if(x[zx+1]>y[zy]){zx++;}
                    else{f=0;break;}
                }
                else if(zx<n&&zy==m){
                    if(x[zx+1]>y[zy]){zx++;}
                    else{f=0;break;}
                }
                else if(zx==n&&zy<m)
                {
                    if(x[zx]>y[zy+1]){zy++;}
                    else{f=0;break;}
                }
                else if(zx>=n&&zy>=m){break;}
            }
        }
        else if(x[1]<y[1])
        {
            while(zx<=n&&zy<=m)
            {
                if(zx<n&&zy<m)
                {
                    if(x[zx+1]<y[zy+1]){zx++;zy++;}
                    else if(x[zx]<y[zy+1]){zy++;}
                    else if(x[zx+1]<y[zy]){zx++;}
                    else{f=0;break;}
                }
                else if(zx<n&&zy==m){
                    if(x[zx+1]<y[zy]){zx++;}
                    else{f=0;break;}
                }
                else if(zx==n&&zy<m)
                {
                    if(x[zx]<y[zy+1]){zy++;}
                    else{f=0;break;}
                }
                else if(zx>=n&&zy>=m){break;}
            }
        }
        if(x[1]==y[1]){f=0;}
        if(f==true){cout <<1;}
        else{cout <<0;}
        for(int i=kx;i>=1;i--)
        {
            x[xk[i].p]=xk[i].b;
        }
        for(int i=ky;i>=1;i--)
        {
            y[yk[i].p]=yk[i].b;
        }
        
    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}
