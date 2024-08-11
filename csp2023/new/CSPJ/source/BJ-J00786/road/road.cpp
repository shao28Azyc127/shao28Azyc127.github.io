#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;
double d;
LL jl[100010],qzh[100010],price[100010];
struct{
    LL sy,hf;
}dp[100010];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(LL i=1;i<n;i++){
        cin>>jl[i];
    }
    for(LL i=1;i<=n;i++){
        cin>>price[i];
        dp[i].hf=0x3f3f3f3f;
    }
    dp[1].hf=0;
    qzh[1]=0;
    for(int i=2;i<=n;i++){
        qzh[i]=qzh[i-1]+jl[i-1];
    }
    for(LL i=2;i<=n;i++){
        for(LL j=1;j<i;j++){
            if(dp[i].hf>=LL(ceil(double(qzh[i]-qzh[j]-dp[j].sy)/d)*price[j]+dp[j].hf)){
                if(dp[i].sy<LL(ceil(double(qzh[i]-qzh[j]-dp[j].sy)/d)*LL(d)-(qzh[i]-qzh[j]-dp[j].sy))){
                    dp[i].sy=LL(ceil(double(qzh[i]-qzh[j]-dp[j].sy)/d)*LL(d)-(qzh[i]-qzh[j]-dp[j].sy));
                }
                dp[i].hf=LL(ceil(double(qzh[i]-qzh[j]-dp[j].sy)/d)*price[j])+dp[j].hf;
            }
        }
    }
    cout<<dp[n].hf<<"\n";
    return 0;
}