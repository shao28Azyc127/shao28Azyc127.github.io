#include<bits/stdc++.h>
using namespace std;
int a[10][10],c[1000010];
int hs(int a,int b,int c,int d,int e){
    return (a%10)*10000+(b%10)*1000+(c%10)*100+(d%10)*10+(e%10);
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n,cnt=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d%d%d",&a[i][1],&a[i][2],&a[i][3],&a[i][4],&a[i][5]);
        for(int k=1;k<=9;k++){
            c[hs(a[i][1]+k,a[i][2],a[i][3],a[i][4],a[i][5])]++;
        }
        for(int k=1;k<=9;k++){
            c[hs(a[i][1],a[i][2]+k,a[i][3],a[i][4],a[i][5])]++;
        }
        for(int k=1;k<=9;k++){
            c[hs(a[i][1],a[i][2],a[i][3]+k,a[i][4],a[i][5])]++;
        }
        for(int k=1;k<=9;k++){
            c[hs(a[i][1],a[i][2],a[i][3],a[i][4]+k,a[i][5])]++;
        }
        for(int k=1;k<=9;k++){
            c[hs(a[i][1],a[i][2],a[i][3],a[i][4],a[i][5]+k)]++;
        }
        for(int k=1;k<=9;k++){
            c[hs(a[i][1]+k,a[i][2]+k,a[i][3],a[i][4],a[i][5])]++;
        }
        for(int k=1;k<=9;k++){
            c[hs(a[i][1],a[i][2]+k,a[i][3]+k,a[i][4],a[i][5])]++;
        }
        for(int k=1;k<=9;k++){
            c[hs(a[i][1],a[i][2],a[i][3]+k,a[i][4]+k,a[i][5])]++;
        }
        for(int k=1;k<=9;k++){
            c[hs(a[i][1],a[i][2],a[i][3],a[i][4]+k,a[i][5]+k)]++;
        }
    }
    for(int i=0;i<=99999;i++) if(c[i]==n) cnt++;
    printf("%d",cnt);
    return 0;
}