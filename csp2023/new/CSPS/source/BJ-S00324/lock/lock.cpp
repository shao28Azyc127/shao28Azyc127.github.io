#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
int n,a[10],cnt[100005],ans=0,pow_[10];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    pow_[0]=1;
    for(int i=1;i<=6;i++){
        pow_[i]=pow_[i-1]*10;
    }
    for(int i=1;i<=n;i++){
        int k=0;
        for(int j=0;j<5;j++){
            scanf("%d",&a[j]);
            k*=10;
            k+=a[j];
        }
        for(int j=0;j<5;j++){
            int k_=k-pow_[j]*a[4-j];
            for(int l=0;l<10;l++){
                if(l==a[4-j]) continue;
                cnt[k_+l*pow_[j]]++;
                //printf("%d\n",k_+l*pow_[j]);
            }
        }
        for(int j=0;j<4;j++){
            int k_=k-pow_[j]*a[4-j]-pow_[j+1]*a[4-j-1];
            for(int l=0;l<10;l++){
                if(l==a[4-j]) continue;
                cnt[k_+l*pow_[j]+((a[4-j-1]-a[4-j]+l+10)%10)*pow_[j+1]]++;
                //printf("%d\n",k_+l*pow_[j]+((a[4-j-1]-a[4-j]+l+10)%10)*pow_[j+1]);
            }
        }
    }
    for(int i=0;i<100000;i++){
        if(cnt[i]==n){
            //printf("%d\n",i);
            ans++;
        }
    }
    printf("%d",ans);
    return 0;
}
/*
1
0 0 1 1 5
*/
