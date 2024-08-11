#include<bits/stdc++.h>
using namespace std;
int n,ans,a[10][6],noww[6],l;
void chai(int x){
    for(int i=1;i<=5;++i){
        noww[i]=x%10;
        x/=10;
    }
}
int chck(){
    int flg=0;
    for(int i=1;i<=n;++i){
        int cunl=0,sll=0,ckl=-1;
        for(int j=1;j<=5;++j){
            if(a[i][j]-noww[j]!=0){
                ++sll;
                if(sll==1) cunl=j;
                if(sll==2&&j-cunl==1) ckl=j;
            }
        }

        if(sll==1) continue;
        if(sll==2&&ckl!=-1){
            int x=a[i][cunl]-noww[cunl],y=a[i][ckl]-noww[ckl];
            if((x-y)%10==0) continue;
        }
        flg=1;
        break;
    }
    if(flg) return 0;
    return 1;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&l);
        chai(l);
        for(int j=1;j<=5;++j) a[i][j]=noww[j];
    }
    for(int i=0;i<=99999;++i){
        chai(i);
        ans+=chck();
    }
    printf("%d",ans);
    return 0;
}
