#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
const int inf=0x3f3f3f3f;
int c,n,m,q;
int a[N],b[N];
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d%d%d%d",&c,&n,&m,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&b[i]);
    }
    if(n<=2 && m<=2){
        if((a[1]<b[1] && a[n]<b[m]) || (a[1]>b[1] && a[n]>b[m])){
            printf("1");
        }   
        else{
            printf("0");
        }
    }
    else if(c>=8 && c<=14){
        int maxa=0,minb=inf;
        for(int i=1;i<=n;i++){
            maxa=max(maxa,a[i]);
        }
        for(int i=1;i<=m;i++){
            minb=min(minb,b[i]);
        }
        if((maxa<b[1] && minb>a[n]) || (minb>a[1] && maxa<b[m])){
            printf("1");
        }
        else{
            printf("0");
        }
    }
    while(q--){
        int x,y,p,v;
        scanf("%d%d",&x,&y);
        for(int i=1;i<=x;i++){
            scanf("%d%d",&p,&v);
            a[p]=v;
        }
        for(int i=1;i<=y;i++){
            scanf("%d%d",&p,&v);
            b[p]=v;
        }
        if(n<=2 && m<=2){
            if((a[1]<b[1] && a[n]<b[m]) || (a[1]>b[1] && a[n]>b[m])){
                printf("1");
            }      
            else{
                printf("0");
            }
        }
        else if(c>=8 && c<=14){
            int maxa=0,minb=inf;
            for(int i=1;i<=n;i++){
                maxa=max(maxa,a[i]);
            }
            for(int i=1;i<=m;i++){
                minb=min(minb,b[i]);
            }
            if((maxa<b[1] && minb>a[n]) || (minb>a[1] && maxa<b[m])){
                printf("1");
            }
            else{
                printf("0");
            }
        }
    }
    return 0;
}