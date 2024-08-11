#include <bits/stdc++.h>

using namespace std;

long long x[500020],y[500020];
long long xx[500020],yy[500020];
int c,n,m,q;
int ch=false;

int check_up(int xpos, int ypos){ //x>y
    for(;ypos<m;ypos++){
        if(x[xpos]>y[ypos]){
            if(ypos==m-1&&xpos==n-1){
                ch=1;
                return 0;
            }
            if(xpos<n-1)
                check_up(xpos+1,ypos);
            else if(xpos==n-1)
                check_up(xpos,ypos+1);
        }
        if(x[xpos]<y[ypos])
            break;
    }
}

int check_down(int ypos, int xpos){ //x>y
    for(;xpos<n;xpos++){
        if(x[xpos]<y[ypos]){
            if(xpos==n-1&&ypos==m-1){
                ch=1;
                return 0;
            }
            if(ypos<m-1)
                check_down(ypos+1,xpos);
            else if(ypos==m-1)
                check_down(ypos,xpos+1);
        }
        if(y[ypos]<x[xpos])
            break;
    }
}

int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);

    scanf("%d%d%d%d",&c,&n,&m,&q);
    for(int i=0;i<n;i++){
        scanf("%d",&x[i]);
        xx[i]=x[i];
    }
    for(int i=0;i<m;i++){
        scanf("%d",&y[i]);
        yy[i]=y[i];
    }

    if(x[0]==y[0])
        ch=false;
    else if(x[0]>y[0])
        check_up(0,0);
    else if(x[0]<y[0])
        check_down(0,0);
    printf("%d",ch);

    for(int k=0;k<q;k++){
        for(int i=0;i<n;i++){
            x[i]=xx[i];
        }
        for(int i=0;i<m;i++){
            y[i]=yy[i];
        }
        int kx,ky;
        scanf("%d%d",&kx,&ky);
        for(int kk=0;kk<kx;kk++){
            int px,vx;
            scanf("%d%d",&px,&vx);
            x[px-1]=vx;
        }
        for(int kk=0;kk<ky;kk++){
            int py,vy;
            scanf("%d%d",&py,&vy);
            y[py-1]=vy;
        }
        ch=0;
        if(x[0]==y[0])
            ch=false;
        else if(x[0]>y[0])
            check_up(0,0);
        else if(x[0]<y[0])
            check_down(0,0);
        printf("%d",ch);
    }


    return 0;
}
