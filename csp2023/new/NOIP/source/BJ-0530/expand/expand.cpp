#include<iostream>
#include<cstring>
using namespace std;
int c,n,m,q;
int la,lb;
int a[500001],b[500001];
void problem3(){
    bool flag = 0;
    if((a[0]==b[0])||a[la-1]==b[lb-1]){
        printf("0");
        return;
    }
    if((a[0]>b[0])!=(a[la-1]>b[lb-1])){
        printf("0");
        return;
    }
    if(a[0]>b[0]){
        swap(a,b);
        swap(la,lb);
        flag = 1;
    }
//    int l = 0;r = 0;
    for(int i = 0;i<lb;i++){

    }




    if(flag){
        swap(a,b);
        swap(la,lb);
    }
}
void p2(){
    if(a[1]==b[1]||a[n]==b[m]){
        printf("0");
        return;
    }if((a[1]>b[1])!=(a[n]>b[m])){
        printf("0");
        return;
    }
    printf("1");
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d%d%d%d",&c,&n,&m,&q);
    for(int i = 1;i<=n;i++){
        scanf("%d",a+i);
    }
    for(int i = 1;i<=m;i++){
        scanf("%d",b+i);
    }
    if(c<=2){
        p2();
    }
    int kx,ky;
    int p,v;
    while(q--){
        scanf("%d%d",&kx,&ky);
        for(int i = 1;i<=kx;i++){
            scanf("%d%d",&p,&v);
            a[p] = v;
        }
         for(int i = 1;i<=ky;i++){
            scanf("%d%d",&p,&v);
            b[p] = v;
        }
        if(c<=2){
        p2();
        }
    }
    return 0;
}
