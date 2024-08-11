#include<bits/stdc++.h>
using namespace std;
struct lockV {
    long long a[5];
};
long long n;
lockV arr[10];
long long curr[100005];
vector<lockV> toCheck;
long long hlockV(lockV a) {
    long long tmp = 0;
    for(long long i = 0; i < 5; i++) {
        tmp *= 10;
        tmp += a.a[i];
    }
    return tmp;
}
void gencyc(lockV a) {
    for(long long i = 0; i < 5; i++) {
        for(long long j = 1; j <= 9; j++) {
            lockV tmp = a;
            tmp.a[i] = (tmp.a[i]+j)%10;
            long long tmp2 = hlockV(tmp);
            curr[tmp2]++;
            if(curr[tmp2] == 1) {
                toCheck.push_back(tmp);
            }
        }
    }
    for(long long i = 0; i < 4; i++) {
        for(long long j = 1; j <= 9; j++) {
            lockV tmp = a;
            tmp.a[i] = (tmp.a[i]+j)%10;
            tmp.a[i+1] = (tmp.a[i+1]+j)%10;
            long long tmp2 = hlockV(tmp);
            curr[tmp2]++;
            if(curr[tmp2] == 1) {
                toCheck.push_back(tmp);
            }
        }
    }
}
int main () {
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%lld",&n);
    for(long long i = 0; i < n; i++) {
        for(long long j = 0; j < 5; j++) {
            scanf("%lld",&arr[i].a[j]);
        }
        gencyc(arr[i]);
    }
    long long ans = 0;
    for(long long i = 0; i < toCheck.size(); i++) {
        if(curr[hlockV(toCheck[i])] == n) {
            ans++;
        }
    }
    printf("%lld\n",ans);
    return 0;
}