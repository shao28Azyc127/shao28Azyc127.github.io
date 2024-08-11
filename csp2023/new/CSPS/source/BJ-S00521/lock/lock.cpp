#include<bits/stdc++.h>
#define MaxN 100010
using namespace std;
int locks[MaxN];
int n,tot = 1;
inline int opt(int a,int b,int c,int d,int e){
    return a*10000 + b*1000+c*100+d*10+e;
}
inline int op(int num,int i){
    return (num+i)%10;
}
void check(int a,int b,int c,int d,int e,int cnt){
    int num = opt(a,b,c,d,e);
    if(locks[num]!=cnt-1) return;
    locks[num] = cnt;
}
void solve(int a,int b,int c,int d,int e,int cnt){
    for(int i = 1;i<=9;i++){
        check(op(a,i),b,c,d,e,cnt);
        check(op(a,i),op(b,i),c,d,e,cnt);
        check(a,op(b,i),c,d,e,cnt);
        check(a,op(b,i),op(c,i),d,e,cnt);
        check(a,b,op(c,i),d,e,cnt);
        check(a,b,op(c,i),op(d,i),e,cnt);
        check(a,b,c,op(d,i),e,cnt);
        check(a,b,c,op(d,i),op(e,i),cnt);
        check(a,b,c,d,op(e,i),cnt);
    }
    return ;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin >> n;
    while(n--){
        int a,b,c,d,e;
        cin >> a >> b >>c >> d >> e;
        solve(a,b,c,d,e,tot);
        tot++;
    }
    int ans = 0;
    for(int i = 0;i<=99999;i++){
        if(locks[i]==tot-1){
            ++ans;
        }
    }
    cout << ans;
    return 0;
}

