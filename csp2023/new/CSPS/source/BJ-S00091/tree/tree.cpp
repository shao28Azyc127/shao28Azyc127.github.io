#include<bits/stdc++.h>
#define ll long long
using namespace std;

template<typename T>
void read(T &a) {
    char ch;bool flag = a = 0;
    for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') flag = true;
    for(;ch>='0'&&ch<='9';a=a*10+ch-'0',ch=getchar());
    if(flag) a*=-1;
}

ll n;
ll a, b, c;
ll ans;

int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    read(n);
    for(int i=1;i<=n;i++) {
            read(a);read(b);read(c);
        ll daysneed = 0;
        ll height;
        for(height=0;height<a;daysneed++) {
            height += max(b+(daysneed+i)*c[i], 1);
        }
        ans = max(i+daysneed, ans);
    }
    printf("%lld", ans);
    return 0;
}
