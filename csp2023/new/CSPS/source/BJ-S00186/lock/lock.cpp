#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;

int n,cnt[N],a[6],ans;

int main() {
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    if(n==1) {
        printf("81\n");
        return 0;
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=5;j++) {
            scanf("%d",&a[j]);
        }
        int num=a[1]*10000+a[2]*1000+a[3]*100+a[4]*10+a[5];
        for(int j=1;j<=9;j++) {
            cnt[num-a[5]+(a[5]+j)%10]++;
            cnt[num-a[4]*10+(a[4]+j)%10*10]++;
            cnt[num-a[3]*100+(a[3]+j)%10*100]++;
            cnt[num-a[2]*1000+(a[2]+j)%10*1000]++;
            cnt[num-a[1]*10000+(a[1]+j)%10*10000]++;
        }
        for(int j=1;j<=9;j++) {
            cnt[num-a[5]-a[4]*10+(a[5]+j)%10+(a[4]+j)%10*10]++;
            cnt[num-a[4]*10+(a[4]+j)%10*10-a[3]*100+(a[3]+j)%10*100]++;
            cnt[num-a[3]*100+(a[3]+j)%10*100-a[2]*1000+(a[2]+j)%10*1000]++;
            cnt[num-a[2]*1000+(a[2]+j)%10*1000-a[1]*10000+(a[1]+j)%10*10000]++;
        }
    }
    for(int i=1;i<=99999;i++) {
        if(cnt[i]==n) {
            ans++;
            //cout<<i<<endl;
        }
    }
    cout<<ans<<endl;
    return 0;
}
//meow
