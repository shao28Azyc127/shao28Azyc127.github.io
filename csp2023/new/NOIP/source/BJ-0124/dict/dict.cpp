#include<bits/stdc++.h>
#define MaxN 3010
using namespace std;
int nmax[MaxN],nmin[MaxN];
int n,m;
bool solve(int r){
    for(int i = 1;i<=n;i++){
        if(i==r) continue;
        if(nmax[i]<=nmin[r]) return false;
    }
    return true;
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin >> n >> m;
    if(n==1){
        cout << 1;
        return 0;
    }
    memset(nmin,100,sizeof(nmin));
    for(int i =1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            char a;
            cin >> a;
            int s = a-'a';
            nmax[i] = max(nmax[i],s);
            nmin[i] = min(nmin[i],s);
        }
    }
    for(int i = 1;i<=n;i++){
        cout << solve(i);
    }
    return 0;
}
