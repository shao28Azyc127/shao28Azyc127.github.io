#include<bits/stdc++.h>
using namespace std;
int n;
double d;
long long p[100005],dis[100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    for(int i=1;i<n;i++)   cin >> dis[i];
    for(int i=1;i<=n;i++)   cin >> p[i];
    int st = 1;
    long long ans = 0;
    long long cntdis = 0;
    double oil = 0;
    while(1){
        if(st == n) break;
        int nxt = st;
        cntdis = 0;
        while(1){
            nxt ++;
            cntdis += dis[nxt-1];
            if(nxt == n || p[nxt] < p[st])    break;
        }
        ans += ceil(cntdis / d - oil) * p[st];
        oil = ceil(cntdis / d - oil) - (cntdis / d - oil);
        st = nxt;
        if(st == n) break;
    }
    cout << ans;
    return 0;
}
