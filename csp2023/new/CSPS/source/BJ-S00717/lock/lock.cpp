#include<bits/stdc++.h>
using namespace std;
int a[10][10],n,t[10],y,er;
int ans;
int ju(int a,int b,int f){
    if(f){
        return b-a<0?b-a+10:b-a;
    }
    else{
        return a-b<0?b-a+10:b-a;
    }
}
bool check(int a1,int b1,int c1,int d1,int e1){
    t[1]=a1;t[2]=b1;t[3]=c1;t[4]=d1;t[5]=e1;
    int f[10],k;
    for(int i=1;i<=n;i++){
        k=0;
        for(int j=1;j<=5;j++){
            if(t[j]!=a[i][j]){
                f[++k]=j;
            }
        }
        if(k==1){
            y++;
            //fine
        }
        else if(k==2&&(ju(t[f[1]],a[i][f[1]],1)==ju(t[f[2]],a[i][f[2]],1))&&abs(f[1]-f[2])==1){
            er++;
            //fine
        }
        else{
            //not fine
            return 0;
        }
    }
    return 1;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d %d %d %d",&a[i][1],&a[i][2],&a[i][3],&a[i][4],&a[i][5]);
    }
    for(int a1=0;a1<=9;a1++){
        for(int b1=0;b1<=9;b1++){
            for(int c1=0;c1<=9;c1++){
                for(int d1=0;d1<=9;d1++){
                    for(int e1=0;e1<=9;e1++){
                        ans+=check(a1,b1,c1,d1,e1);
                    }
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}
