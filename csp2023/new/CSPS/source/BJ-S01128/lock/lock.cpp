#include<bits/stdc++.h>
using namespace std;

// #define LOCAL

int n,ans=0;
int a[5];

int tag[100000][8];

int gint(){
    int ret=0;
    for(int i=0;i<5;i++){
        ret+=a[i]*pow(10,i);
    }

    return ret;
}

void ad(int& x){
    x++;
    x%=10;
}

int main(){
    #ifndef LOCAL
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    #endif

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5]);
        for(int j=0;j<=4;j++){
            ad(a[j]);
            for(int k=1;k<=9;k++){
                tag[gint()][i]=1;
                ad(a[j]);
            }
        }
        for(int j=0;j<=3;j++){
            ad(a[j]);
            ad(a[j+1]);
            for(int k=1;k<=9;k++){
                tag[gint()][i]=1;
                ad(a[j]);
                ad(a[j+1]);
            }
        }
    }
    for(int i=0;i<100000;i++){
        int flg=1;
        for(int j=0;j<n;j++){
            flg&=tag[i][j];
        }
        ans+=flg;
    }
    printf("%d\n",ans);

    return 0;
}
