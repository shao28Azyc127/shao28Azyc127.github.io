#include<bits/stdc++.h>
using namespace std;
int n,x,ans,a[6],b[6];
int f[100007];
int shu(int *b){
    int p=0;
    for(int i=1;i<=5;i++){
        p=p*10+b[i];
    }
    return p;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    int m=n;
    while(m--){
        x=0;
        for(int i=1;i<=5;i++){
            cin>>a[i];
            x=x*10+a[i];
        }
        f[x]=-1;
        for(int i=1;i<=5;i++){
            for(int j=0;j<=9;j++){
                for(int k=1;k<=5;k++) b[k]=a[k];
                b[i]=j;
                int q=shu(b);
                f[q]++;
            }
        }
        for(int i=1;i<=4;i++){
            for(int j=0;j<=9;j++){
                for(int k=1;k<=5;k++) b[k]=a[k];
                b[i]=(b[i]+j)%10;
                b[i+1]=(b[i+1]+j)%10;
                int q=shu(b);
                f[q]++;
            }
        }
    }
    for(int i=0;i<=99999;i++){
        if(f[i]==n) ans++;
    }
    printf("%d",ans);
    return 0;
}
