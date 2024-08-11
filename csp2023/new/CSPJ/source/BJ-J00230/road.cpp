#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int d[N], p[N];
bool cross[N];
int n, di, len, lft, ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf(" %d %d",&n,&di);
    for(int i = 1; i < n; i++){
        scanf(" %d",&d[i]);
    }
    for(int i = 1; i <= n; i++) scanf(" %d",&p[i]);
    for(int i = 1; i < n; i++){
        if(cross[i]) continue;
        len = d[i];
        for(int j = i + 1; j < n; j++){
            if(p[j] >= p[i]){
                len += d[j];
                cross[j] = true;
            }
            else break;
        }
        if(len % di == 0) ans += (len / di) * p[i];
        else{
            if((len - lft) % di == 0){
                ans += ((len - lft) / di) * p[i];
                lft = 0;
            }
            else{
                ans += ((len - lft) / di + 1) * p[i];
                lft = ((len - lft) / di + 1) * di - len;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
