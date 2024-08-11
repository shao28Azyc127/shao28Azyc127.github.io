#include <cstdio>
using namespace std;

int n;
int a[10][5];
int k[5];

bool check(){
    for (int i=0;i<n;i++){
        int cnt=0;
        for (int j=0;j<5;j++){
            if (a[i][j]!=k[j]) cnt++;
        }
        if (cnt==0) return 0;
        if (cnt>=3) return 0;
        if (cnt==2){
            bool res=0;
            for (int j=0;j<4;j++){
                if (a[i][j]!=k[j] && a[i][j+1]!=k[j+1]){
                    res=1;
                    if ((k[j]-a[i][j]+10)%10==(k[j+1]-a[i][j+1]+10)%10){
                        break;
                    }
                    else return 0;
                }
            }
            if (!res) return 0;
        }
    }
    return 1;
}

int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        for (int j=0;j<5;j++) scanf("%d",&a[i][j]);
    }
    int ans=0;
    for (k[0]=0;k[0]<=9;k[0]++){
        for (k[1]=0;k[1]<=9;k[1]++){
            for (k[2]=0;k[2]<=9;k[2]++){
                for (k[3]=0;k[3]<=9;k[3]++){
                    for (k[4]=0;k[4]<=9;k[4]++){
                        if (check()){
                            //for (int i=0;i<5;i++) printf("%d ",k[i]);
                            //printf("*\n");
                            ans++;
                        }
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
