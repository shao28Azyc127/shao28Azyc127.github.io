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

char a[2000010];
ll ans;
ll n;

bool check(int l, int r) {
    if((r-l+1)%2) return false;
    stack<char> s;
    for(int i=l;i<=r;i++) {
        if(s.empty()) {
            s.push(a[i]);
            continue;
        }
        if(s.top() == a[i]) s.pop();
        else s.push(a[i]);
    }
    return !s.size();
}

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    read(n);
    for(int i=1;i<=n;i++) {
        scanf("%c", &a[i]);
    }

    for(int i=2;i<=n-n%2;i+=2) {
        for(int j=1;j+i-1<=n;j++) {
            if(check(j, j+i-1)) {
                ans++;
            }
        }
    }
    printf("%lld", ans);
    return 0;
}

//ÒÔÉÏÎª¼Ä¡£45pts.
