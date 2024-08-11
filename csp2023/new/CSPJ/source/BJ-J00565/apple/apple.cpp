#include<bits/stdc++.h>
using namespace std;
long long a,cnt[1000005],a_cnt,ans;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%lld",&a);
    for(long long i=1;i<=a;i++) cnt[i]=i;
    for(long long i=1;i<=a;i++){
        if(cnt[i]==0) continue;
        long long cou=3;
        for(long long j=i;j<=a;j++){
            if(cou==3){
                if(cnt[j]==0) continue;
                cnt[j]=0;
                cou=1;
            }else if(cnt[j]!=0) cou++;
        }if(cnt[a]==0) ans++;
        else{
            a_cnt++;
            ans++;
        }
    }printf("%lld %lld",ans,a_cnt+1);
    return 0;
}
