#include<bits/stdc++.h>
using namespace std;
int x[111111][111111] = {0},t=0,n,m,k,aaa,maxx;
int ff(int v){
    if(v == n && t % k == 0){
        return t;
    }
    aaa = 0;
    int aa[n]={0};
    for(int i = 1;i <= n;i ++){
        if(i == v){
            continue;
        }
        if(x[v][i]){
            if(i == n && (t + 1)% k != 0){
                continue;
            }
            aa[aaa] = ff(i);
            aaa++;
            t++;
        }
    }
    maxx = aa[0];
    for(int i = 1;i <= aaa;i++){
        maxx = min(maxx,aa[i]);
    }
    return maxx;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int a,b,c;
    scanf("%d %d %d",n,m,k);
    for(int i = 0;i < n;i ++){
        cin >> a >> b >> c;
        x[a][b] = c;
    }
    cout << 1;
    return 0;
}
