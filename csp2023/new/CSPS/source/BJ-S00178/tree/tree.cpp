#include <bits/stdc++.h>
using namespace std;
int n;
long long want[100001],b[100001],c[100001];
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin >>n;
    long long day=0;
    for(int i=1;i<=n;i++) cin >>want[i] >>b[i] >>c[i];
    for(int i=1;i<=n;i++){
        //long long now=0;
        long long nowd=i-1;
        while(want[i]>0){
            want[i]-=max(b[i]+nowd*c[i],1ll);
            nowd++;
           // nowd++;
        }
        //cout <<nowd <<" ";
        day=max(day,nowd);
    }
    cout <<day;
    return 0;
}
