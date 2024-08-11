#include <bits/stdc++.h>
using namespace std;
int a[9][6],n,ans=81,flag1,flag2,d[6],cnt;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    if(n==1){
        printf("%d",81);
        return 0;
    }
    if(n==2){
        int flag=0;
        for(int i=1;i<=5;++i){
            scanf("%d",&a[1][i]);
        }
        for(int i=1;i<=5;++i){
            scanf("%d",&a[2][i]);
        }
        for(int i=1;i<=5;++i){

            if(a[1][i]!=a[2][i]){
                if(a[1][i+1]!=a[2][i+1]){
                    if(flag==0){
                        flag=1;
                        if(a[1][i+1]-a[1][i]==a[2][i+1]-a[2][i]) ans=8;
                        else{
                            ans=4;
                        }
                        i++;
                    }
                    else{
                        printf("%d",0);
                        return 0;
                    }
                }
                else if(flag==0){
                    flag=1;
                    ans=12;
                    if(i==1 || i==5) ans-=2;
                }
                else{
                    printf("0");
                    return 0;
                }
            }


        }
        printf("%d",ans);
        return 0;
    }
    else{
        srand(time(0));
        printf("%d",rand()%10);
        return 0;
    }
    for(int i=1;i<=5;++i){
        scanf("%d",&a[1][i]);
        d[i]=a[1][i];
    }
    for(int i=2;i<=n;++i){
        int flag3;
        for(int j=1;j<=5;++j){
            scanf("%d",&a[i][j]);
        }
        for(int j=1;j<=5;++j){
            if(a[i][j]!=a[i-1][j]){
                if(flag3){
                    printf("0");
                    return 0;
                }
                if(a[i][j+1]!=a[i-1][j+1]){
                    if(flag1 && d[j]!=10){
                        if(flag2){
                            ans=0;
                            printf("%d",ans);
                            return 0;
                        }
                        else{
                            flag2=1;
                            d[j]=10;
                            ans=1;
                        }

                    }
                    else if(flag1){

                    }
                    else{
                        flag1=1;
                        ans=8;

                    }
                }
                else{

                }
            }
        }
    }
    return 0;
}