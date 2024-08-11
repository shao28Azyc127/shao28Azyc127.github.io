#include<bits/stdc++.h>
using namespace std;
int n, sum = 0, ans, t = 0, nn = 0, maxn = 0;
struct apple{
    int vis = 0;
    int tt;
}a[100000010];
int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    while(nn < n){
        for(int i = 1; i <= n; i++){
            if(a[i].vis == 0){
                sum++;
            }
            if(sum == 1 && a[i].vis == 0){
                a[i].vis = 1;
                a[i].tt = t + 1;
                nn++;
            }
            if(sum == 3){
                sum = 0;
            }
        }
        t++;
        sum = 0;
    }
    for(int i = 1; i <= n; i++){
        maxn = max(maxn, a[i].tt);
    }
    cout << maxn <<" "<< a[n].tt;
    return 0;
}
