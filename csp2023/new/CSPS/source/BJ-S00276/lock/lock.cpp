#include<cstdio>
int n,a[10][9],ans;
bool c(int i,int j,int k,int p,int q,int l){
    bool c = 0,sw0 = 0,sw1 = 0,sw2 = 0,sw3 = 0,cnt0 = 0,cnt1 = 0,cnt2 = 0,cnt3 = 0,cnt4 = 0;
    if(((i + a[l][1]) - (j + a[l][0]) + 10) % 10 == 0) sw0 = 1;
    if(((j + a[l][2]) - (k + a[l][1]) + 10) % 10 == 0) sw1 = 1;
    if(((k + a[l][3]) - (p + a[l][2]) + 10) % 10 == 0) sw2 = 1;
    if(((p + a[l][4]) - (q + a[l][3]) + 10) % 10 == 0) sw3 = 1;
    if(i == a[l][0]) cnt0 = 1;
    if(j == a[l][0]) cnt1 = 1;
    if(k == a[l][2]) cnt2 = 1;
    if(p == a[l][3]) cnt3 = 1;
    if(q == a[l][4]) cnt4 = 1;
    if(!cnt0&&cnt1&&cnt2&&cnt3&&cnt4) c = 1;
    if(cnt0&&!cnt1&&cnt2&&cnt3&&cnt4) c = 1;
    if(cnt0&&cnt1&&!cnt2&&cnt3&&cnt4) c = 1;
    if(cnt0&&cnt1&&cnt2&&!cnt3&&cnt4) c = 1;
    if(cnt0&&cnt1&&cnt2&&cnt3&&!cnt4) c = 1;
    if(sw0&&!cnt0&&!cnt1&&cnt2&&cnt3&&cnt4) c = 1;
    if(sw1&&cnt0&&!cnt1&&!cnt2&&cnt3&&cnt4) c = 1;
    if(sw2&&cnt0&&cnt1&&!cnt2&&!cnt3&&cnt4) c = 1;
    if(sw3&&cnt0&&cnt1&&cnt2&&!cnt3&&!cnt4) c = 1;
    return c;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i = 0;i < n;i++) for(int j = 0;j < 5;j++) scanf("%d",&a[i][j]);
    for(int i = 0;i < 10;i++){
        for(int j = 0;j < 10;j++){
            for(int k = 0;k < 10;k++){
                for(int p = 0;p < 10;p++){
                    for(int q = 0;q < 10;q++){
                        int check = 0;
                        for(int l = 0;l < n;l++){
                            if(!c(i,j,k,p,q,l)){
                                check++;
                            }
                        }
                        if(check == 0){
                            ans++;
                            printf("%d %d %d %d %d\n",i,j,k,p,q);
                        }

                    }
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}
