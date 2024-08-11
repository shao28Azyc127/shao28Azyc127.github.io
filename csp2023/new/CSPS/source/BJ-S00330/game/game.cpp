#include<bits/stdc++.h>
using namespace std;
int n,ans;
char f[2000010],l[2000010];
inline bool judge(int s,int t) {
    int cnt=0;
    for (int a=s;a<=t;a++) {
        l[cnt]=f[a];
        if (cnt && l[cnt]==l[cnt-1]) cnt--;
        else cnt++;
    }
    if (cnt) return false;
    return true;
}
int main () {
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin >>n;
    for (int a=1;a<=n;a++) cin >>f[a];
    for (int a=1;a<n;a++) {
        for (int b=a+1;b<=n;b+=2) {
            ans+=judge(a,b);
        }
    }
    cout <<ans;
    return 0;
}
