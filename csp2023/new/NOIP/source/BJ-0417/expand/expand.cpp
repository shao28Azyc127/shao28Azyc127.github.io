#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,x[100001],y[100001];
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d%d%d%d",&c,&n,&m,&q);
    //for(int i=1;i<=n;i++)scanf("%d",&x[i]);
    //for(int j=1;j<=m;j++)scanf("%d",&y[i]);
    if(c==1){
        int a,b,a1,b1;
        scanf("%d%d",&a,&b);
        if(a!=b)cout<<"1";
        else cout<<"0";
        for(int i=1,ky,xc;i<=q;i++){
            scanf("%d%d",&ky,&xc);
            a1=a,b1=b;
            for(int j=1,wb,mlx;j<=ky;j++){
                scanf("%d%d",&wb,&mlx);
                a1=mlx;
            }
            for(int k=1,wb,mlx;k<=xc;k++){
                scanf("%d%d",&wb,&mlx);
                b1=mlx;
            }
            if(a1!=b1)cout<<"1";
            else cout<<"0";
        }
    }
    return 0;
}
