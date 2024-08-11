#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
long long minn[100005];
long long a;
long long k;
long long price[100005];
long long litre[100005];
long long sum[100005];
long long up(long long a,long long b){
    if(a%b != 0){
        return a/b+1;
    }
    else{
            return a/b;}
}
int main(){
    minn[0] = 0x3f3f3f3f;
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%long longd%long longd",&a,&k);
    for(long long i = 1;i < a;i++){
        //dp[i] = 0x3f3f3f3f;
        scanf("%long longd",&litre[i]);
        sum[i] = litre[i]+sum[i-1];
    }
    for(long long i = 1;i <= a;i++){
        scanf("%long longd",&price[i]);
        minn[i] = min(minn[i-1],price[i]);
    }
    long long now = 0,ans = 0;
    for(long long i = 1;i < a;i++){
        for(long long j = i+1;j < a;j++){
            if(minn[j] < minn[i]){
                ans += up(sum[j]-sum[i]-now,k)*minn[i];
                now = up(sum[j]-sum[i]-now,k)*minn[i]-(sum[j]-sum[i]-now);
                i = j-1;
            }
        }
    }
    printf("%long longd",ans);
    return 0;
}
