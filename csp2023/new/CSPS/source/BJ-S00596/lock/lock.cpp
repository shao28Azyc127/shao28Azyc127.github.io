#include<bits/stdc++.h>
using namespace std;
int n;
int a[15][15];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            scanf("%d",&a[i][j]);
        }
        for(int j=1;j<i;j++){
            if(a[j][1]==a[i][1]&&a[j][2]==a[i][2]&&a[j][3]==a[i][3]&&a[j][4]==a[i][4]&&a[j][5]==a[i][5]){
                i--;
                n--;
                //cout<<"!!!"<<endl;
            }
        }
    }
    if(n==1){
        printf("81\n");
        return 0;
    }
    int sum=0;
    //1
    for(int k1=1;k1<=n;k1++){
        for(int k2=k1+1;k2<=n;k2++){
            for(int i=1;i<=5;i++){
                if(a[k1][i]!=a[k2][i]){
                    sum+=10;
                }
            }
        }
    }
    //2
    for(int k1=1;k1<=n;k1++){
        for(int k2=k1+1;k2<=n;k2++){
            for(int i=1;i<=5;i++){
                for(int j=i+1;j<=5;j++){
                    if(a[k1][i]!=a[k2][i]&&a[k1][j]!=a[k2][j]){
                        sum+=10;
                    }
                }
            }
        }
    }
    printf("%d",sum);
    return 0;
}
