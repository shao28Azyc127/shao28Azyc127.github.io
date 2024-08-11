#include<bits/stdc++.h>
using namespace std;
int n;
int a[20][10];
bool f[10];
int cnt[20][10], mx[10], cnt2[10];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            scanf("%d", &a[i][j]);
        }
    }
    if(n==1){
        int ans=(2*n-1)*9;
        printf("%d", ans);
        return 0;
    }
    if(n==2){
        int cnt=0;
        for(int i=1;i<=5;i++){
            if(a[1][i]==a[2][i]){
                cnt++;
                f[i]=true;
            }
        }
        if(cnt==4){
            printf("10");
            return 0;
        }
        if(cnt==3){
            if((!f[1])&&(!f[2])){
                if(max(a[1][1]-a[1][2],a[1][2]-a[1][1])==max(a[2][2]-a[2][1],a[2][1]-a[2][2])){
                    printf("12");
                    return 0;
                }
                else{
                    printf("6");
                    return 0;
                }
            }
            if((!f[3])&&(!f[2])){
                if(max(a[1][3]-a[1][2],a[1][2]-a[1][3])==max(a[2][2]-a[2][3],a[2][3]-a[2][2])){
                    printf("12");
                    return 0;
                }
                else{
                    printf("6");
                    return 0;
                }
            }
            if((!f[3])&&(!f[4])){
                if(max(a[1][3]-a[1][4],a[1][4]-a[1][3])==max(a[2][4]-a[2][3],a[2][3]-a[2][4])){
                    printf("12");
                    return 0;
                }
                else{
                    printf("6");
                    return 0;
                }
            }
            if((!f[5])&&(!f[4])){
                if(max(a[1][5]-a[1][4],a[1][4]-a[1][5])==max(a[2][4]-a[2][5],a[2][5]-a[2][4])){
                    printf("12");
                    return 0;
                }
                else{
                    printf("6");
                    return 0;
                }
            }
            printf("2");
            return 0;
        }
        if(cnt==2||cnt==1){
            printf("2");
            return 0;
        }
    }
    /*int mxk;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cnt[a[i][j]][j]++;
            if(cnt[a[i][j]][j]>mx[j]) mx[j]=cnt[a[i][j]][j], mxk=a[i][j];
        }
    }*/
    for(int i=2;i<=n;i++){
        for(int j=j;j<=5;j++){
            if(a[j][i]==a[j][i-1]) cnt2[j]++;
        }
    }
    int cnt3=0;
    for(int i=1;i<=5;i++) if(cnt2[i]==n) cnt3++;
    if(cnt3==4){
        printf("10");
        return 0;
    }
    printf("1");
    return 0;
}
